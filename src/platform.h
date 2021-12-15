#ifndef SRC_PLATFORM
#define SRC_PLATFORM

#ifdef __EMSCRIPTEN__
    #define PLATFORM WASM
#elif _WIN32 // note the underscore: without it, it's not msdn official!
    #define PLATFORM WIN
#elif __unix__ // all unices, not all compilers
    #define PLATFORM UNIX
#elif __linux__
    #define PLATFORM LINUX
#elif __APPLE__
    #define PLATFORM DAR
#endif

#endif /* SRC_PLATFORM */
