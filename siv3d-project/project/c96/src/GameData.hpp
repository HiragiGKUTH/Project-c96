#ifndef SceneParameter_hpp
#define SceneParameter_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>

struct TrackInfo {
    String difficulty;
    String trackName;
    String musicScorePath;
    double bpm;
};

struct GameData {
    TrackInfo trackInfo;
};

using MyApp = SceneManager<String, GameData>;

#endif /* SceneParameter_hpp */
