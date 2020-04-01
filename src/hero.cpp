#include "hero.h"
#include <SFML/Graphics.hpp>
#include <string>


hero::hero(string mode)
{
    a="hero/"+mode+to_string(n)+".png";

}

hero::~hero()
{
    //dtor
}
