#include "SelectionBox.hpp"

SelectionBox::SelectionBox(String& text, Color box_color, double line_thickness) {
    this->text = text;
    this->box_color = box_color;
    this->line_thickness = line_thickness;
    this->text_font = FontAsset(U"SelectionBox");
    this->box = this->text_font(this->text).region();
}

void SelectionBox::draw() const {
    // mouse over to change color
    box.drawFrame(0.0, line_thickness, box.mouseOver() ? Palette::Red : box_color);
    text_font(text).draw(pos);
}


// setter
void SelectionBox::setPos(Vec2 pos) {
    // pos is Top Left position
    this->pos = pos;
    this->box.setPos(Arg::topLeft = pos);
}

void SelectionBox::setBoxColor(Color color) {
    this->box_color = color;
}

// getter
RectF SelectionBox::getRegion() const {
    return box;
}

String SelectionBox::getText() const {
    return text;
}
