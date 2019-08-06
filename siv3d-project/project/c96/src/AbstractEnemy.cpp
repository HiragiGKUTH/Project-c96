#include "AbstractEnemy.hpp"
#include "GameDefine.hpp"


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
    return isInGameArea() || bulletManager.getBulletNum() > 0;
}

void AbstractEnemy::hit() {
    Print << U"Player to enemy hit";
}

void AbstractEnemy::move() {
    vel.set(Vec2(speed, 0).rotated(ang));
    pos.moveBy(vel);
    collision.setPos(pos);
}

void AbstractEnemy::bullet() {
    if (cnt%60== 0) {
        for (int i = 0; i < 6; i++) {
            if (i != (cnt/60)%6) {
                bulletManager.add(pos, GameDefine::PlayerPoses[i], i%2?1:0.5, 1);
            }
        }
    }
}

// return True if a Enemy in game area
bool AbstractEnemy::isInGameArea() {
    if (cnt < beginDurationFrame) {
        return true;
    }
    return GameDefine::GameArea.intersects(collision);
}

Circle* AbstractEnemy::getCollision() {
    return &collision;
}

Array<Circle*> AbstractEnemy::getBulletCollisions() {
    Array<Circle*> bulletCollisionList;
    for (int i = 0; i < bulletManager.getBulletNum(); ++i) {
    }
    return bulletCollisionList;
}

void AbstractEnemy::setCollisionSize(double r) {
    this->collisionRadius = r;
    this->collision = Circle(r);
}
