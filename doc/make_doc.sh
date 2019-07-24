#!/bin/sh

BRIDGESCXX=$1
BRIDGESJAVA=$2
BRIDGESPYTHON=$3


#if ${BRIDGESCXX} does not point to bridges assignment repo, bail.
if ! [ -e ${BRIDGESCXX}/isbridgescxx ];
then
    echo can not find bridges c++ repository. pass it as parameter 1 to this script.
    exit 1
fi

#if ${BRIDGESJAVA} does not point to bridges assignment repo, bail.
if ! [ -e ${BRIDGESJAVA}/isbridgesjava ];
then
    echo can not find bridges java repository. pass it as parameter 2 to this script.
    exit 1
fi

#if ${BRIDGESPYTHON} does not point to bridges assignment repo, bail.
if ! [ -e ${BRIDGESPYTHON}/isbridgespython ];
then
    echo can not find bridges python repository. pass it as parameter 3 to this script.
    exit 1
fi

( cat bridges_doxygen_cxx.cfg; echo "INPUT=${BRIDGESCXX}/src ${BRIDGESCXX}/src/data_src" ) | doxygen -

( cat bridges_doxygen_java.cfg; echo "INPUT=${BRIDGESJAVA}/src/main/java/bridges/base ${BRIDGESJAVA}/src/main/java/bridges/connect ${BRIDGESJAVA}/src/main/java/bridges/data_src_dependent ${BRIDGESJAVA}/src/main/java/bridges/validation ${BRIDGESJAVA}/src/main/java/bridges/games" ) | doxygen -

( cat bridges_doxygen_python.cfg; echo "INPUT=${BRIDGESPYTHON}/Bridges" ) | doxygen -
