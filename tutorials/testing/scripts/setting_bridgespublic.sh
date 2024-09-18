#!/bin/sh

#. ./config.sh

if [ "${FORCE_BRIDGES_USERNAME}" = "" ]
then
    echo "You need to define both FORCE_BRIDGES_USERNAME and FORCE_BRIDGES_APIKEY to export in the environment in config.sh"
    echo "I suggest runnig it with non bridges_public credentials first to make sure it does what you want."
    exit 1
fi
   
if [ "${FORCE_BRIDGES_APIKEY}" = "" ]
then
    echo "You need to define both FORCE_BRIDGES_USERNAME and FORCE_BRIDGES_APIKEY to export in the environment in config.sh"
    echo "I suggest runnig it with non bridges_public credentials first to make sure it does what you want."
    exit 1
fi

BRIDGES_TESTING=$1;

if [ ! -f ${BRIDGES_TESTING}/isbridgestesting ]
then
    echo "the first parameter should be a path to bridges testing. It assume you can make and run the c++ codes in there."
    exit 1
fi

cd ${BRIDGES_TESTING}/c++/web_tutorial_mastercopy
make testing
cd ${BRIDGES_TESTING}/c++/web_tutorial_testing
make -j 8


#the assignment number follows a pattern 9XYZ, where X is the group
#number, Y is the tutorial number in the group, an Z is the assignment
#in that tutorial. This should future proof it.

FORCE_BRIDGES_ASSIGNMENT=9000 ./array1d 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=9001 ./array2d 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=9002 ./array3d 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9010 ./color_grid 9999 fakename fakeapi


FORCE_BRIDGES_ASSIGNMENT=9100 ./sllist 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9110 ./dllist 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9120 ./circ_sllist 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9130 ./circ_dllist 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9140 ./mllist 9999 fakename fakeapi


FORCE_BRIDGES_ASSIGNMENT=9200 ./tree 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9210 ./bintree 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9220 ./bst_eq 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9230 ./avl 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9240 ./kdt 9999 fakename fakeapi


FORCE_BRIDGES_ASSIGNMENT=9300 ./graph_alist 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9310 ./graph_amatrix 9999 fakename fakeapi


FORCE_BRIDGES_ASSIGNMENT=9400 ./shape_collection 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9500 ./sine_wave 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=9510 ./audio_clip_manipulation 9999 fakename fakeapi


## New tutorials (added by KRS - 1/12/21

FORCE_BRIDGES_ASSIGNMENT=10000 ./tut_array1d_p1 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10010 ./tut_array1d_p2 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10020 ./tut_array1d_p3 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=10030 ./tut_sllist_p1 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10040 ./tut_sllist_p2 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10050 ./tut_sllist_p3 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=10060 ./tut_dllist_p1 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10070 ./tut_dllist_p2 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10080 ./tut_dllist_p3 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=10090 ./tut_bst_p1 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10100 ./tut_bst_p2 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10110 ./tut_bst_p3 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=10120 ./tut_col_grid_p1 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10130 ./tut_col_grid_p2 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10140 ./tut_col_grid_p3 9999 fakename fakeapi

FORCE_BRIDGES_ASSIGNMENT=10150 ./tut_graph_p1 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10160 ./tut_graph_p2 9999 fakename fakeapi
FORCE_BRIDGES_ASSIGNMENT=10170 ./tut_graph_p3 9999 fakename fakeapi

## tutorials added : 7/19/22

FORCE_BRIDGES_ASSIGNMENT=10180 ./tut_linechart 9999 fakename fakeapi

## tutorials added : 7919/24

FORCE_BRIDGES_ASSIGNMENT=10190 ./barchart 9999 fakename fakeapi


## games don't produce useful visualization


##snippets don't produce visualization

##is there a need of something for visualize?
