#ifndef Game_hpp
#define Game_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include <memory>
#include "GameData.hpp"

#include "Board.hpp"
#include "Player.hpp"
#include "EnemyManager.hpp"


class Game : public MyApp::Scene {
private:
    Font dummy;
    std::shared_ptr<Board> board;
    std::shared_ptr<Player> player;
    std::shared_ptr<EnemyManager> enemyManager;
    
    Stopwatch gameTimer;
    Stopwatch trackTimer;
    
    const double beginTime = 3.0;
    
private:
    void collisionAll();
    
    void collisionEnemyToPlayer(Circle* pCol, Array<Circle*> eCols);
    void collisionPlayerToEnemy(Array<Circle*> pShotCols, Array<Circle*> eCols);
public:
    Game(const InitData &init);
    void update() override;
    void draw() const override;
};

#endif /* Game_hpp */
