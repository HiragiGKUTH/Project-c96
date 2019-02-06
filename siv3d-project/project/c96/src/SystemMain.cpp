//
//  SystemMain.cpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/02/03.
//  Copyright © 2019 gkuth. All rights reserved.
//

#include <Siv3D.hpp>

#include "SystemMain.hpp"
#include "Define.hpp"
#include "Looper.hpp"

bool SystemMain::init() {
    Window::SetTitle(U"Project-c96")
    Window::Resize(Define::WINDOW_W, Define::WINDOW_H);
    
}


bool SystemMain::main() {
    Looper looper;
    
    while(System::Update()) {
        if (looper.loop()) {
            break;
        }
    }
}

bool SystemMain::exit() {
    
}
