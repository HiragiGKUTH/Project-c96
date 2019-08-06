#ifndef Player_hpp
#define Player_hpp

#include <Siv3D.hpp>
#include <memory>
#include "Task.hpp"
#include "Shot.hpp"
#include "Define.hpp"


class Player : public Task {
private:
    Vec2 pos;
    Vec2 vel;
    Vec2 targetPos;
    Circle collision;
    Color color;
    const double speed = 16.0;
    Array<std::shared_ptr<Shot>> shotList;
    int cnt;
    
public:
    Player();
    virtual ~Player() = default;
    bool update() override;
    void draw() const override;
    
    Circle* getCollision();
    Array<Circle*> getShotCollisions();
    void hit();
    
private:
    void move();
    void shot();
};

#endif /* Player_hpp */
