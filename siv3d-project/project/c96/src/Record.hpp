//
//  Record.hpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/08/09.
//  Copyright © 2019 gkuth. All rights reserved.
//

#ifndef Record_hpp
#define Record_hpp

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "GameData.hpp"
#include "GameDefine.hpp"

class Record : public MyApp::Scene {
private:
    Array<std::pair<double, GameDefine::ePlayerPos>> notes;
    Audio recordingAudio;
    Stopwatch recordingTimer;
    
private:
    void save();
public:
    Record(const InitData &init);
    void update();
    void draw() const;
};

#endif /* Record_hpp */
