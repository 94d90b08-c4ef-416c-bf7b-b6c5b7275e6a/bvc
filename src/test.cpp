#include "../include/lvmcore.h"
#include <iostream>
#include <filesystem>
#include <fstream>

#define FILE_NAME "TEST.bvc"

int main(void) {

   try {
       SparseFile new_sparse_file(FILE_NAME, 1024*1024);
   } catch (LVMCoreException& exc) {
       std::cout << exc.what() << std::endl;
   }

}
