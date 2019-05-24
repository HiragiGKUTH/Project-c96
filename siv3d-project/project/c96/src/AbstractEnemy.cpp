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
    collision.setPos(pos);
    cnt++;
    return isInGameArea();
}

// return True if a Enemy in game area
bool AbstractEnemy::isInGameArea() {
    if (cnt < beginDurationFrame) {
        return true;
    }
    return Window::ClientRect().intersects(collision);
}

void AbstractEnemy::setCollisionSize(double r) {
    this->collisionRadius = r;
    this->collision = Circle(r);
}
