CXX=g++
CXX_VERSION=9
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
CPPFLAGS=-std=c++17 -static-libstdc++

main: supp
	$(CXX) $(CPPFLAGS) -o $(BUILD_DIR)/main $(SRC_DIR)/main.cpp
test: supp
	$(CXX) $(CPPFLAGS) -o $(BUILD_DIR)/test $(SRC_DIR)/test.cpp
clean:
	rm -rf $(BUILD_DIR)
	rm -f TEST.bvc
supp:
	[ -d $(BUILD_DIR) ] || mkdir $(BUILD_DIR)

test/podman:
	podman run --rm --volume `pwd`:/tmp/bvc --workdir /tmp/bvc gcc:$(CXX_VERSION) make test

devenv:
	sudo dnf groupinstall "Development tools"
	sudo dnf install podman
