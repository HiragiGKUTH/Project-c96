#include "BulletManager.hpp"

BulletManager::BulletManager() {
    
}

bool BulletManager::add(Vec2 pos, double speed, double ang) {
    if (bulletList.size() >= MAX_BULLETS) {
        Print << U"BulletManager: can't add more bullet. >10000";
        return false;
    }
    // make bullet and push
    bulletList.push_back(std::make_shared<Bullet>(pos, speed, ang));
    return true;
}

unsigned long BulletManager::getBulletNum() {
    return bulletList.size();
}

std::shared_ptr<Bullet> BulletManager::at(int index) {
    return bulletList.at(index);
}

bool BulletManager::update() {
    unsigned long bulletNum = bulletList.size();
    for (int i = 0; i < bulletNum; ++i) {
        if (!bulletList.at(i)->update()) {
            bulletList.remove_at(i);
            bulletNum--;
        }
    }
    return true;
}

void BulletManager::draw() const {
    Print << U"BulletManager: " << bulletList.size() << U"bullets";
    for (auto bullet : bulletList){
        bullet->draw();
    }
}
