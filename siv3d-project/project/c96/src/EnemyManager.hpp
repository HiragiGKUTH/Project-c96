#ifndef EnemyManager_hpp
#define EnemyManager_hpp

#include <Siv3D.hpp>
#include <memory>
#include "AbstractEnemy.hpp"
#include "Task.hpp"


class EnemyManager : public Task {
private:
    Array<std::shared_ptr<AbstractEnemy>> enemyList;
    Stopwatch trackTimer;
    int beatCount;
    double beatTime;
    int frac;
    int denom;
    
    double nowTime;
    double privTime;
public:
    EnemyManager(double bpm, int frac, int denom);
    ~EnemyManager() = default;
    bool update() override;
    void draw() const override;
    
    void beginTimer();
    
    Array<Circle*> getCollisions();
    Array<Circle*> getBulletCollisions();
    
private:
    bool onBeatingFrame();
};

#endif /* EnemyManager_hpp */
