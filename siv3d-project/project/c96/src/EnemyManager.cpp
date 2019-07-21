#include "EnemyManager.hpp"
#include "NormalEnemy.hpp"
#include "GameDefine.hpp"


EnemyManager::EnemyManager() {
    this->enemyList.push_back(std::make_shared<NormalEnemy>(Vec2(480,240), 1.0, ToRadians(90)));
}

bool EnemyManager::update() {
    
    // Enemy deletation
    unsigned long enemyNum = enemyList.size();
    for (int i = 0; i < enemyNum; ++i) {
        if (!enemyList.at(i)->update()) {
            // i-- to avoid skipping enemy update 
            enemyList.remove_at(i--);
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

Array<Circle*> EnemyManager::getCollisions() {
    Array<Circle*> enemyCollisions;
    for (auto& enemy : enemyList) {
        enemyCollisions.push_back(enemy->getCollision());
    }
    return enemyCollisions;
}

Array<Circle*> EnemyManager::getBulletCollisions() {
    Array<Circle*> enemyBulletCollisions;
    for (auto& enemy : enemyList) {
        enemyBulletCollisions.append(enemy->getBulletCollisions());
    }
    return enemyBulletCollisions;
}
