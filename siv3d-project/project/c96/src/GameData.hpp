#ifndef SceneParameter_hpp
#define SceneParameter_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>

struct TrackInfo {
    int difficulty;
    String name;
    String musicPath;
    String scorePath;
    double bpm;
    int denom;
    int frac;
};

struct GameData {
    TrackInfo trackInfo;
};

using MyApp = SceneManager<String, GameData>;

#endif /* SceneParameter_hpp */
