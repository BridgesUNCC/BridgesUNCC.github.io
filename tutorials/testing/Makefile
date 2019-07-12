
CC = clang++

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all


SRCS = array.cpp array2d.cpp array3d.cpp sllist.cpp dllist.cpp circ_sllist.cpp \
		circ_dllist.cpp  mllist.cpp tree.cpp bintree.cpp bst.cpp avl.cpp \
		graph_alist.cpp graph_amatrix.cpp 


OBJS = $(SRCS:.cpp=.o)

EXECUTABLES = $(SRCS:.cpp=)

INCLUDES = 	DataStructure.h Array.h Element.h SLelement.h DLelement.h \
			CircSLelement.h CircDLelement.h MLelement.h \
			TreeElement.h BTElement.h BSTElement.h AVLTreeElement.h \
			GraphAdjList.h GraphAdjMatrix.h \
			ElementVisualizer.h	LinkVisualizer.h Color.h Edge.h base64.h\
			Bridges.h Connector.h \
			data_src/ActorMovieIMDB.h \
			data_src/EarthquakeUSGS.h \
			data_src/Book.h \
			data_src/Game.h \
			data_src/CancerIncidence.h \
			data_src/GutenbergBook.h \
			data_src/Shakespeare.h \
			data_src/Song.h

STYLE_INCLUDES = BST.h StudentInfo.h

# Incude and Library paths

BRIDGES_INCL = /Users/kalpathi/gr/bridges/client/cxx/bridges17/src
CURL_LIB_PATH = /usr/local/curl758/lib


# Include and library flags

IFLAGS = -I$(BRIDGES_INCL)  -I/usr/local/curl758/include  \
					-I/usr/local/rapidjson/include
LDFLAGS =  -L$(CURL_LIB_PATH)
CPPFLAGS = -c -g $(IFLAGS) -std=c++11 -stdlib=libc++

# Libraries

LIBS =  -lcurl

.SUFFIXES: .cpp

.cpp.o:  
	$(CC) $(CPPFLAGS)  $< -o $@

all : $(EXECUTABLES)

run:
	array;
	array2d;
	array3d;
	sllist;
	dllist;
	circ_sllist;
	circ_dllist;
	mllist;
	tree;
	bintree;
	bst;
	avl;
	graph_alist;
	graph_amatrix;

style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) $(STYLE_INCLUDES)


to_html:
	/bin/sh ./to_html_creds.sh

to_srcs:
	/bin/sh ./to_srcs.sh
	
	
	

array: array.o
	$(CC) -g -o array array.o $(LDFLAGS) $(LIBS)

array2d: array2d.o
	$(CC) -g -o array2d array2d.o $(LDFLAGS) $(LIBS)

array3d: array3d.o
	$(CC) -g -o array3d array3d.o $(LDFLAGS) $(LIBS)

sllist: sllist.o
	$(CC) -g -o sllist sllist.o $(LDFLAGS) $(LIBS)

mllist: mllist.o
	$(CC) -g -o mllist mllist.o $(LDFLAGS) $(LIBS)

dllist: dllist.o
	$(CC) -g -o dllist dllist.o $(LDFLAGS) $(LIBS)

bst: bst.o
	$(CC) -g -o bst bst.o $(LDFLAGS) $(LIBS)

bst2: bst2.o
	$(CC) -g -o bst2 bst2.o $(LDFLAGS) $(LIBS)

avl: avl.o
	$(CC) -g -o avl avl.o $(LDFLAGS) $(LIBS)

bintree: bintree.o
	$(CC) -g -o bintree bintree.o $(LDFLAGS) $(LIBS)

tree: tree.o
	$(CC) -g -o tree tree.o $(LDFLAGS) $(LIBS)

graph_alist: graph_alist.o
	$(CC) -g -o graph_alist graph_alist.o $(LDFLAGS) $(LIBS)

circ_sllist: circ_sllist.o
	$(CC) -g -o circ_sllist circ_sllist.o $(LDFLAGS) $(LIBS)

circ_dllist: circ_dllist.o
	$(CC) -g -o circ_dllist circ_dllist.o $(LDFLAGS) $(LIBS)

graph_amatrix: graph_amatrix.o
	$(CC) -g -o graph_amatrix graph_amatrix.o $(LDFLAGS) $(LIBS)


clean:
	rm $(OBJS)  $(EXECUTABLES)

depend: $(SRCS)
	gcc -MD  $(IFLAGS) $(SRCS)

backup:
	tar cvfz bridges_cxx.tgz  src docs Makefile 
	cp bridges_cxx.tgz ~/Dropbox/.


# DO NOT DELETE
