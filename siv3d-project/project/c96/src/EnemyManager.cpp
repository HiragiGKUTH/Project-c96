#include "EnemyManager.hpp"
#include "NormalEnemy.hpp"


EnemyManager::EnemyManager() {
    this->enemyList.push_back(std::make_shared<NormalEnemy>(Vec2(240,240), 1.0, ToRadians(90)));
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

Array<Circle*> EnemyManager::getEnemyCollisions() {
    Array<Circle*> allEnemyCollisions;
    for (auto& enemy : enemyList) {
        allEnemyCollisions.append(enemy->getCollisions());
    }
    return allEnemyCollisions;
}
