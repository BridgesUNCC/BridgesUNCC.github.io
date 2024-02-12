#!/bin/sh

wget http://bridgesuncc.github.io/sw/bridges-java-LATEST.jar -O ~/bridges-java.jar

cat >> ~/.bashrc <<EOF

export CLASSPATH=~/bridges-java.jar:.

EOF
