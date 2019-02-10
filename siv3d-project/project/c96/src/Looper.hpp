#ifndef Looper_hpp
#define Looper_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameData.hpp"

class Looper final {
private:
    MyApp manager;
    bool LoadAssets();
public:
    Looper();
    ~Looper();
    
    bool loop();
};

#endif /* Looper_hpp */
