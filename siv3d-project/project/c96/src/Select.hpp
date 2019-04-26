#ifndef Select_hpp
#define Select_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameData.hpp"


class Select : public MyApp::Scene {
private:
    Font dummy;
public:
    Select(const InitData &init);
    void update() override;
    void draw() const override;
};

#endif /* Select_hpp */
