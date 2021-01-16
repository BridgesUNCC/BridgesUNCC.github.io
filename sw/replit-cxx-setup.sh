#!/bin/sh

#
# install Curl - can only use the install-pkg script which is buggy
#
install-pkg libcurl4
install-pkg libcurl4-openssl-dev

#
# download the BRIDGES C++ client
#
wget http://bridgesuncc.github.io/sw/bridges-cxx-3.1.1-x86_64-linux-gnu.tgz  -O ~/bridges-cxx.tgz

#
# explode it in the home directory
#
cd ${HOME}
tar xvfz bridges-cxx.tgz

#
# need to set up environment variables that need to be appended to the .bashrc
#
cat >> ~/.bashrc <<EOF

export BRIDGES_CXXFLAGS="-I${HOME}/bridges-cxx-3.1.1-x86_64-linux-gnu/include -I${HOME}/.apt/usr/include/x86_64-linux-gnu"
export BRIDGES_LDFLAGS="-L${HOME}/bridges-cxx-3.1.1-x86_64-linux-gnu/lib -L{HOME}/.apt/usr/lib/x86_64-linux-gnu"

export BRIDGES_CXX=clang++
export BRIDGES_CC=clang++
export BRIDGES_LD=clang++

EOF

