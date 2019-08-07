#include <cmath>
#include "EnemyManager.hpp"
#include "NormalEnemy.hpp"
#include "GameDefine.hpp"


EnemyManager::EnemyManager(double bpm, int frac, int denom) {
    this->trackTimer.reset();
    
    this->beatTime = 60.0 / bpm;
    this->beatCount = 0;
    this->frac = frac;
    this->denom = denom;
}

void EnemyManager::beginTimer() {
    trackTimer.start();
    beatCount++;
}

bool EnemyManager::update() {
    // beat counting
    if (onBeatingFrame()) {
        beatCount++;
    }
    
    
    // add Enemy on timing
    
    
    
    
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
    Print << U"beat " << beatCount;
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

bool EnemyManager::onBeatingFrame() {
    privTime = nowTime;
    nowTime = std::fmod(trackTimer.sF(), beatTime);
    
    return privTime > nowTime;
}
