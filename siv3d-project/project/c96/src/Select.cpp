#include <string>

#include <Siv3D.hpp>
#include "Select.hpp"
#include "SelectionBox.hpp"
#include "GameInfo.hpp"
#include "GameData.hpp"

Array<Select::TrackInfo> Select::loadTrackInfo() {
    const JSONReader json(U"rc/track/track.data.json");
    if (!json) {
        Print << U"Select::Select() - failed to load json";
    }
    
    Array<TrackInfo> track_info;
    for (const auto& arr : json.arrayView()) {
        TrackInfo track;
        for (const auto& obj : arr.objectView()) {
            track.name = obj.value[U"track_name"].getString();
            track.difficulty = Parse<int>(obj.value[U"difficulty"].getString());
            track.musicPath  = obj.value[U"music_path"].getString();
            track.scorePath = obj.value[U"score_path"].getString();
            track.bpm = Parse<double>(obj.value[U"bpm"].getString());
        }
        track_info << track;
    }
    return track_info;
}

Select::Select(const InitData &init) : IScene(init) {
    // Load track infomation
    //this->track_info = loadTrackInfo();
    TrackInfo track;
    track.name = U"al fine";
    track.difficulty = 5;
    track.musicPath = U"rc/music/al_fine.wav";
    track.scorePath = U"rc/score/al_fine.csv";
    track.bpm = 212.0;
    
    this->track_info << track;

    // Init SelectionBox
    {
        Vec2 offset(Window::Width()/2, Window::Height()/8);
        Vec2 pos_differ(Window::Width()/16, Window::Height()/6);
        
        for (auto i : step(track_info.size())) {
            auto sb = SelectionBox(this->track_info[i].name, Palette::Blue);
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
    for (auto& selection_box : selection_boxes) {
        selection_box.draw();
    }
}


