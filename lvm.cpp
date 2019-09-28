#include "lvm.h"
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

class SparseFileExtension : public std::exception {
  const char* what() const throw () {
    return "C++ Exception";
  }
};

int create_sparse_file(std::string path_to_file, size_t desired_size_kb) {
  int fd = open(path_to_file.c_str(), O_CREAT | O_RDWR | O_DIRECT);
  if (fd != -1) {
    off_t new_offset = lseek(fd, desired_size_kb * 1024, SEEK_SET);
    if (new_offset == -1) {
      throw "Failed to sparse";
    } else {
      return fd;
    }
  } else {
    throw "Failed to create/open";
  }
}


// class SparseFileManager{

//   mount
//   expand
//   shink

// };

