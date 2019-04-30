#ifndef Task_hpp
#define Task_hpp

class Task {
public:
    Task() = default;
    virtual ~Task() = default;
    virtual bool update() = 0;
    virtual void draw() const = 0;
};

#endif /* Task_hpp */
