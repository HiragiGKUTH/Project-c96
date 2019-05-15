#include "EnemyManager.hpp"
#include "Enemy.hpp"


EnemyManager::EnemyManager() {
    this->enemyList.push_back(std::make_shared<Enemy>(Vec2(240,240), 10.0, ToRadians(90)));
}

bool EnemyManager::update() {
    
    // Enemy deletation
    unsigned long enemyNum = enemyList.size();
    for (int i = 0; i < enemyNum; ++i) {
        if (!enemyList.at(i)->update()) {
            enemyList.remove_at(i);
            enemyNum--;
        }
    }
    return true;
}

void EnemyManager::draw() const {
    Print << enemyList.size() << U" Enemies";
    for (auto& enemy : enemyList) {
        enemy->draw();
    }
}
