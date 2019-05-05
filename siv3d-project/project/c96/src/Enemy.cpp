#include <Siv3D.hpp>
#include "Enemy.hpp"


Enemy::Enemy(Vec2 pos, double speed, double ang) : AbstractEnemy(pos) {
    this->speed = speed;
    this->ang = ang;
}

void Enemy::draw() const {
    Circle(pos, 16).draw(Palette::Red);
}
