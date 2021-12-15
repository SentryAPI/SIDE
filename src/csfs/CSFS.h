#include <string>
#include <vector>

namespace CSFS {
    //Returns the current directory (based on system dir)
    //Likely to be ROOT on WASM if the current dir isn't changed!
    std::string GetCurrentDir();
    //Set the current directory
    void SetCurrentDir(std::string dir);
    //Get the directory that we started execution in
    std::string GetExecDir();
    //Get all files in current directory
    std::vector<std::string> GetAllFiles();
    //Get all files in specified directory (relative to GetCurrentDir)
    std::vector<std::string> GetAllFiles(std::string root);
    //Get all directories in current directory
    std::vector<std::string> GetAllDirectories();
    //Get all directories in specified directory (relative to GetCurrentDir)
    std::vector<std::string> GetAllDirectories(std::string root);
};