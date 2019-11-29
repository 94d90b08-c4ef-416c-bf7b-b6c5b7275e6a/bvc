#include "../include/lvmcore.h"
#include "../include/process.h"
#include <iostream>
#include <filesystem>
#include <fstream>
// #include <json-c/json.h>

#define FILE_NAME "TEST.bvc"
#define FILE_SIZE 1024*1024*128

int main(void) {

    // Case 1: create new repository
   try {
        // Create new sparse file
        SparseFile new_sparse_file(FILE_NAME, FILE_SIZE);
        std::cout << new_sparse_file.get_name() << std::endl;
        // Setup loop device
        exec("sudo losetup -f TEST.bvc");
        // Get loop device name
        std::string loop_dev_info = exec("sudo losetup -JO NAME -j TEST.bvc");
        std::cout << loop_dev_info << std::endl;
        // TODO: use JSON parser for this
        // but now it works for dev host
        std::string loop_dev_name = "/dev/loop0";
        // Make PV on it
        exec("sudo pvcreate " + loop_dev_name);
        std::cout << "Created PV: " << exec("sudo pvs")  << std::endl;
        // Make Volume group on the top of it
        exec("sudo vgcreate " + std::string(FILE_NAME) + " " + loop_dev_name);
        std::cout << "Created VG: " << exec("sudo vgs")  << std::endl;
        // Create thin pool volume
        exec("sudo lvcreate --type thin-pool -L " + std::to_string(FILE_SIZE) + " " + std::string(FILE_NAME) + "/pool");
        // Create root thin LV on pool
        // Make FS on root LV
        // Mount root LV
        // CLEANUP
        exec("sudo losetup -D");
   } catch (LVMCoreException& exc) {
       std::cout << exc.what() << std::endl;
   }

}
