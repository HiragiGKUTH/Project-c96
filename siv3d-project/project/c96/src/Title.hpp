//
//  Title.hpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/02/09.
//  Copyright © 2019 gkuth. All rights reserved.
//

#ifndef Title_hpp
#define Title_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameData.hpp"


class Title : public MyApp::Scene {
private:
    String title_string;
    Font title_font;
    Vec2 title_pos;
    
    Array<String> menu_strings;
    Font menu_font;
    Array<Vec2> menu_poses;

public:
    Title(const InitData &init);
    void update() override;
    void draw() const override;
};

#endif /* Title_hpp */
