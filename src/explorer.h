#ifndef SRC_EXPLORER
#define SRC_EXPLORER
#include "renderable.h"

class explorer : public renderable {
    explorer();
    ~explorer();
    char search_buffer[256];
public:
    static explorer* get_explorer();
    void on_render() override;
};
#endif /* SRC_EXPLORER */
