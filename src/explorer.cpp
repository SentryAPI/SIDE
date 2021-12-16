#include "explorer.h"
#include "../imgui/imgui.h"
#include "render_host.h"
#include <vector>
#include <string>

explorer* singleton;
explorer::explorer() {
    //Duplicate instance check
    if(singleton) {
        //yikers
        //Lets throw out the old instance & replace it for a new one
        render_host::pop_obj(singleton);
        delete singleton;
    }
    //Create new instance
    singleton = this;
    render_host::queue_obj(this);
}
explorer::~explorer() {
    //If its detached for some reason, just throw everything out
    if(this != singleton) {
        delete singleton;
    }
    render_host::pop_obj(this);
}

explorer* explorer::get_explorer() {
    if(singleton) {
        return singleton;
    }
    //Heap allocation, dont forget to delete when its useless!!!
    singleton = new explorer();
    return singleton;
}

std::vector<std::string> keys = {"Test", "Test2", "Test3"};
void explorer::on_render() {
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar;
    ImGui::Begin("Explorer", nullptr, window_flags);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImGui::InputText("Search", this->search_buffer, IM_ARRAYSIZE(this->search_buffer));
    //-FLT_MIN in the imvec2 makes it take up all available space
    if(ImGui::BeginListBox("##FilesBox", ImVec2(-FLT_MIN, -FLT_MIN))) {
        for(auto key : keys) {
            if(key.find(this->search_buffer) != std::string::npos) {
                if(ImGui::Selectable(key.c_str())) {
                    //Cool stuff here
                }
            }
        }
        ImGui::EndListBox();
    }

    ImGui::End();
}