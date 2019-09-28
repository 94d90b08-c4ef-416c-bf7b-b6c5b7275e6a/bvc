#include <filesystem>
#include <exception>
#include <fstream>
#include <lvm2app.h>

class LVMCoreException: public std::exception {
public:
    virtual const char* what() {
        return "Something goes wrong in LVM world";
    }
};

class SetSizeFailed: public LVMCoreException {
    std::string reason;
public:
    SetSizeFailed() {
        reason = "File allocation failed because of GTFO, thats why";
    }
    SetSizeFailed(std::string _reason) {
        reason = _reason;
    }
    const char* what() {
        return reason.c_str();
    }
};

class SparseFile {

    std::filesystem::path file_path;
    unsigned long desired_size;
    unsigned long current_size;

public:

    SparseFile(std::string _file_path, unsigned long _file_size, bool allow_shrink=false) {
        /* Handles sparse file */
        file_path = _file_path;
        desired_size = _file_size;
        if (std::filesystem::exists(file_path)) {
            current_size = std::filesystem::file_size(file_path);
        } else {
            make_file();
            current_size = 0;
        }
        if (current_size != desired_size) {
            set_size(allow_shrink);
        }
    }

private:

    void set_size(bool _allow_shrink) {
        /* Simply change existing file size */
        if (current_size <= desired_size) {
            std::filesystem::resize_file(file_path, desired_size);
        } else if (_allow_shrink)
        {
            std::filesystem::resize_file(file_path, desired_size);
        } else {
            throw SetSizeFailed("Desired size less that current and shrinking is not allowed");
        }
        current_size = std::filesystem::file_size(file_path);
    }

    void make_file() {
        /* Create file if it doesnt exist */
        std::ofstream tmp(file_path);
        tmp.close();
    }

};

namespace LVMCore {
    class PV {
        PV(SparseFile){

        }

    };


};
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

