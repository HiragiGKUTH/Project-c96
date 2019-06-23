#ifndef Shot_hpp
#define Shot_hpp

#include <Siv3D.hpp>
#include "Task.hpp"

// class "Shot" is player's
class Shot : public Task {
private:
    Vec2 pos;
    Vec2 vel;
    double ang;
    Color color;
    Circle collision;
    
public:
    Shot(Vec2 pos, double speed, double ang);
    virtual ~Shot() = default;
    bool update() override;
    void draw() const override;
    
    Circle* getCollision();
    
private:
    void move();
    bool isInGameArea();
};

#endif /* Shot_hpp */
