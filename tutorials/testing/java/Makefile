
#
#Platform specific variables
#
CC = javac
HOME = /Users/krs

#
#

ASTYLE = astyle
ASTYLE_PARAMS = -A2 -T4 -xn -xc -xV -C -S -N -xU  -Y -p -xg -H -y -xb

TARGET =  all


SRCS = arr1d.java arr2d.java arr3d.java sllist.java dllist.java csllist.java \
		cdllist.java  mllist.java tree.java bintree.java bst.java avl.java \
		graph_al.java graph_am.java 


EXECUTABLES = $(SRCS:.cpp=)

all : 
	javac $(SRCS)

run:
	java arr1d;
	java arr2d;
	java arr3d;
	java sllist;
	java dllist;
	java csllist;
	java cdllist;
	java mllist;
	java tree;
	java bintree;
	java bst;
	java avl;
	java graph_al;
	java graph_am;

style:  
	$(ASTYLE) $(ASTYLE_PARAMS)  $(SRCS) 


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
