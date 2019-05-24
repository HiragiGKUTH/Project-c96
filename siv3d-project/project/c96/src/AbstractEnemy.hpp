#ifndef AbstractEnemy_hpp
#define AbstractEnemy_hpp

#include <Siv3D.hpp>
#include "Task.hpp"
#include "BulletManager.hpp"


class AbstractEnemy : public Task {
protected:
    // essential for Enemy defination
    Vec2 pos;
    Vec2 vel;
    double speed;
    double ang;
    unsigned int cnt;
    
    double collisionRadius;
    Circle collision;
    
    BulletManager bulletManager;
    
    const unsigned int beginDurationFrame = 120;

public:
    AbstractEnemy(Vec2 pos);
    virtual ~AbstractEnemy() = default;
    bool update() override;
    
    Array<Circle*> getCollisions();
    
protected:
    bool isInGameArea();
    void setCollisionSize(double r);
    
    void move();
    void bullet();
};

#endif /* AbstractEnemy_hpp */
