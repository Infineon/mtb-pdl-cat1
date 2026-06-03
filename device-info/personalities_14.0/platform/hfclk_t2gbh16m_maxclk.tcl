# (c) 2026, Infineon Technologies AG or an affiliate of
# Infineon Technologies AG.
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# From https://wiki.tcl-lang.org/page/constants
proc const {name value} {
    uplevel 1 [list set $name $value]
    uplevel 1 [list trace var $name w {error constant} ]
}


set channelName stdout

if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

# Main function
proc main {} {
    const NUM_OF_ARG 7

    if {$::argc != $NUM_OF_ARG} {
        puts stdout "$::argv"
        error "Script requires $NUM_OF_ARG input parameters, got $::argc"
        return 0
    }


    set clockInst [lindex $::argv 0]
    set clockSrc [lindex $::argv 1]
    set clockSrcSourcedByFll [lindex $::argv 2]
    set clockSrcSourcedByImo [lindex $::argv 3]
    set pllIsBypassed [lindex $::argv 4]
    set clockSrcFracEn [lindex $::argv 5]
    set clockSrcSscgEn [lindex $::argv 6]

    return [lookup_max_freq $clockInst $clockSrc $clockSrcSourcedByFll $clockSrcSourcedByImo $pllIsBypassed $clockSrcFracEn $clockSrcSscgEn]
}

proc lookup_max_freq {clockInst clockSrc clockSrcSourcedByFll clockSrcSourcedByImo pllIsBypassed clockSrcFracEn clockSrcSscgEn} {
    # Max clock values, per root clock.
    # The first row in each sub-table is for the first PLL source, the second row is for the second PLL source.
    #   - So the second row only applies to the HfClks that have multiple PLL sources with "guaranteed mappings".
    # Derived from Table 48 (pg 159 attow) in the T2G-B-H-16M/CYT6BJ Datasheet.
    #   [0]     [1]     [2]         [3]          [4]            [5]         [6]             [7]          [8]
    #   FLL+ECO FLL+IMO PLL+ECO+Int PLL+ECO+SSCG PLL+ECO+Frac   PLL+IMO+Int PLL+IMO+SSCG    PLL+IMO+Frac DefaultMax
    const HfClkTable {
        {100   98      200         0            0              194         0               0            200}
        {100   98      320         310          316            313         306             310          320}
        {100   98      100         0            0              100         0               0            100}
        {100   98      100         0            0              100         0               0            100}
        {100   98      125         122          123            122         119             121          125}
        {100   98      196.608     193          196.608        193         189             191          196.608}
        {100   98      200         0            0              194         0               0            200}
        {0     0       0           0            0              0           0               0            0  }
    }

    # Get the row with maximum frequencies for the clockInst passed in from the personality.
    set hfclk_row [lindex $HfClkTable $clockInst]

    # Special case for clockInst 7 (ILO sourced, CSV Dedicated on T2G-B-H-16M/CYT6BJ, <= 8MHz)
    if {$clockInst == 7} {
        set retval 8000000
        puts $::channelName "$retval"
        return $retval
    }

    # Create the index to the correct maximum frequency in the table.
    if {$clockSrcSourcedByFll} {
        if ($clockSrcSourcedByImo) {
            set idx 1
        } else {
            set idx 0
        }
    } else {
        # FLL maxes are the first two columns in the table.  PLLs start at index 2.
        set idx 2
        # If the clock source is sourced by IMO, then move over three more columns.
        if ($clockSrcSourcedByImo) {
            set idx [expr {$idx + 3}]
        }

        # If the clock source is Integer, then the idx is already at the right column.
        # If SSCG or Fractional are enabled, then we need to adjust the index.
        if ($clockSrcSscgEn) {
            set idx [expr {$idx + 1}]
        } elseif ($clockSrcFracEn) {
            set idx [expr {$idx + 2}]
        }
    }

    # Get the maximum frequency from the table and convert it to Hz.
    set retval [lindex $hfclk_row $idx]
    set retval [expr {int(round(double($retval) * 1000000))}]

    puts $::channelName "$retval"
    return $retval
}

main