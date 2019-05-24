#include "Bullet.hpp"

Bullet::Bullet(Vec2 pos, double speed, double ang) {
    this->pos = pos;
    this->speed = speed;
    this->ang = ang;
    
    this->collision = Circle(20);
    
    // 右を初期値に回す
    this->vel = Vec2::Right().rotate(ang)*speed;
}

bool Bullet::update() {
    vel = Vec2::Right().rotate(ang)*speed;
    pos.moveBy(vel);
    collision.setPos(pos);
    
    return Window::ClientRect().intersects(collision);
}

void Bullet::draw() const {
    //todo: draw actual bullet
    collision.draw();
}
