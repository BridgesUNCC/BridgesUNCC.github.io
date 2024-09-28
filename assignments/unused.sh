#!/bin/sh


BRIDGESASSIGNMENT=$1

#if ${BRIDGESASSIGNMENT} does not point to bridges assignment repo, bail.
if ! [ -e ${BRIDGESASSIGNMENT}/isbridgesassignment ];
then
    echo can not find bridges assignment repository. pass it as parameter 1 to this script.
    exit 1
fi

grep addassign data.sh | cut -d \" -f 2  | sort  | uniq > /tmp/a

ls -1 ${BRIDGESASSIGNMENT}/assignmentdb | grep -- - | sort  > /tmp/b

comm -13  /tmp/a /tmp/b | sort -n

