#include "Shot.hpp"

Shot::Shot(Vec2 pos, double ang, double speed) {
    this->pos = pos;
    this->vel = Vec2(speed, 0).rotated(ang);
    this->collision = Circle(4);
}

bool Shot::update() {
    pos.moveBy(vel);
    collision.setPos(pos);
    return true;
}

void Shot::draw() const {
    collision.draw();
}