#ifndef Bullet_hpp
#define Bullet_hpp

#include <Siv3D.hpp>
#include "Task.hpp"

class Bullet : public Task {
private:
    Vec2 pos;
    Vec2 vel;
    Vec2 startPos;
    Vec2 targetPos;
    double speed;
    double ang;
    double arriveTime;
    double currentTime;
    unsigned int cnt;
    int moveKind;
    Circle collision;
    
public:
    Bullet(Vec2 pos, Vec2 targetPos, double arriveTime, int moveKind);
    
    bool update() override;
    void draw() const override;
};

#endif /* Bullet_hpp */
