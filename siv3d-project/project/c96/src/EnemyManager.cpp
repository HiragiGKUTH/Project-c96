#include "EnemyManager.hpp"
#include "Enemy.hpp"


EnemyManager::EnemyManager() {
    this->enemyList.push_back(std::make_shared<Enemy>(Vec2(240,240), 1.0, ToRadians(90)));
}

bool EnemyManager::update() {
    for (auto& enemy : enemyList) {
        if (!enemy->update()) {
            enemyList.remove(enemy);
        }
    }
    return true;
}

void EnemyManager::draw() const {
    for (auto& enemy : enemyList) {
        enemy->draw();
    }
}
