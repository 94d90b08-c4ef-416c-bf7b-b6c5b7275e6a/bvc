#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>


int create_sparse_file(std::string path_to_file, size_t desired_size);
