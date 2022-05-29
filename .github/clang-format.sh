#!/usr/bin/env bash
clang-format --style="{BasedOnStyle: llvm, IndentWidth: 4, AlignTrailingComments: false, BreakBeforeBraces: Linux, AllowShortFunctionsOnASingleLine: Inline}" "$@"
