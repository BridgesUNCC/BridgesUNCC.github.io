#!/bin/sh

prefix_with() {
    local prefix=$1
    shift
    for arg
    do
	echo ${prefix}${arg}
    done
}

prepare_assignment_scaffold() {
    local targetfile=$1
    local srcdir=$2

    cd ${srcdir}
    FILES=$(git ls-files)
    cd -
    zip -j -r ${targetfile} $(prefix_with ${srcdir}/ ${FILES})
    
}
