#include "editor.h"
#include "render_host.h"
#include "lang_defs.h"

editor::editor(std::string file, std::string editor_name) {
    //Heap allocate the editor & store the pointer
    this->ext_editor = new TextEditor();
    auto lang_def = SIDE_LANG::LanguageDefinition::Javascript();
    this->ext_editor->SetLanguageDefinition(lang_def);
    this->editor_name = editor_name;
    this->open = true;
    this->unique_id = (int)(random()*100);
    //TODO: Load file content into editor
}
editor::~editor() {
    //Clean up external editor & free memory
    delete this->ext_editor;
}
void editor::save() {
    std::string content(this->ext_editor->GetText());
    //TODO: save 'content' to mod
}
void editor::on_render() {
    std::string title(editor_name+"###"+std::to_string(this->unique_id));
    ImGui::Begin(title.c_str(), &this->open);
    this->ext_editor->Render(editor_name.c_str());
    ImGui::End();
    if(!this->open) {
        this->save();
        render_host::pop_obj(this);
        delete this;
    }
}