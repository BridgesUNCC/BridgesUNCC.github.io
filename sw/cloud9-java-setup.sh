#!/bin/sh

wget http://bridgesuncc.github.io/sw/bridges-java-3.1.0.jar -O ~/bridges-java.jar

cat >> ~/.bashrc <<EOF

export CLASSPATH=~/bridges-java.jar:.

EOF
