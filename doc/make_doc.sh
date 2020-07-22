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

##Figuring out version numbers

CXX_VERSION_NUMBER=unknown

cd ${BRIDGESCXX}
CXX_VERSION_NUMBER=`git describe --tags`
cd -

JAVA_VERSION_NUMBER=unknown

cd ${BRIDGESJAVA}
JAVA_VERSION_NUMBER=`git describe --tags`
cd -

PYTHON_VERSION_NUMBER=unknown

cd ${BRIDGESPYTHON}
PYTHON_VERSION_NUMBER=`git describe --tags`
cd -

##Generating C++ doc

(
    cat bridges_doxygen_cxx.cfg;
    cat <<EOF
INPUT=${BRIDGESCXX}/src ${BRIDGESCXX}/src/data_src
PROJECT_NUMBER = ${CXX_VERSION_NUMBER}	
OUTPUT_DIRECTORY = ./cxx-api/${CXX_VERSION_NUMBER}/
EOF
) | doxygen -

##Generating JAVA doc

(
    cat bridges_doxygen_java.cfg;
    cat <<EOF
INPUT=${BRIDGESJAVA}/src/main/java/bridges/base ${BRIDGESJAVA}/src/main/java/bridges/benchmark ${BRIDGESJAVA}/src/main/java/bridges/connect ${BRIDGESJAVA}/src/main/java/bridges/data_src_dependent ${BRIDGESJAVA}/src/main/java/bridges/validation ${BRIDGESJAVA}/src/main/java/bridges/games
PROJECT_NUMBER = ${JAVA_VERSION_NUMBER}	
OUTPUT_DIRECTORY = ./java-api/${JAVA_VERSION_NUMBER}/
EOF
) | doxygen -

##Generating Python doc

(
    cat bridges_doxygen_python.cfg;
    cat<<EOF
INPUT=${BRIDGESPYTHON}/bridges ${BRIDGESPYTHON}/bridges/data_src_dependent
PROJECT_NUMBER = ${PYTHON_VERSION_NUMBER}	
OUTPUT_DIRECTORY = ./python-api/${PYTHON_VERSION_NUMBER}/
EOF
) | doxygen -


./generate_old_doc.sh > old_docs.html

echo
echo ==================================
echo
echo Note that while documentations were created/modified, the content of the git repository has not.
echo If you have created new documentation, you still need to git-add them.
echo If you have changed existing documentation, you still need to git-add them or git commit -a.
echo If the current documentation has changed, you still need to update the symlinks cxx-api/current, java-api/current, and python-api/current
echo
echo ==================================
echo
