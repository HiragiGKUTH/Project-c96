#ifndef Board_hpp
#define Board_hpp

#include <Siv3D.hpp>
#include "Task.hpp"

class Board : public Task {
public:
    Board();
    virtual ~Board() = default;
    
    bool update() override;
    void draw() const override;
    
};

#endif /* Board_hpp */
