#!/bin/bash

# Check if the script is run as root
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root" 
   exit 1
fi

# Check if a parameter is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <new_value>"
    exit 1
fi

if [[ $1 == "--help" ]]; then
    echo "Usage: $0 <new_value>"
    echo "available frequencies(Hz): $(cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies)"
    exit 1
fi

new_value="$1"

# Iterate through each CPU core and update scaling_max_freq
for cpu_core in /sys/devices/system/cpu/cpu*/cpufreq/scaling_max_freq; do
    echo "$new_value" > "$cpu_core"
done

# Iterate through each CPU core and update scaling_max_freq
for cpu_core in /sys/devices/system/cpu/cpu*/cpufreq/scaling_min_freq; do
    echo "$new_value" > "$cpu_core"
done

echo "Scaling max frequency updated to $new_value for all CPU cores."

