#include "EnemyManager.hpp"
#include "NormalEnemy.hpp"
#include "GameDefine.hpp"


EnemyManager::EnemyManager(double bpm) {
    this->trackTimer.reset();
    this->beatTime = 60.0 / bpm;
}

void EnemyManager::beginTimer() {
    trackTimer.start();
}

bool EnemyManager::update() {
    
    if (trackTimer.sF() > beatTime) {
        trackTimer.restart();
    }
    
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
