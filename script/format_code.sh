#!/bin/sh
RUNNING_PATH=${PWD}
RELATED_PATH=${0%/*}
cd "${RUNNING_PATH}"
cd "${RELATED_PATH}"
cd ..

find . -iname '*.[c|h]' |xargs -I {} clang-format -i '{}'
