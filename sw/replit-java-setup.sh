#!/bin/sh

#
# the command line argument should reflect the path to repl folder root
#
REPL_PATH=$1

# create a jar director for placing bridges jar file
mkdir ${REPL_PATH}/lib

# download the BRIDGES Java client
#
wget http://bridgesuncc.github.io/sw/bridges-java-3.1.0.jar  -O ${REPL_PATH}/lib/bridges-java.jar


#
#set CLASSPATH
#
export CLASSPATH=${REPL_PATH}/lib/bridges-java.jar:.

