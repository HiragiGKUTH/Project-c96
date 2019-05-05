#ifndef Enemy_hpp
#define Enemy_hpp

#include <Siv3D.hpp>
#include "AbstractEnemy.hpp"


class Enemy : public AbstractEnemy {
private:
    void move();
    
public:
    Enemy(Vec2 pos, double speed, double ang);
    virtual ~Enemy() = default;
    void draw() const override;
};

#endif /* Enemy_hpp */
