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
    Circle collision;
    const double speed = 16.0;
    
    Array<std::shared_ptr<Shot>> shotList;
public:
    Player();
    virtual ~Player() = default;
    
    bool update() override;
    void draw() const override;
    
private:
    void move();
    void shot();
};

#endif /* Player_hpp */
