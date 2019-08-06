#ifndef SelectionBox_hpp
#define SelectionBox_hpp

#include <Siv3D.hpp>

class SelectionBox {
private:
    Font text_font;
    int id;
    String text;
    Color box_color;
    double line_thickness;
    RectF box;
    Vec2 pos;
public:
    SelectionBox(int id, String& text, Color box_color = Palette::White, double line_thickness = 2.0);
    void draw() const;
    
    // setter
    void setPos(Vec2 pos);
    void setBoxColor(Color color);
    
    // getter
    RectF getRegion() const ;
    String getText() const ;
    int getId() const ;
};

#endif /* SelectionBox_hpp */
