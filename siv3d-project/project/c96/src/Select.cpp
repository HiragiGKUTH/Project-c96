#include <string>

#include <Siv3D.hpp>
#include "Select.hpp"
#include "SelectionBox.hpp"
#include "GameInfo.hpp"
#include "GameData.hpp"

Array<TrackInfo> Select::loadTrackInfo() {
    const JSONReader json(U"rc/track/track.data.json");
    if (!json) {
        Print << U"Select::Select() - failed to load json";
    }
    
    Array<TrackInfo> track_info;
    for (const auto& obj : json.arrayView()) {
        TrackInfo track;
        track.name = obj[U"track_name"].getString();
        track.difficulty = obj[U"difficulty"].get<int>();
        track.musicPath  = obj[U"music_path"].getString();
        track.scorePath = obj[U"score_path"].getString();
        track.bpm = obj[U"bpm"].get<double>();
        track_info << track;
    }
    return track_info;
}

Select::Select(const InitData &init) : IScene(init) {
    // Load track infomation
    this->track_info = loadTrackInfo();
    
    // Init SelectionBox
    {
        Vec2 offset(Window::Width()/2, Window::Height()/8);
        Vec2 pos_differ(Window::Width()/16, Window::Height()/6);
        
        for (auto i : step(track_info.size())) {
            auto sb = SelectionBox((int)i, this->track_info[i].name, Palette::Blue);
            sb.setPos(offset + (pos_differ * i));
            this->selection_boxes << sb;
        }
    }
}

void Select::update() {
    for (auto& selection_box : selection_boxes) {
        // Set difficulty and change scene when selection box clicked
        if (selection_box.getRegion().leftClicked()) {
            getData().trackInfo = track_info[selection_box.getId()];
            changeScene(U"Game");
        }        
    }
}

void Select::draw() const {
    for (auto& selection_box : selection_boxes) {
        selection_box.draw();
    }
}


