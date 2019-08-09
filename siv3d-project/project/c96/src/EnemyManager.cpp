#include <cmath>
#include "EnemyManager.hpp"
#include "NormalEnemy.hpp"
#include "GameDefine.hpp"
#include "GameInfo.hpp"


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
    // beat update
    beatUpdate();
    
    // beat counting
    if (isBeatingFrame) {
        beatCount++;
    }
    
    
    // add Enemy on timing
    if (isBeatingFrame) {
        Array<std::pair<double, GameDefine::ePlayerPos>> notes;
        notes.push_back({beatTime, static_cast<GameDefine::ePlayerPos>(Random(0,5))});
        notes.push_back({beatTime, static_cast<GameDefine::ePlayerPos>(Random(0,5))});
        enemyList.push_back(std::make_shared<NormalEnemy>(GameDefine::GameArea.center(), Random(Math::TwoPi), notes, beatTime));
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
    return enemyBulletCollisions;
}

void EnemyManager::beatUpdate() {
    privTime = nowTime;
    nowTime = std::fmod(trackTimer.sF(), beatTime);
    
    if (privTime > nowTime) {
        isBeatingFrame = true;
        return;
    }
    isBeatingFrame = false;
}
