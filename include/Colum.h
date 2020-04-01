#ifndef COLUM_H
#define COLUM_H
#include <SFML/Graphics.hpp>

using namespace sf;


class Colum
{
    public:
    int width;
    int d;
    const int length=300;
    Colum(int swidth, int sd);
    int dp, wp=10;

    void DrawColum(RenderWindow& window);


};

#endif // COLUM_H
