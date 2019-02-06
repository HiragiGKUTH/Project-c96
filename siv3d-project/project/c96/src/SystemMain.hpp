//
//  SystemMain.hpp
//  c96
//
//  Created by 嶌岡柊也 on 2019/02/03.
//  Copyright © 2019 gkuth. All rights reserved.
//

#ifndef SystemMain_hpp
#define SystemMain_hpp

class SystemMain final {
public:
    SystemMain() = default;
    
    bool init();
    bool main();
    bool exit();
};

#endif /* SystemMain_hpp*/


