#ifndef Enemy_hpp
#define Enemy_hpp

#include <Siv3D.hpp>
#include "AbstractEnemy.hpp"


class NormalEnemy : public AbstractEnemy {
private:
    void move();
    
public:
    NormalEnemy(Vec2 pos, double speed, double ang);
    virtual ~NormalEnemy() = default;
    void draw() const override;
};

#endif /* Enemy_hpp */
