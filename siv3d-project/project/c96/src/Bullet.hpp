#ifndef Bullet_hpp
#define Bullet_hpp

#include <Siv3D.hpp>
#include "Task.hpp"

class Bullet : public Task {
private:
    Vec2 pos;
    Vec2 vel;
    double speed;
    double ang;
    unsigned int cnt;
    Circle collision;
    
public:
    Bullet(Vec2 pos, double speed, double ang);
    
    bool update() override;
    void draw() const override;
    
    void setAngle(double ang);
    void setSpeed(double speed);
    
    void activateGravity(double strength, double direction);
};

#endif /* Bullet_hpp */
