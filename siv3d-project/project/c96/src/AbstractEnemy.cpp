#include "AbstractEnemy.hpp"


AbstractEnemy::AbstractEnemy(Vec2 pos) {
    this->pos = pos;
    this->speed = 0;
    this->ang = 0;
    this->vel = Vec2(speed, 0).rotated(ang);
}

bool AbstractEnemy::update() {
    move();
    bullet();
    bulletManager.update();
    cnt++;
    return isInGameArea();
}

void AbstractEnemy::move() {
    vel.set(Vec2(speed, 0).rotated(ang));
    pos.moveBy(vel);
    collision.setPos(pos);
}

void AbstractEnemy::bullet() {
    for (auto i : step(36)) {
        bulletManager.add(pos, 10, ToRadians(i*10));
    }
}
    

// return True if a Enemy in game area
bool AbstractEnemy::isInGameArea() {
    if (cnt < beginDurationFrame) {
        return true;
    }
    return Window::ClientRect().intersects(collision);
}

Array<Circle*> AbstractEnemy::getCollisions() {
    Array<Circle*> collisionList;
    collisionList.push_back(&collision);
    for (int i = 0; i < bulletManager.getBulletNum(); ++i) {
        collisionList.push_back(bulletManager.at(i)->getCollision());
    }
    return collisionList;
}

void AbstractEnemy::setCollisionSize(double r) {
    this->collisionRadius = r;
    this->collision = Circle(r);
}
