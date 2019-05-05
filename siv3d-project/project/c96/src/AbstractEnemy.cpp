#include "AbstractEnemy.hpp"

AbstractEnemy::AbstractEnemy(Vec2 pos) {
    this->pos = pos;
    this->speed = 0;
    this->ang = 0;
    this->vel = Vec2(speed, 0).rotated(ang);
}

bool AbstractEnemy::update() {
    vel.set(Vec2(speed, 0).rotated(ang));
    pos.moveBy(vel);
    return true;
}
