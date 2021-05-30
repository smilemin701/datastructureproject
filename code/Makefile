EXENAME = project
OBJS = main.o adjacency_list.o dijkstra.o centrality.o BFS_path.o PNG.o HSLAPixel.o lodepng.o Image.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic

LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm


all : $(EXENAME)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main: output_msg main.o adjacency_list.o dijkstra.o centrality.o BFS_path.o PNG.o HSLAPixel.o lodepng.o Image.o
	$(LD) main.o adjacency_list.o dijkstra.o centrality.o BFS_path.o PNG.o HSLAPixel.o lodepng.o Image.o $(LDFLAGS) -o main

main.o : main.cpp Graph/adjacency_list.h Algorithms/dijkstra.h cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h Image.h
	$(CXX) $(CXXFLAGS) main.cpp

adjacency_list.o : Graph/adjacency_list.h Graph/adjacency_list.cpp
	$(CXX) $(CXXFLAGS) Graph/adjacency_list.cpp

dijkstra.o : Algorithms/dijkstra.h Algorithms/dijkstra.cpp
	$(CXX) $(CXXFLAGS) Algorithms/dijkstra.cpp

centrality.o : Algorithms/centrality.h Algorithms/centrality.cpp Algorithms/dijkstra.h
	$(CXX) $(CXXFLAGS) Algorithms/centrality.cpp

BFS_path.o : Algorithms/BFS_path.h Algorithms/BFS_path.cpp
	$(CXX) $(CXXFLAGS) Algorithms/BFS_path.cpp

main2: output_msg main2.o adjacency_list.o dijkstra.o centrality.o BFS_path.o
	$(LD) main2.o adjacency_list.o dijkstra.o centrality.o BFS_path.o $(LDFLAGS) -o main2

main2.o : main2.cpp adjacency_list.o dijkstra.o
	$(CXX) $(CXXFLAGS) main2.cpp

PNG.o : cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o : cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o : cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

Image.o : Image.cpp Image.h
	$(CXX) $(CXXFLAGS) Image.cpp


# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else

CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif

output_msg : ; $(CLANG_VERSION_MSG)

test: output_msg test.o adjacency_list.o dijkstra.o centrality.o BFS_path.o 
	$(LD) tests.o adjacency_list.o dijkstra.o centrality.o BFS_path.o $(LDFLAGS) -o test

test.o : tests/tests.cpp cs225/catch/catch.hpp Graph/adjacency_list.h Algorithms/dijkstra.h Algorithms/centrality.h Algorithms/BFS_path.h 
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean :
	-rm -f *.o $(EXENAME) test

.PHONY: all test clean output_msg