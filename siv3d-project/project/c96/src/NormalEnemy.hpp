#ifndef Enemy_hpp
#define Enemy_hpp

#include <Siv3D.hpp>
#include "AbstractEnemy.hpp"
#include "GameDefine.hpp"


class NormalEnemy : public AbstractEnemy {
private:
    void move();
    
public:
    NormalEnemy(Vec2 pos, double exitAngle, Array<std::pair<double, GameDefine::ePlayerPos>> notesInfo, double arrivalDuration);
    virtual ~NormalEnemy() = default;
    void draw() const override;
};

#endif /* Enemy_hpp */
