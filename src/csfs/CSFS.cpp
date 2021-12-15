#include "CSFS.h"
#include "../platform.h"

namespace CSFS {
    #if PLATFORM == WIN
    //Doesnt support multiple drives, no real way to achieve this on windows
    std::string root = "C:/";
    #else
    std::string root = "/";
    #endif

    std::string executing_directory = ""; //TODO: Get the current dir
    std::string current_directory = executing_directory;

    //Returns the current directory (based on system dir)
    //Likely to be ROOT on WASM if the current dir isn't changed!
    std::string GetCurrentDir() {
        return current_directory;
    }
    //Set the current directory
    void SetCurrentDir(std::string dir) {
        if(dir == "..") {
            std::string parent_directory = ""; //TODO: String shit to get parent dir
            current_directory = parent_directory;
        }
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