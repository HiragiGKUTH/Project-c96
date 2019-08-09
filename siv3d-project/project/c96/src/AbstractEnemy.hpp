#ifndef AbstractEnemy_hpp
#define AbstractEnemy_hpp

#include <Siv3D.hpp>
#include "Task.hpp"
#include "BulletManager.hpp"
#include "GameDefine.hpp"


class AbstractEnemy : public Task {
protected:
    // essential for Enemy defination
    Vec2 pos;
    Vec2 vel;
    double arrivalDuration;
    double speed;
    double ang;
    Stopwatch timer;
    
    
    double collisionRadius;
    Circle collision;
    
    BulletManager bulletManager;
    
    Array<std::pair<double, GameDefine::ePlayerPos>> notesInfo;
    
public:
    AbstractEnemy(Vec2 pos, double exitAngle, Array<std::pair<double, GameDefine::ePlayerPos>> notesInfo, double arrivalDuration);
    virtual ~AbstractEnemy() = default;
    bool update() override;
    
    void hit();
    
    Circle* getCollision();
    
protected:
    bool isInGameArea();
    void setCollisionSize(double r);
    
    void move();
    void bullet();
};

#endif /* AbstractEnemy_hpp */
