#include "CSFS.h"

namespace CSFS {
    //Returns the current directory (based on system dir)
    //Likely to be ROOT on WASM if the current dir isn't changed!
    std::string GetCurrentDir() {
        return "";
    }
    //Set the current directory
    void SetCurrentDir(std::string dir) {

    }
    //Get the directory that we started execution in
    std::string GetExecDir() {
        return "";
    }
    //Get all files in current directory
    std::vector<std::string> GetAllFiles() {
        return std::vector<std::string>();
    }
    //Get all files in specified directory (relative to GetCurrentDir)
    std::vector<std::string> GetAllFiles(std::string root) {
        return std::vector<std::string>();
    }
    //Get all directories in current directory
    std::vector<std::string> GetAllDirectories() {
        return std::vector<std::string>();
    }
    //Get all directories in specified directory (relative to GetCurrentDir)
    std::vector<std::string> GetAllDirectories(std::string root) {
        return std::vector<std::string>();
    }
};