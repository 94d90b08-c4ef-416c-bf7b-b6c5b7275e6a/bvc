#include "../include/lvm.h"
#include <exception>

/*

Manage LVM pool as a file

*/


// class PoolManager{


//   create_file
//   make_vg
//   make_lv
//   destructor // commit all changes to the file


// };

// class SparseFileExtension : public std::exception {
// private:
//   int return_code;
// public:
//   SparseFileExtension():return_code(0){}
//   SparseFileExtension(int code):return_code(return_code){}
//   const char* what() {
//     std::string msg = "SparseFileExtension: ";
//     //if(return_code)
//     return "C++ Exception";
//   }
// };

// int create_sparse_file(std::string path_to_file, size_t desired_size_kb) {
//   int fd = open(path_to_file.c_str(), O_CREAT | O_RDWR | O_DIRECT | O_SYNC, 0644);
//   if (fd != -1) {
//     int res = fallocate(fd, NULL, 0, desired_size_kb * 1024);
//     return res;
//     // off_t new_offset = lseek(fd, (desired_size_kb * 1024) - 1, SEEK_CUR);
//     // if (new_offset == -1) {
//     //   throw "Failed to sparse";
//     // } else {
//     //   write(fd, "\0", 1);
//     //   close(fd);
//     //   return fd;
//     // }
//   } else {
//     throw "Failed to create/open";
//   }
// }


// class SparseFileManager{

//   mount
//   expand
//   shink

// };

