//
//  Looper.cpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/02/06.
//  Copyright © 2019 gkuth. All rights reserved.
//

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
