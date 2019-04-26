#include <Siv3D.hpp>
#include "Select.hpp"
#include "SelectionBox.hpp"
#include "GameInfo.hpp"
#include "GameData.hpp"

Select::Select(const InitData &init) : IScene(init) {
    // Set difficulty texts
    this->difficulty_names = GameInfo::Difficulty_names;
    this->difficulty_descriptions = GameInfo::Difficulty_descriptions;
    
    // Init SelectionBox
    {
        Vec2 offset(Window::Width()/2, Window::Height()/8);
        Vec2 pos_differ(Window::Width()/16, Window::Height()/6);
        
        for (auto i : step(difficulty_names.size())) {
            auto sb = SelectionBox(this->difficulty_names[i], Palette::Blue);
            sb.setPos(offset + (pos_differ * i));
            this->selection_boxes << sb;
        }
    }
}

void Select::update() {
    for (auto& selection_box : selection_boxes) {
        // Set difficulty and change scene when selection box clicked
        if (selection_box.getRegion().leftClicked()) {
            String difficulty_text = selection_box.getText();
            getData().difficulty = difficulty_text;
            changeScene(U"Game");
        }        
    }
}

void Select::draw() const {
    for (auto& selection_box : selection_boxes) {
        selection_box.draw();
    }
}
