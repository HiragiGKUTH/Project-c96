#include <cmath>
#include "EnemyManager.hpp"
#include "NormalEnemy.hpp"
#include "GameDefine.hpp"
#include "GameInfo.hpp"


EnemyManager::EnemyManager(double bpm, int frac, int denom, Array<std::pair<double, GameDefine::ePlayerPos>> notes) {
    this->trackTimer.reset();
    
    this->beatTime = 60.0 / bpm;
    this->beatCount = 0;
    this->frac = frac;
    this->denom = denom;
    this->notes = notes;
}

void EnemyManager::beginTimer() {
    trackTimer.start();
    beatCount++;
    enemyList.push_back(std::make_shared<NormalEnemy>(GameDefine::GameArea.center()-Vec2(0, 400), ToDegrees(90), notes, beatTime*2));
}

bool EnemyManager::update() {
    // beat update
    beatUpdate();
    
    // beat counting
    if (isBeatingFrame) {
        beatCount++;
    }
    
    
    // add Enemy on timing
   /* if (isBeatingFrame && beatCount%2 == 0) {
        Array<std::pair<double, GameDefine::ePlayerPos>> part;
        for (auto& note : notes) {
            if (trackTimer.sF() <= note.first && note.first < trackTimer.sF() + beatTime * 2) {
                part.push_back(note);
            }
        }
        
        enemyList.push_back(std::make_shared<NormalEnemy>(GameDefine::GameArea.center(), ToDegrees(90), part, beatTime*2));
    }*/
    
    
    
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
