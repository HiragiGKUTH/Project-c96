#ifndef BulletManager_hpp
#define BulletManager_hpp

#include "Siv3D.hpp"
#include <memory>

#include "Bullet.hpp"

// Enemy has this Manager
class BulletManager : public Task {
private:
    Array<std::shared_ptr<Bullet>> bulletList;
    const unsigned int MAX_BULLETS = 10000;
    
public:
    BulletManager();
    
    bool add(Vec2 pos, double speed, double ang);
    
    unsigned long getBulletNum();
    std::shared_ptr<Bullet> at(int index);
    
    bool update() override;
    void draw() const override;
};

#endif /* BulletManager_hpp */
