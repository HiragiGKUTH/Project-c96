//
//  baseEffect.hpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/08/09.
//  Copyright © 2019 gkuth. All rights reserved.
//

#ifndef baseEffect_hpp
#define baseEffect_hpp

#include <Siv3D.hpp>

struct baseEffect : IEffect {
    static constexpr double life = 0.5;
    static constexpr double blur = 4.0;
    
    Vec2 pos;
    Circle circle;
    double r;
    
    baseEffect(Vec2 pos, double r) {
        this->pos = pos;
        this->r = r;
    }
    
    bool update(double t) {
        t /= life;
        
        r++;
        
        circle.setPos(pos);
        circle.r = r;
        
        circle.drawFrame(0.0, 3.0 - t);
        circle.drawShadow(Vec2(0,0), blur, 0);
        
        return t < 1.0;
    }
    
};

#endif /* baseEffect_hpp */
