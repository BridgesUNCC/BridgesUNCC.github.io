
# Fill in the path to your Repl folder root
# default is the current directory; if you are in the repl folder, then no changes
# are needed for this path

REPL_PATH=./

#
# the final executable - name of class containing main()
# modify to reflect your application
#
EXE=java_test

# put in the source file names
# modify to reflect your application
# multiple source files are separated by spaces

SRCS = java_test.java

OBJS = $(SRCS:.java=.class)


export CLASSPATH=${REPL_PATH}/lib/bridges-java.jar:.


all: 
	javac  ${SRCS}
	java   $(EXE)
