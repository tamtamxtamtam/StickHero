#include "Stick.h"
#include <SFML/Graphics.hpp>


Stick::Stick(float slength)
{
    stick_length=slength;
}


void Stick::DrawStick(RenderWindow& window)
{
    RectangleShape stick_rectangle(Vector2f(-stick_width, -stick_length));
    stick_rectangle.setFillColor(Color(0,0,0));
    stick_rectangle.setPosition(d, 600);
    if (stt==0)
    {
        stick_rectangle.setRotation( + angle);
    }
    window.draw(stick_rectangle);
}

void Stick::RotationStick()
{

}

