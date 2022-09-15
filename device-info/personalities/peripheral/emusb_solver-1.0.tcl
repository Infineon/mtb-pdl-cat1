# Copyright 2022 Cypress Semiconductor Corporation
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

# Constant
const REQ_PERI_CLOCK_ACCURACY 0.0025
const EXPECTED_FREQ 100000

# Name of returned parameters
const UPPER_DIV "upperDiv"
const LOWER_DIV "lowerDiv"
const RESULT "result"

const LIST_UPPER_INDEX 0
const LIST_LOWER_INDEX 1
const LIST_RESULT_INDEX 2

# Find the frequency range
proc find_upper_lower_limit {} {
    set upper_limit [expr {$::EXPECTED_FREQ * (1 + $::REQ_PERI_CLOCK_ACCURACY)}]
    set lower_limit [expr {$::EXPECTED_FREQ * (1 - $::REQ_PERI_CLOCK_ACCURACY)}]
    set result_lst [list $upper_limit $lower_limit]

    return $result_lst
}

# Find range of divider values
proc find_div_value {peri_clock_freq peri_clock_accuracy upper_limit lower_limit} {
    set upper_div 0
    set lower_div 0
    set start_upper_div 0
    set start_lower_div 0

    # Find the best value
    set temp_div [expr {$peri_clock_freq / $::EXPECTED_FREQ}]
    set temp_div_upper $temp_div
    set temp_div_lower $temp_div

    set temp_div_upper [expr {ceil($temp_div_upper)}]

    # Find upper divider value
    while {1} {
        set find_real_freq [expr {$peri_clock_freq / $temp_div_upper}]
        set find_real_upper_limit [expr {$find_real_freq * (1 + $peri_clock_accuracy)}]
        set find_real_lower_limit [expr {$find_real_freq * (1 - $peri_clock_accuracy)}]

        if {$find_real_upper_limit > $upper_limit || $find_real_lower_limit < $lower_limit} {
            break
        } else {
            set temp_div_upper [expr {$temp_div_upper + 1}]
            set upper_div $temp_div_upper

            if {$start_upper_div == 0} {
                set start_upper_div $temp_div_upper
            }
        }
    }

    # Find lower divider value
    while {1} {
        set temp_div_lower [expr {floor($temp_div_lower)}]
        set find_real_freq [expr {$peri_clock_freq / $temp_div_lower}]
        set find_real_upper_limit [expr {$find_real_freq * (1 + $peri_clock_accuracy)}]
        set find_real_lower_limit [expr {$find_real_freq * (1 - $peri_clock_accuracy)}]

        if {$find_real_upper_limit > $upper_limit || $find_real_lower_limit < $lower_limit} {
            break
        } else {
            set temp_div_lower [expr {$temp_div_lower - 1}]
            set lower_div $temp_div_lower

            if {$start_lower_div == 0} {
                set start_lower_div $temp_div_lower
            }
        }
    }

    set div_list [list $upper_div $lower_div $start_upper_div $start_lower_div]

    return $div_list
}

# Result constant
const THE_DIV_VALUE_IS_FOUND 0
const THE_DIV_VALUE_IS_NOT_FOUND 1
const RESULT_BAD_ACCURACY 2

proc check_valid_value {upper_div lower_div start_upper_div start_lower_div} {
    set div_list {0 0 0}

    set result $::THE_DIV_VALUE_IS_NOT_FOUND

    if {$upper_div == 0 && $lower_div == 0} {
        set result $::THE_DIV_VALUE_IS_NOT_FOUND
    } elseif {$upper_div == 0} {
        set result $::THE_DIV_VALUE_IS_FOUND
        set div_list [lreplace $div_list $::LIST_UPPER_INDEX $::LIST_UPPER_INDEX $start_lower_div]
    } elseif {$lower_div == 0} {
        set result $::THE_DIV_VALUE_IS_FOUND
        set div_list [lreplace $div_list $::LIST_LOWER_INDEX $::LIST_LOWER_INDEX $start_upper_div]
    } else {
        set result $::THE_DIV_VALUE_IS_FOUND
        set div_list [lreplace $div_list $::LIST_UPPER_INDEX $::LIST_UPPER_INDEX $upper_div]
        set div_list [lreplace $div_list $::LIST_LOWER_INDEX $::LIST_LOWER_INDEX $lower_div]
    }

    set div_list [lreplace $div_list $::LIST_RESULT_INDEX $::LIST_RESULT_INDEX $result]

    return $div_list
}

# Send data to personality
proc output_results {upper_div lower_div result} {
    puts $::channelName "param:$::UPPER_DIV=$upper_div"
    puts $::channelName "param:$::LOWER_DIV=$lower_div"
    puts $::channelName "param:$::RESULT=$result"
}

# The number of input parameters
const NUM_OF_ARG 2

# Main function
proc main {} {
    if {$::argc != $::NUM_OF_ARG} {
        error "Script requires two input parameters"
        return 0
    }

    set peri_clock_freq [lindex $::argv 0]
    set peri_clock_accuracy [lindex $::argv 1]

    # Set default statuses
    set upper_div 1
    set lower_div 1
    set result $::THE_DIV_VALUE_IS_NOT_FOUND

    # Check accuracy
    if {$peri_clock_accuracy > $::REQ_PERI_CLOCK_ACCURACY} {
        set result $::RESULT_BAD_ACCURACY
    } else {
        # Find upper and lower limit
        set upper_lower_limit {}
        lappend upper_lower_limit [find_upper_lower_limit]

        # Find range of divider values
        set div_value {}
        lappend div_value [find_div_value $peri_clock_freq $peri_clock_accuracy [lindex $upper_lower_limit 0 $::LIST_UPPER_INDEX] [lindex $upper_lower_limit 0 $::LIST_LOWER_INDEX]]

        # Check calculation of divider value
        set final_div_value {}
        lappend final_div_value [check_valid_value [lindex $div_value 0 $::LIST_UPPER_INDEX] [lindex $div_value 0 $::LIST_LOWER_INDEX] [lindex $div_value 0 2] [lindex $div_value 0 3]]

        if {[lindex $final_div_value 0 $::LIST_RESULT_INDEX] != $::THE_DIV_VALUE_IS_NOT_FOUND} {
            set upper_div [lindex $final_div_value 0 $::LIST_UPPER_INDEX]
            set lower_div [lindex $final_div_value 0  $::LIST_LOWER_INDEX]
        }

        set result [lindex $final_div_value 0 $::LIST_RESULT_INDEX]
    }

    output_results $upper_div $lower_div $result
}


# Select output methods
set channelName stdout
if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

# Start calculation
main
