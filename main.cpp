#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Colum.h"
#include "Stick.h"
#include <string>


using namespace std;
using namespace sf;


void PlayGame(RenderWindow& window)
{
    /// ud: trạng thái của que 1: đi lên, 0: đi xuống
    int ud=1;
    bool abool=false;

    SoundBuffer win, lose, fall;
    win.loadFromFile("victory.ogg");
    lose.loadFromFile("death.ogg");
    fall.loadFromFile("fall.ogg");
    Sound Win(win), Lose(lose), Fall(fall);
    /////////
    int rcout=1; ///đếm số lần chạy chương trình để tạo hiệu ứng đung đưa cho nhân vật ;
    /////////
    Font font;
    font.loadFromFile("stickhero.ttf");
    Text Score;
    Score.setFont(font);
    Score.setPosition(440,20);
    int score=0;

    Font pp;
    pp.loadFromFile("arial.ttf");
    Text Pp;
    Pp.setFont(pp);
    Pp.setPosition(270,300);
    Pp.setString("perfect!");

    Texture playbg_texture;
    playbg_texture.loadFromFile("bg4.jpg");
    Sprite playbg(playbg_texture);
    playbg.setScale(0.6,0.5);


    Texture stopb_texture;
    stopb_texture.loadFromFile("btn_home.png");
    Sprite stopb(stopb_texture);
    stopb.setPosition(20,20);

    ////////////
    float n=0; /// để di chuyển hero sang phải
    float k=0; /// để di chuyển hero rơi xuống
    vector <string> stay;
    for (int i=1; i<=5; i++){
        string a="hero/stay"+to_string(i)+".png";
        stay.push_back(a);
    }


    //}
    ////////////
    int wA=100;
    int dA=50;

    int wB=rand()%100 + 20;
    int dB= wA+ dA + 20 + (rand()%(600-wA-dA-20-wB - 20));

    int wC=rand()%100 + 20;
    int dC=600;


    Colum A(wA, dA);
    Colum B(wB, dB);
    Colum C(wC, dC);

    Stick stick(stick.stick_length);
    //////////////
    stick.d=150;

    while(window.isOpen() && abool==0)
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed) window.close();

        }

        int x = Mouse::getPosition(window).x;
        int y = Mouse::getPosition(window).y;

        window.clear();
        window.draw(playbg);
        window.draw(stopb);

        A.DrawColum( window);
        B.DrawColum( window);
        C.DrawColum( window);
        ////////
        ///hiệu ứng chuyển động bằng thay thế liên tiếp các ảnh
        rcout+=1;
        int m=(rcout/50)%5;
        Texture hero;
        hero.loadFromFile(stay[m]);
        Sprite hhero(hero);
        hhero.setScale(0.8,0.8);
        hhero.setPosition(100+n,554+k);
        window.draw(hhero);
        ////////
        //Stick
        window.draw(Score);
        Score.setString("SCORE: " + to_string(score));


        stick.DrawStick(window);
        if (Keyboard::isKeyPressed(Keyboard::Space) && stick.stt==1)
        {
            Fall.play();
            stick.stt=0;

        }
        else if (stick.stt==1)
        {

                if ( ud == 1  )  {
                        stick.stick_length+=0.2;
                        if (stick.stick_length>=550) ud=0;
                }
                else if ( ud == 0) {
                    stick.stick_length-=0.2;
                    if (stick.stick_length<=00) ud=1;
                }

        }
        else if (stick.stt==0)
        {
            if (stick.angle<90)
            {
             stick.angle+=0.1;
            }
            ///di chuyển tất cả các đối tượng sang trái
            else if (stick.angle<90.1){
                    bool a=false;
                    if (stick.stick_length<=(B.d+B.width-A.d-A.width) && stick.stick_length>=(B.d-A.d-A.width)){

                            if (stick.stick_length+stick.d<=(B.dp+B.wp) && stick.stick_length+stick.d>=(B.dp)){
                                    a=true;
                                    window.draw(Pp);
                                }
                            if (B.d<=150-B.width) {
                                A.width=B.width;
                                A.dp=B.dp;
                                A.d=B.d;
                                B.width=C.width;
                                B.dp=C.dp;
                                B.d=C.d;
                                C.width=rand()%100 + 20;
                                C.d=dC;
                                C.dp=dC+C.width/2-C.wp/2;
                                Win.play();
                                score+=1;
                                if (a==true) score++;



                                Score.setString("SCORE: "+ to_string(score));
                                //ud=1;
                                stick.stt=1;
                                stick.d=150;
                                stick.angle=0;
                                stick.stick_length=0;
                                ud=1;



                            }
                            else{
                                A.d-=1;
                                A.dp-=1;
                                B.d-=1;
                                B.dp-=1;
                                C.d-=1;
                                C.dp-=1;
                                stick.d-=1;
                            }


                    }
                    ///nhân vật rơi xuống, và stick gãy xoay xuống
                    else {
                        if(n<= stick.stick_length){
                            n+=1;
                        }
                        else {
                            stick.angle+=0.05;

                        }
                    }

            }
            else if(n>=stick.stick_length ){
                if (stick.angle<180.0) stick.angle+=1;
                k+=1;
                if (k>350)
                {
                    Lose.play();
                    abool=true;
                }
            }



        }



        if (Mouse::isButtonPressed(Mouse::Left) && x>=20 && x<=100 && y>=20 && y<=100 ){
            stick.stick_length=0;
            stick.stt =1;
            stick.angle=0;
            return;

        }
        window.display();
    }
    /// nút restart
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed) window.close();

        }
        window.clear();

        window.draw(playbg);

        Texture rs;
        rs.loadFromFile("uires_2.png");
        Sprite rrs(rs);
        rrs.setPosition(215,650);
        window.draw(rrs);

        Texture gover;
        gover.loadFromFile("gover.png");
        Sprite ggover(gover);
        ggover.setPosition(44,50);
        window.draw(ggover);

        Score.setCharacterSize(50);
        Score.setPosition(190,520);
        window.draw(Score);

        stopb.setPosition(315,650);
        window.draw(stopb);

        int x = Mouse::getPosition(window).x;
        int y = Mouse::getPosition(window).y;
        if (Mouse::isButtonPressed(Mouse::Left) && x>=215 && x<=295 && y>=650 && y<=730 ){
                return PlayGame(window);

        }
        if (Mouse::isButtonPressed(Mouse::Left) && x>=315 && x<=395 && y>=650 && y<=730 ){
            return;
        }
          window.display();
        }

}

int main()
{
    RenderWindow window(VideoMode(600,900),"Stick Hero",Style::Close);
    srand(time(NULL));

    //bg
    Texture bg_texture, a_texture, play_texture;
    bg_texture.loadFromFile("bg4.jpg");
    a_texture.loadFromFile("uires_1.png");
    play_texture.loadFromFile("btn_play.png");


    //khai bao
    Sprite sprite(bg_texture);
    Sprite a(a_texture);
    Sprite play(play_texture);

    sprite.setScale(0.6,0.5);
    a.setScale(0.6, 0.5);

    a.setPosition(77.4,100);
    play.setPosition(160,350);

    while(window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed) window.close();


        }
        window.clear();
        window.draw(sprite);
        window.draw(a);
        window.draw(play);
        window.display();
        int x = Mouse::getPosition(window).x;
        int y = Mouse::getPosition(window).y;

        if (Mouse::isButtonPressed(Mouse::Left) && x>=160 && x<=440 && y>=350 && y<=630 ){
            PlayGame(window);
        }
    }
}
