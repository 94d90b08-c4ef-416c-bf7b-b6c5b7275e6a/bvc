CXX=g++
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
CPPFLAGS=-std=c++17
#EXECUTABLE=test

main: supp
	$(CXX) $(CPPFLAGS) -o $(BUILD_DIR)/main $(SRC_DIR)/main.cpp
test: supp
	$(CXX) $(CPPFLAGS) -o $(BUILD_DIR)/test $(SRC_DIR)/test.cpp
clean:
	rm -rf $(BUILD_DIR)
	rm -f TEST.bvc
supp:
	[ -d $(BUILD_DIR) ] || mkdir $(BUILD_DIR)
