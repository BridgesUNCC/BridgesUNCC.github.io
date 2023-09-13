SRCS = mnt_path.cpp
EXE=MountainPath

# Everything below that should not have to change ever.


CXX=g++
LD=g++
CC=g++

TARGET =  all 

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -g  -std=c++14 $(BRIDGES_CXXFLAGS)

LDFLAGS = -g $(BRIDGES_LDFLAGS) -pthread
LIBS =  -lcurl -l bridges 

$(EXE): $(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(LDFLAGS) $(LIBS)

.SUFFIXES: .cpp

.cpp.o:  
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(EXE)

clean:
	-rm $(OBJS)
	-rm $(EXE)

