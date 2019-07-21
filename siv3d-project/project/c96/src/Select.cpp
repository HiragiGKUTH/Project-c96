#include <Siv3D.hpp>
#include "Select.hpp"
#include "SelectionBox.hpp"
#include "GameInfo.hpp"
#include "GameData.hpp"


Array<String> getTrackList() {
    TextReader reader(U"assets/track/track.list");
    String line;
    Array<String> lines;
    while (reader.readLine(line)) {
        lines << line;
    }
    return lines;
}

Select::Select(const InitData &init) : IScene(init) {
    // Get Track names
    this->track_names = getTrackList();
    
    // Init SelectionBox
    {
        Vec2 offset(Window::Width()/2, Window::Height()/8);
        Vec2 pos_differ(Window::Width()/16, Window::Height()/6);
        
        for (auto i : step(track_names.size())) {
            auto sb = SelectionBox(this->track_names[i], Palette::Blue);
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
            changeScene(U"Game");
        }        
    }
}

void Select::draw() const {
    Print << track_names;
    for (auto& selection_box : selection_boxes) {
        selection_box.draw();
    }
}


