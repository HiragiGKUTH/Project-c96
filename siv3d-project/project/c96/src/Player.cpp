#include "Player.hpp"

Player::Player() {
    this->pos = Vec2(Define::WindowSize.x/2, Define::WindowSize.y/2);
    this->collision.set(this->pos, 4.0);
}

bool Player::update() {
    move();
    return true;
}

void Player::draw() const {
    collision.draw();
    Print << pos;
}


void Player::move() {
    Vec2 tmp_vel = Vec2::Zero();
    int push_num = 0;
    
    // key ifs...
    if (KeyUp.pressed()) { tmp_vel+=Vec2::Up(); push_num++;}
    if (KeyRight.pressed()) { tmp_vel+=Vec2::Right(); push_num++;}
    if (KeyDown.pressed()) { tmp_vel+=Vec2::Down(); push_num++;}
    if (KeyLeft.pressed()) { tmp_vel+=Vec2::Left(); push_num++;}
    // If shift pressed player move slow
    if (KeyShift.pressed()) { tmp_vel*=0.6; }
    // If player will move to diagonal, set speed 1/1.414...
    if (push_num > 1) tmp_vel/=Math::Sqrt(2.0);
    //apply position
    pos.moveBy(tmp_vel*speed);
    collision.setPos(pos);
}
