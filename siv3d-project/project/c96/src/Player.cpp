#include "Player.hpp"
#include "GameDefine.hpp"

Player::Player() {
    this->pos = Vec2(Define::WindowSize.x/2, Define::WindowSize.y/2);
    this->collision.set(this->pos, 16.0);
    this->color = Palette::White;
}

bool Player::update() {
    color = Palette::White;
    move();
    shot();
    return true;
}

void Player::draw() const {
    collision.draw(color);
    Print << shotList.size() << U" Shots";
    for (auto& shot : shotList) {
        shot->draw();
    }
    Print << pos;
    for (auto& movePos : GameDefine::PlayerPoses) {
        Circle(movePos, 16.0).drawFrame(4.0, Palette::Orange);
    }
}

void Player::move() {
    // set target pos
    if (KeyS.down()) {
        targetPos = GameDefine::PlayerPoses[0];
    }
    if (KeyD.down()) {
        targetPos = GameDefine::PlayerPoses[1];
    }
    if (KeyF.down()) {
        targetPos = GameDefine::PlayerPoses[2];
    }
    if (KeyJ.down()) {
        targetPos = GameDefine::PlayerPoses[3];
    }
    if (KeyK.down()) {
        targetPos = GameDefine::PlayerPoses[4];
    }
    if (KeyL.down()) {
        targetPos = GameDefine::PlayerPoses[5];
    }
    
    vel = (targetPos - pos)/5;
    pos.moveBy(vel);
    
    collision.setPos(pos);
}

void Player::shot() {
    if (System::FrameCount() % 10 == 0) {
        shotList << std::make_shared<Shot>(pos, 10.0, ToRadians(270));
    }
    
    // shot updates
    {
        unsigned long shotNum = shotList.size();
        for (int i = 0;i < shotNum; ++i) {
            // delete shot if outside of game area
            if (!shotList.at(i)->update()) {
                shotList.remove_at(i);
                shotNum--;
            }
        }
    }
}

Circle* Player::getCollision() {
    return &collision;
}

Array<Circle*> Player::getShotCollisions() {
    Array<Circle*> shotCollisionList;
    for (auto& shot : shotList) {
        shotCollisionList.push_back(shot->getCollision());
    }
    return shotCollisionList;
}

void Player::hit() {
    color = Palette::Red;
}
