#ifndef Select_hpp
#define Select_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameData.hpp"
#include "SelectionBox.hpp"


class Select : public MyApp::Scene {
private:
    struct TrackInfo {
        String name;
        int difficulty;
        String musicPath;
        String scorePath;
        double bpm;
    };
    
    Array<TrackInfo> track_info;
    Array<SelectionBox> selection_boxes;
    double menu_theta;
public:
    Array<TrackInfo> loadTrackInfo();
    Select(const InitData &init);
    void update() override;
    void draw() const override;
};

#endif /* Select_hpp */
