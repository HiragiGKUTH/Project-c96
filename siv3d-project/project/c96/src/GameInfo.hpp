//
//  GameInfo.hpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/02/10.
//  Copyright © 2019 gkuth. All rights reserved.
//

#ifndef GameInfo_h
#define GameInfo_h

#include <Siv3D.hpp>

namespace GameInfo {
    const String Title = U"Project-c96";
    const String Version = U"Alpha-0.0.1";
    const ColorF FadeColor = ColorF(1.0, 1.0, 1.0);
    
    const int32 TitleFontSize = 48;
    const int32 TitleMenuFontSize = 32;
    
    const String MenuGameStart = U"StartGame!";
    const String MenuGameExit = U"ExitGame!";
    const String MenuGameConfig = U"Configuration!";
    const String MenuGameCredit = U"Credit!";
    
    const FilePath SaveFilePath = U"./save/a.gcsv";
    
    const Array<std::pair<String, Array<String>>> Credits {
        { U"Game Designer" ,{ U"Hiragi-GKUTH" }},
        { U"Programmer" ,{ U"Hiragi-GKUTH" }},
        { U"Game Art" ,{ U"Hiragi-GKUTH" }},
        { U"Game Musics" ,{ U"Hiragi-GKUTH" }},
    };
}


#endif /* GameInfo_h */
