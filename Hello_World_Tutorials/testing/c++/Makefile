CC = clang++

TARGET =  graph_alist 

SRCS = array.cpp array2d.cpp array3d.cpp sllist.cpp dllist.cpp circ_sllist.cpp \
		circ_dllist.cpp  tree.cpp bintree.cpp bst.cpp avl.cpp \
		graph_alist.cpp graph_amatrix.cpp 

OBJS = $(SRCS:.cpp=.o)

EXE = $(SRCS:.cpp=)

INCLUDES = Element.h SLelement.h DLelement.h BSTElement.h TreeElement.h\
			ADTVisualizer.h ElementVisualizer.h	LinkVisualizer.h \
			GraphList.h Edge.h	\
			Bridges.h Connector.h Validation.h

BRIDGES_INCL = /Users/kalpathi/gr/bridges/client/cxx/v23/src
IFLAGS = -I$(BRIDGES_INCL)  -I/usr/local/curl750/include
CPPFLAGS = -c -g $(IFLAGS) -std=c++11 -stdlib=libc++

LDFLAGS =  -L/usr/local/curl750/lib
LIBS =  -lcurl

.SUFFIXES: .cpp

.cpp.o:  
	$(CC) $(CPPFLAGS)  $< -o $@

TARGET : graph_alist

all : tests

run:
		array;
		array2d;
		array3d;
		sllist;
		dllist;
		circ_sllist;
		circ_dllist;
		tree;
		bintree;
		bst;
		avl;
		graph_alist;
		graph_amatrix;

tests : array array2d array3d sllist dllist circ_sllist circ_dllist tree  \
			bintree bst avl graph_alist graph_amatrix \
			imdbll bst_eq bn

imdbll: 
	cd ../CourseProjects/LinkedList_IMDB; make;

bst_eq : 
	cd ../with_data_src/bst_eq; make;

bn : ../CourseProjects/Graph_Bacon_Number/bn.o
	cd ../CourseProjects/Graph_Bacon_Number; make;

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
	rm $(OBJS)  $(EXE)

depend: $(SRCS)
	gcc -MD  $(IFLAGS) $(SRCS)

backup:
	tar cvfz bridges_cxx.tgz  src docs Makefile 
	cp bridges_cxx.tgz ~/Dropbox/.


# DO NOT DELETE

