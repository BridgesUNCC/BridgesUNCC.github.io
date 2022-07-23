#!/bin/sh


BRIDGESWEBSITE=$1

#if ${BRIDGESWEBSITE} does not point to bridges assignment repo, bail.
if ! [ -e ${BRIDGESWEBSITE}/isbridgeswebsite ];
then
    echo can not find bridges website repository. pass it as parameter 1 to this script.
    exit 1
fi

DEST=${BRIDGESWEBSITE}/workshops/2022/BRIDGES-Summer-22-07/

cp -r * ${DEST}

cd ${DEST}
git add *
git commit -am "updating website"

echo ===========================================================================
echo A commit has been created on the website repostiory. But it has not been pushed.
echo ===========================================================================

