#include "lvm.h"
#include <iostream>
#include <unistd.h>

int main(void){
    std::string path_to_sparse_file("TEST.SPARSE");
    int fd = create_sparse_file(path_to_sparse_file, 10240);
    std::cout << "File descriptor made: " << fd << std::endl;
    return unlink(path_to_sparse_file.c_str());
}