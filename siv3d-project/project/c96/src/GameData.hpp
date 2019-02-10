//
//  SceneParameter.hpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/02/10.
//  Copyright © 2019 gkuth. All rights reserved.
//

#ifndef SceneParameter_hpp
#define SceneParameter_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>

struct GameData {
    String difficulity = U"";
};

using MyApp = SceneManager<String, GameData>;

#endif /* SceneParameter_hpp */
