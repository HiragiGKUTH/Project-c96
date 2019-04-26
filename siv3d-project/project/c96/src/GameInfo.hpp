#ifndef GameInfo_h
#define GameInfo_h

#include <Siv3D.hpp>

namespace GameInfo {
    // Generals
    const String Title = U"Project-c96";
    const String Version = U"Alpha-0.0.1";
    const ColorF FadeColor = ColorF(1.0, 1.0, 1.0);
    
    // Fonts
    const int32 TitleFontSize = 64;
    const int32 TitleMenuFontSize = 48;
    const int32 SelectionBoxFontSize = 48;
    
    // Texts
    const String MenuGameStart = U"StartGame!";
    const String MenuGameExit = U"ExitGame!";
    const String MenuGameConfig = U"Configuration!";
    const String MenuGameCredit = U"Credit!";
    
    // Save path
    const FilePath SaveFilePath = U"./save/a.gcsv";
    
    // Credits
    const Array<std::pair<String, Array<String>>> Credits {
        { U"Game Designer" ,{ U"Hiragi-GKUTH" }},
        { U"Programmer" ,{ U"Hiragi-GKUTH" }},
        { U"Game Art" ,{ U"Hiragi-GKUTH" }},
        { U"Game Musics" ,{ U"Hiragi-GKUTH" }},
    };
    
    //Difficulties
    const Array<String> Difficulty_names {
        U"Lunatic",
        U"Hard",
        U"Normal",
        U"Easy",
    };
    
    const Array<String> Difficulty_descriptions {
        U"遊ばないほうがいいと思うぜ！",
        U"相当弾幕STGに自身があると見た...",
        U"ふつうのひと",
        U"げーむしょしんしゃ",
    };
}


#endif /* GameInfo_h */
