#include <Siv3D.hpp>
#include "NormalEnemy.hpp"


NormalEnemy::NormalEnemy(Vec2 pos, double speed, double ang) : AbstractEnemy(pos) {
    this->speed = speed;
    this->ang = ang;
    this->setCollisionSize(16.0);
}

void NormalEnemy::draw() const {
    // this is alternative way for drawing enemy
    collision.draw();
    bulletManager.draw();
}
