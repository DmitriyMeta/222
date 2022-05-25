#!/usr/bin/env bash
set -e
COVERAGE=$(genhtml coverage.info --output-directory coverage | tee /dev/fd/2 | grep -Po 'lines.*?%' | egrep "[0-9]+" -o | head -n 1)
[ $COVERAGE -ge 90 ]
