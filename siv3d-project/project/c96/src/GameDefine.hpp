//
//  GameDefine.hpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/06/23.
//  Copyright © 2019 gkuth. All rights reserved.
//

#ifndef GameDefine_h
#define GameDefine_h

#include <Siv3D.hpp>

namespace GameDefine {
    const Rect GameArea = Rect(48, 32, 1500, 1044);
    
    auto getVec2 = [] (int i) {
        const int num = 7;
        const int offsetY = GameArea.y + GameArea.h - 128;
        const int offsetX = GameArea.x;
        return Vec2(offsetX + (GameArea.w/num)*i, offsetY);
    };
    const Array<Vec2> PlayerPoses = {
        getVec2(1),
        getVec2(2),
        getVec2(3),
        getVec2(4),
        getVec2(5),
        getVec2(6)
    };
    
    enum ePlayerPos {
        S,
        D,
        F,
        J,
        K,
        L,
    };
}


#endif /* GameDefine_h */
