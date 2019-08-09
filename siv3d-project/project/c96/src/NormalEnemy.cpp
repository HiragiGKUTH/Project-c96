#include <Siv3D.hpp>
#include "NormalEnemy.hpp"


NormalEnemy::NormalEnemy(Vec2 pos, double exitAngle, Array<std::pair<double, GameDefine::ePlayerPos>> notesInfo, double arrivalDuration)
        : AbstractEnemy(pos, exitAngle, notesInfo, arrivalDuration) {
    this->setCollisionSize(16.0);
}

void NormalEnemy::draw() const {
    // this is alternative way for drawing enemy
    collision.draw();
    bulletManager.draw();
}
