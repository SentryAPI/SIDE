#include "render_host.h"
#include <vector>

namespace render_host {
    std::vector<renderable*> renderable_objs;
    void queue_obj(renderable* obj) {
        renderable_objs.push_back(obj);
    }
    void pop_obj(renderable* obj) {
        renderable_objs.erase(std::find(renderable_objs.begin(), renderable_objs.end(), obj));
    }
    void render_all() {
        for(auto obj : renderable_objs) {
            obj->on_render();
        }
    }
};