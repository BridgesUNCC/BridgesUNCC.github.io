#!/bin/sh

#
# the command line argument should reflect the path to repl folder root
#
REPL_PATH=$1

# create a jar director for placing bridges jar file
mkdir ${REPL_PATH}/lib

# download the BRIDGES Java client
#
wget http://bridgesuncc.github.io/sw/bridges-java-3.1.2.jar  -O ${REPL_PATH}/lib/bridges-java.jar

# get an example makefile for repl
wget http://bridgesuncc.github.io/sw/replit-example-Makefile-Java -O ${REPL_PATH}/Makefile

#
#set CLASSPATH
#
export CLASSPATH=${REPL_PATH}/lib/bridges-java.jar:.

