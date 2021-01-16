#!/bin/sh

REPL_PATH=$1
echo ${REPL_PATH}
#
# install Curl - can only use the install-pkg script which is buggy
#
install-pkg libcurl4
install-pkg libcurl4-openssl-dev


# create directory for curl includes and libraries
mkdir ${REPL_PATH}/curl

mv ~/.apt/usr/*  ${REPL_PATH}/curl

# download the BRIDGES C++ client
#
wget http://bridgesuncc.github.io/sw/bridges-cxx-3.1.1-x86_64-linux-gnu.tgz  -O ~/bridges-cxx.tgz

#
# explode it in the REPL directory
#
cd ${REPL_PATH}
tar xvfz ~/bridges-cxx.tgz

#
# need to set up environment variables that need to be appended to the .bashrc
#
cat >> ~/.bashrc <<EOF

export BRIDGES_CXXFLAGS="-I${REPL_PATH}/bridges-cxx-3.1.1-x86_64-linux-gnu/include -I${REPL_PATH}/curl/include/x86_64-linux-gnu"
export BRIDGES_LDFLAGS="-L${REPL_PATH}/bridges-cxx-3.1.1-x86_64-linux-gnu/lib -L{HOME}/${REPL_PATH}/curl/lib/x86_64-linux-gnu"

export BRIDGES_CXX=clang++
export BRIDGES_CC=clang++
export BRIDGES_LD=clang++

EOF
