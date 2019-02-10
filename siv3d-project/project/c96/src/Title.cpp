//
//  Title.cpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/02/09.
//  Copyright © 2019 gkuth. All rights reserved.
//

#include <Siv3D.hpp>
#include "Title.hpp"

#include "Define.hpp"
#include "GameInfo.hpp"

Title::Title(const InitData &init) : IScene(init) {
    // Title initialize
    this->title_string = GameInfo::Title;
    this->title_font = Font(GameInfo::TitleFontSize);
    this->title_pos = Vec2(Define::WindowSize/8);

    this->menu_strings = {
        GameInfo::MenuGameStart,
        GameInfo::MenuGameConfig,
        GameInfo::MenuGameCredit,
        GameInfo::MenuGameExit
    };
    this->menu_font = Font(GameInfo::TitleMenuFontSize);
    
    // menu position initialize
    {
        Vec2 offset = 5 * Define::WindowSize / 8;
        for (auto i : step(this->menu_strings.size())) {
            this->menu_poses.push_back(offset + Vec2(this->menu_font.fontSize()/2*i, this->menu_font.height()*i));
        }
    }
}

void Title::update() {
    
}

void Title::draw() const {
    // title draw
    title_font(title_string).draw(title_pos);
    
    // menu draw
    for (auto i : step(menu_strings.size())) {
        menu_font(menu_strings[i]).draw(menu_poses[i]);
    }
}
