#!/usr/bin/env bash
CONFIG='
CheckOptions:
    - { key: readability-magic-numbers.IgnoredFloatingPointValues,
        value: "1.0;2.0;3.0;4.0;5.0;6.0;8.0;9.0;10.0;12.0;16.0;24.0;100.0;0.5;0.25;0.125;0.1;0.01" }
'
clang-tidy --checks=-*,bugprone-*,performance-*,readability-*,misc-* --warnings-as-errors=* --config="$CONFIG" "$@" --
