#include "Colum.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Colum::Colum(int swidth, int sd)
{
    width=swidth;
    d=sd;
    dp=d+width/2-wp/2;


}

void Colum::DrawColum(RenderWindow& window)
{
    RectangleShape rectangle(Vector2f(width, length));
    rectangle.setFillColor(Color(0,0,0));
    rectangle.setPosition(d, 900-length);
    window.draw(rectangle);

    RectangleShape pp(Vector2f(wp, wp));
    pp.setFillColor(Color(255, 36, 0));
    pp.setPosition(dp, 900-length);
    window.draw(pp);
}
