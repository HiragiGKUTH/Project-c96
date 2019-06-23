#include <Siv3D.hpp>
#include "GameDefine.hpp"
#include "Board.hpp"



Board::Board() {
    // nothing todo yet wow
}

bool Board::update() {
    return true;
}


void Board::draw() const {
    GameDefine::GameArea.drawFrame(2, 0, Palette::Red);
    GameDefine::GameArea.drawFrame(0, 1024, Palette::White);
}
