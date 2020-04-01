#ifndef STICK_H
#define STICK_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Stick
{
    public:
        const int stick_width = 5;
        float stick_length=0;
        int d;
        // stt: 0 trạng thái đứng im, 1: trạng thái thay đổi độ cao;
        int stt=1;
        float angle=0;


        //Stick();
        Stick(float stick_length);


        void DrawStick(RenderWindow& window);
        void RotationStick();
};

#endif // STICK_H
