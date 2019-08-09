#ifndef Board_hpp
#define Board_hpp

#include <Siv3D.hpp>
#include "Task.hpp"
#include "GameDefine.hpp"

class Board : public Task {
private:
    const double r = 32.0;
    Array<Circle> baseCircles;
    Effect effect;
    bool isBeating;
    Array<std::pair<double, GameDefine::ePlayerPos>> notes;
    double musicLength;
    Stopwatch timer;
    double judgeMargin;
    int score;
public:
    Board(Array<std::pair<double, GameDefine::ePlayerPos>> notes, double musicLength);
    virtual ~Board() = default;
    
    bool update() override;
    void draw() const override;
    
    void beginTimer();
    
    void keyJudge();
};

#endif /* Board_hpp */
