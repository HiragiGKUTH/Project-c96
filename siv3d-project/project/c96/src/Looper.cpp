#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameInfo.hpp"
#include "Looper.hpp"

#include "Title.hpp"
#include "Game.hpp"


Looper::Looper() {
    this->LoadAssets();
    manager.add<Title>(U"Title");
    manager.add<Game>(U"Game");
    manager.setFadeColor(GameInfo::FadeColor);
}

Looper::~Looper() {
    
}

bool Looper::loop() {
    if (KeyEscape.pressed()) {
        return false;
    }
    
    // loop initalize
    const auto transformer = ScalableWindow::CreateTransformer();
    ClearPrint();
    
    //Debug Information
    Print << Profiler::FPS() << U" FPS";

    if (!manager.update()) {
        return false;
    }
    
    // loop finalize
    ScalableWindow::DrawBlackBars();
    
    return true;
}

bool Looper::LoadAssets() {
    return true;
}
