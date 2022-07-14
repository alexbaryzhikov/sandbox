#!/bin/bash

if [ $(grep -Ec '(vmx|svm)' /proc/cpuinfo) -eq 0 ]; then
    echo "FAIL"
    exit 2
else
    echo "OK"
fi
