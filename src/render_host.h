#ifndef SRC_RENDER_HOST
#define SRC_RENDER_HOST
#include "renderable.h"

namespace render_host {
    //Add renderable to render queue
    void queue_obj(renderable*);
    void pop_obj(renderable*);
    void render_all();
};
#endif /* SRC_RENDER_HOST */
