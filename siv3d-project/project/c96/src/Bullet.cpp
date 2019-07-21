#include "Bullet.hpp"

Bullet::Bullet(Vec2 pos, Vec2 targetPos, double arriveTime, int moveKind = 1) {
    this->pos = pos;
    this->targetPos = targetPos;
    this->arriveTime = arriveTime;
    this->moveKind = moveKind;
    
    this->currentTime = 0.0;
    this->startPos = this->pos;
    this->collision.setR(32.0);
}

bool Bullet::update() {
    currentTime+=System::DeltaTime();
    
    switch (moveKind) {
        case 1:
            pos = startPos + (targetPos - startPos) * (currentTime/arriveTime);
            break;
        default:
            Print << U"Bullet::Update():error - Unknown move kind";
            pos = Vec2::Zero();
            break;
    }
    collision.setPos(pos);
    
    return Window::ClientRect().intersects(collision);
}

void Bullet::draw() const {
    //todo: draw actual bullet
    collision.draw(Palette::Red);
    if (arriveTime > currentTime) {
        Circle(targetPos, 32.0).drawFrame(0.0, 3.0, Palette::White, Palette::Orange);
    }
}
