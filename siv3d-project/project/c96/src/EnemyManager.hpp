#ifndef EnemyManager_hpp
#define EnemyManager_hpp

#include <Siv3D.hpp>
#include <memory>
#include "AbstractEnemy.hpp"
#include "Task.hpp"
#include "GameDefine.hpp"


class EnemyManager : public Task {
private:
    Array<std::shared_ptr<AbstractEnemy>> enemyList;
    Stopwatch trackTimer;
    int beatCount;
    double beatTime;
    int frac;
    int denom;
    Array<std::pair<double, GameDefine::ePlayerPos>> notes;
    
    double nowTime;
    double privTime;
    bool isBeatingFrame;
public:
    EnemyManager(double bpm, int frac, int denom, Array<std::pair<double, GameDefine::ePlayerPos>> notes);
    ~EnemyManager() = default;
    bool update() override;
    void draw() const override;
    
    void beginTimer();
    
    Array<Circle*> getCollisions();
    Array<Circle*> getBulletCollisions();
    
private:
    void beatUpdate();
};

#endif /* EnemyManager_hpp */
