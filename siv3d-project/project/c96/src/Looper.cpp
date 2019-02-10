#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Looper.hpp"

#include "Title.hpp"
#include "Game.hpp"


Looper::Looper() {
    this->LoadAssets();
    manager.add<Title>(U"Title");
    manager.add<Game>(U"Game");
}

Looper::~Looper() {
    
}

bool Looper::loop() {
    if (KeyEscape.pressed()) {
        return false;
    }
    
    // loop initalize
    const auto transformer = ScalableWindow::CreateTransformer();
    
    //Debug Information
    Print << Profiler::FPS() << U" FPS";

    if (!manager.update()) {
        return false;
    }
    
    // loop finalize
    ClearPrint();
    ScalableWindow::DrawBlackBars();
    
    return true;
}

bool Looper::LoadAssets() {
    return true;
}
