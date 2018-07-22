
#
#Platform specific variables
#
CC = clang++
HOME = /Users/krs
BRIDGES_INCL = $(HOME)/gr/bridges/bridges17/cxx/src
CURL_INCL = /usr/local/curl760/include
CURL_LIB_PATH = /usr/local/curl760/lib
CURL_LIB = curl
RAPID_JSON_INCL = /usr/local/rapidjson/include

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all


SRCS = array1d.py sllist.py dllist.py circ_sllist.py circ_dllist.py	\
		mllist.py tree.py bintree.py bst.py	avl.py	graph_alist.py \
		graph_amatrix.py StudentInfo.py color_grid.py


all : $(SRCS)

run:
	python array1d.py;
	python array2d.py;
	python array3d.py;
	python sllist.py;
	python dllist.py;
	python circ_sllist.py;
	python circ_dllist.py;
	python mllist.py;
	python tree.py;
	python bintree.py;
	python bst.py;
	python avl.py;
	python graph_alist.py;
	python graph_amatrix.py;
	python color_grid.py;


to_html:
	/bin/sh ./to_html_creds.sh

to_srcs:
	/bin/sh ./to_krs.sh

to_site:
	/bin/sh ./to_site.sh
	zip bridges-python-1.0.zip 
	
	
	

backup:
	tar cvfz bridges_python.tgz  src docs Makefile 
	cp bridges_cxx.tgz ~/Dropbox/.


# DO NOT DELETE
