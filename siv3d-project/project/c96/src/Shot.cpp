#include "Shot.hpp"


Shot::Shot(Vec2 pos, double speed, double ang) {
    this->pos = pos;
    this->vel = Vec2(speed, 0).rotated(ang);
    this->collision = Circle(8);
}

bool Shot::update() {
    pos.moveBy(vel);
    collision.setPos(pos);
    return isInGameArea();
}

void Shot::draw() const {
    collision.draw();
}

// return True if a Shot is in game area
bool Shot::isInGameArea() {
    return Window::ClientRect().intersects(collision);
}

