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
    double beatTime;
public:
    EnemyManager(double bpm);
    ~EnemyManager() = default;
    bool update() override;
    void draw() const override;
    
    void beginTimer();
    
    Array<Circle*> getCollisions();
    Array<Circle*> getBulletCollisions();
};

#endif /* EnemyManager_hpp */
