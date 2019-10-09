CC=g++
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
CPPFLAGS=-std=c++17
EXECUTABLE=test

test:
	g++ -o cli src/cli.cpp -L../../libs/usr/local/lib64/ -I../../libs/usr/local/include/docopt/ -ldocopt
	export LD_LIBRARY_PATH=/home/alise/libs/usr/local/lib64/
clean:
	rm cli
