#include <Siv3D.hpp>
#include "GameDefine.hpp"
#include "Board.hpp"
#include "baseEffect.hpp"



Board::Board(Array<std::pair<double, GameDefine::ePlayerPos>> notes, double musicLength) {
    this->notes = notes;
    this->musicLength = musicLength;
    for (auto& pos : GameDefine::PlayerPoses) {
        this->baseCircles.push_back(Circle(pos, this->r));
    }
    this->judgeMargin = 0.3;
    this->score = 0;
    this->timer.reset();
}

bool Board::update() {
    keyJudge();
    

    

    // effects update
    RenderStateBlock2D blend(BlendState::Additive);
    effect.update();
    return true;
}


void Board::draw() const {
    for (auto& base : baseCircles) {
        base.drawFrame(0.0, 2.0);
    }
    
    GameDefine::GameArea.drawFrame(2, 0, Palette::Red);
    GameDefine::GameArea.drawFrame(0, 1024, Palette::White);
}

void Board::beginTimer() {
    timer.start();
}

void Board::keyJudge() {
    Array<bool> keys;
    Array<int> pushed;
    bool s = KeyS.down();
    bool d = KeyD.down();
    bool f = KeyF.down();
    bool j = KeyJ.down();
    bool k = KeyK.down();
    bool l = KeyL.down();
    keys << s << d << f << j << k << l;
    
    for (int i = 0; i < keys.size(); i++) {
        if (keys[i]){
            pushed << i;
        }
    }
    
    
    Array<std::pair<double, GameDefine::ePlayerPos>> judgeNotes;
    
    for (auto& note : notes) {
        double begin = timer.sF() - judgeMargin;
        double end = timer.sF() + judgeMargin;
        if (begin <= note.first && note.first < end) {
            judgeNotes.push_back(note);
        }
    }
    
    for (auto& note : judgeNotes) {
        double diff = Math::Abs(timer.sF() - note.first);
        if (pushed.count(note.second) > 0) {
            // score calc
            if (diff < judgeMargin * 0.3) {
                score +=700;
                continue;
            }
            if (diff < judgeMargin * 0.5) {
                score +=500;
                continue;
            }
            if (diff < judgeMargin * 0.8) {
                score -= 100;
                continue;
            }
        }
    }
    Print << score;
}
