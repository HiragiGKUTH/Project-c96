#ifndef AbstractEnemy_hpp
#define AbstractEnemy_hpp

#include <Siv3D.hpp>
#include "Task.hpp"


class AbstractEnemy : public Task {
protected:
    Vec2 pos;
    Vec2 vel;
    double speed;
    double ang;
    
public:
    AbstractEnemy(Vec2 pos);
    virtual ~AbstractEnemy() = default;
    bool update() override;
    
protected:
    bool isInGameArea();
};

#endif /* AbstractEnemy_hpp */
