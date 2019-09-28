CC=g++
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
CPPFLAGS=-std=c++17
EXECUTABLE=test

test:
	$(CC) $(CPPFLAGS) -o $(BUILD_DIR)/$(EXECUTABLE) $(SRC_DIR)/main.cpp
clean:
	rm -f $(BUILD_DIR)/test
#	rm -f TEST.SPARSE
