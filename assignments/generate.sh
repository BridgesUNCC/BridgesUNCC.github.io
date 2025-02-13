#!/bin/sh

. ./util.sh

REPORT=""

ASSIGNDIR=data/
BRIDGESASSIGNMENT=$1
HTMLOUTPUT=../newassignments.html

check_for_context

reset_context



writeheader

. ./data.sh


writefooter

git add ${HTMLOUTPUT}
git add ${ASSIGNDIR}
git commit -am "updating assignments"


echo ================================
echo              REPORT
echo ================================

echo ${REPORT}

echo ================================

echo Note that the new assignment data has been commited to git but not pushed
