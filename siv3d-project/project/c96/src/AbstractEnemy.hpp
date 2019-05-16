#ifndef AbstractEnemy_hpp
#define AbstractEnemy_hpp

#include <Siv3D.hpp>
#include "Task.hpp"


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
    
public:
    AbstractEnemy(Vec2 pos);
    virtual ~AbstractEnemy() = default;
    bool update() override;
    
protected:
    bool isInGameArea();
    void setCollisionSize(double r);
};

#endif /* AbstractEnemy_hpp */
