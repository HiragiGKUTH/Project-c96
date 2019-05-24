#ifndef EnemyManager_hpp
#define EnemyManager_hpp

#include <Siv3D.hpp>
#include <memory>
#include "AbstractEnemy.hpp"
#include "Task.hpp"


class EnemyManager : public Task {
private:
    Array<std::shared_ptr<AbstractEnemy>> enemyList;
    
public:
    EnemyManager();
    ~EnemyManager() = default;
    bool update() override;
    void draw() const override;
    
    Array<Circle*> getEnemyCollisions();
};

#endif /* EnemyManager_hpp */
