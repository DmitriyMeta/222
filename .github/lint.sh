#!/usr/bin/env bash
ERRORS=0
function countError {
    echo "Проверка завершилась с ошибкой."
    (( ERRORS++ ))
}
trap countError ERR

echo "# cppcheck"
cppcheck --enable=warning,performance --error-exitcode=2 . && echo "OK" || false

echo "# clang-tidy"
# "--" should be last clang-tidy argument,
# so we concatenate output of "find" with "--"
find . -maxdepth 1 -name "*.c*" | xargs -r $(dirname $0)/clang-tidy.sh  && echo "OK" || false

echo "# clang-format (форматирование кода)"
find . -maxdepth 1 -name "*.c*" | xargs -r $(dirname $0)/clang-format.sh --dry-run -Werror && echo "OK" || false

echo "# Предупреждения GCC"
make werror && echo "OK" || false

exit $ERRORS
