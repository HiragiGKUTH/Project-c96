#ifndef Select_hpp
#define Select_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameData.hpp"
#include "SelectionBox.hpp"


class Select : public MyApp::Scene {
private:
    Array<String> difficulty_names;
    Array<String> difficulty_descriptions;
    Array<SelectionBox> selection_boxes;
public:
    Select(const InitData &init);
    void update() override;
    void draw() const override;
};

#endif /* Select_hpp */
