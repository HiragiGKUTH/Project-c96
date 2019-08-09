#include "Record.hpp"


Record::Record(const InitData &init) : IScene(init) {
    this->recordingAudio = Audio(getData().trackInfo.musicPath);
    this->recordingTimer.start();
    this->recordingAudio.play();
}

void Record::update() {
    Array<GameDefine::ePlayerPos> pushedPoses;
    
    // key pressings
    if (KeyS.down())
        pushedPoses.push_back(GameDefine::ePlayerPos::S);
    if (KeyD.down())
        pushedPoses.push_back(GameDefine::ePlayerPos::D);
    if (KeyF.down())
        pushedPoses.push_back(GameDefine::ePlayerPos::F);
    if (KeyJ.down())
        pushedPoses.push_back(GameDefine::ePlayerPos::J);
    if (KeyK.down())
        pushedPoses.push_back(GameDefine::ePlayerPos::K);
    if (KeyL.down())
        pushedPoses.push_back(GameDefine::ePlayerPos::L);
    
    
    for (auto& pushedPos : pushedPoses) {
        std::pair<double, GameDefine::ePlayerPos> note;
        note.first = recordingAudio.posSec();
        note.second = pushedPos;
        notes.push_back(note);
    }
    
    if (!recordingAudio.isPlaying()) {
        save();
        changeScene(U"Title");
    }
}

void Record::draw() const {
    for (auto& note : notes) {
        Print << note;
    }
}

void Record::save() {
    String path = getData().trackInfo.scorePath;
    CSVData csv;
    
    for (auto& note : notes) {
        csv.write(note.first);
        csv.write(note.second);
        csv.newLine();
    }
    
    csv.save(path);
}
