#include <Siv3D.hpp>
#include "Title.hpp"

#include "Define.hpp"
#include "GameInfo.hpp"

Title::Title(const InitData &init) : IScene(init) {
    // Title initialize
    this->title_string = GameInfo::Title;
    this->title_font = Font(GameInfo::TitleFontSize);
    this->title_pos = Vec2(Define::WindowSize/8);

    // Set menu texts
    this->menu_strings_base = {
        GameInfo::MenuGameStart,
        GameInfo::MenuGameConfig,
        GameInfo::MenuGameCredit,
        GameInfo::MenuGameExit
    };
    
    this->menu_strings = this->menu_strings_base;
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
    // menu update
    for (auto i : step(menu_strings.size())) {
        // Text shuffle when mouse over
        if (System::FrameCount()%5 == 0) {
            if (menu_font(menu_strings[i]).region(menu_poses[i]).mouseOver()) {
                menu_strings[i].shuffle();
            } else {
                menu_strings[i] = menu_strings_base[i];
            }
        }
        
        // change scene
        if (menu_font(menu_strings[i]).region(menu_poses[i]).leftClicked()) {
            switch (i) {
                case 0:
                    changeScene(U"Game");
                    break;
                case 3:
                    System::Exit();
                    break;
                default:
                    Print << U"Not implemented yet";
            }
        }
    }
}

void Title::draw() const {
    // title draw
    title_font(title_string).draw(title_pos);
    
    // menu draw
    for (auto i : step(menu_strings.size())) {
        menu_font(menu_strings[i]).draw(menu_poses[i]);
    }
}
