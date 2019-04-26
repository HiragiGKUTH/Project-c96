#ifndef SceneParameter_hpp
#define SceneParameter_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>

struct GameData {
    String difficulty = U"";
};

using MyApp = SceneManager<String, GameData>;

#endif /* SceneParameter_hpp */
