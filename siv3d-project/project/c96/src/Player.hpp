#ifndef Player_hpp
#define Player_hpp

#include <Siv3D.hpp>
#include "Task.hpp"
#include "Define.hpp"

class Player : public Task {
private:
    Vec2 pos;
    Vec2 vel;
    Circle collision;
    const double speed = 16.0;
public:
    Player();
    virtual ~Player() = default;
    
    bool update() override;
    void draw() const override;
    
private:
    void move();
};

#endif /* Player_hpp */
