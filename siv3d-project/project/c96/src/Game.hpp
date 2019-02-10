#ifndef Game_hpp
#define Game_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameData.hpp"


class Game : public MyApp::Scene {
private:
    
public:
    Game(const InitData &init);
    void update() override;
    void draw() const override;
};

#endif /* Game_hpp */
