#!/bin/sh

. ./config.sh

if [ "${FORCE_BRIDGES_USERNAME}" = "" ]
then
    echo "You need to define both FORCE_BRIDGES_USERNAME and FORCE_BRIDGES_APIKEY to export in the environment in config.sh"
fi
   
if [ "${FORCE_BRIDGES_APIKEY}" = "" ]
then
    echo "You need to define both FORCE_BRIDGES_USERNAME and FORCE_BRIDGES_APIKEY to export in the environment in config.sh"
fi
