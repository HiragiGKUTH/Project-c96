#ifndef Game_hpp
#define Game_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include <memory>
#include "GameData.hpp"

#include "Player.hpp"
#include "EnemyManager.hpp"


class Game : public MyApp::Scene {
private:
    Font dummy;
    std::shared_ptr<Player> player;
    std::shared_ptr<EnemyManager> enemyManager;
public:
    Game(const InitData &init);
    void update() override;
    void draw() const override;
};

#endif /* Game_hpp */
