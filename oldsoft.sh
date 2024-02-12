#!/bin/bash

PYTHONVERSIONS=sw/bridges-python-*.zip

echo "<h2>Python</h2>"
for f in $PYTHONVERSIONS;
do
    #echo $f
    echo "<a href='${f}'>${f}</a><br>"
done


CXXVERSIONS="sw/bridges-cxx-*.zip sw/bridges-cxx-*.tgz"

echo "<h2>C++</h2>"
for f in $CXXVERSIONS;
do
    #echo $f
    echo "<a href='${f}'>${f}</a><br>"
done


JAVAVERSIONS=sw/bridges-*.jar

echo "<h2>Java</h2>"
for f in $JAVAVERSIONS;
do
    #echo $f
    echo "<a href='${f}'>${f}</a><br>"
done
