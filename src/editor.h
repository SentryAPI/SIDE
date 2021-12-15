#include <string>
#include "renderable.h"
#include "../imgui/TextEditor.h"

class editor : public renderable {
    std::string file;
    std::string editor_name;
    int unique_id;
    TextEditor* ext_editor;
    bool open;
public:
    editor(std::string file, std::string editor_name);
    ~editor();
    void save();
    void on_render() override;
};