#ifndef SRC_STORAGE_SENTRYFILE
#define SRC_STORAGE_SENTRYFILE
struct entry_value {
    int size;
    char* content;
};
struct entry {
    char key[0xF];
    entry_value value;
};
struct header {
    char generatorVersionMajor;
    char generatorVersionMinor;
    char generatorVersionPatch;
    char generatorReserved1;
    char generatorReserved2;
    char generatorReserved3;
    short generatorPatchCount;
};
struct sentryfile {
    header format_info;
    int entry_count;
    entry* entries;
};
#endif /* SRC_STORAGE_SENTRYFILE */
