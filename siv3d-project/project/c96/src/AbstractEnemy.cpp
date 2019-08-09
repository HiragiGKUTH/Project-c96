#include "AbstractEnemy.hpp"
#include "GameDefine.hpp"


AbstractEnemy::AbstractEnemy(Vec2 pos, double exitAngle, Array<std::pair<double, GameDefine::ePlayerPos>> notesInfo, double arrivalDuration) {
    this->pos = pos;
    this->speed = 0;
    this->ang = exitAngle;
    this->arrivalDuration = arrivalDuration;
    this->notesInfo = notesInfo;
    this->vel = Vec2(speed, 0).rotated(ang);
    
    this->timer.start();
}

bool AbstractEnemy::update() {
    move();
    bullet();
    bulletManager.update();
    return isInGameArea() || bulletManager.getBulletNum() > 0;
}

void AbstractEnemy::hit() {
}

void AbstractEnemy::move() {
    speed+=0.0;
    vel.set(Vec2(speed, 0).rotated(ang));
    pos.moveBy(vel);
    collision.setPos(pos);
}

void AbstractEnemy::bullet() {
    unsigned long notesNum = notesInfo.size();
    for (int i = 0; i < notesNum; i++) {
        if (timer.sF() + arrivalDuration > notesInfo.at(i).first) {
            bulletManager.add(pos, GameDefine::PlayerPoses[notesInfo.at(i).second], arrivalDuration, 1);
            notesInfo.remove_at(i--);
            notesNum--;
        }
    }
}

// return True if a Enemy in game area
bool AbstractEnemy::isInGameArea() {
    return GameDefine::GameArea.intersects(collision);
}

Circle* AbstractEnemy::getCollision() {
    return &collision;
}


void AbstractEnemy::setCollisionSize(double r) {
    this->collisionRadius = r;
    this->collision = Circle(r);
}
