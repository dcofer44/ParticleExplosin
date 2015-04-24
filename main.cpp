#include<iostream>
#include<cmath>
#include<SDL2/SDL.h>

#include"Screen.h"

using namespace std;
int main()
{
    Screen screen;

    if(!screen.init()) {//Initialize the Screen
        cout<< screen.getErrorMsg() << endl;
        return 1;
    }

    //Begin main loop
    while(true) {

        Uint32 elapsed = SDL_GetTicks();
        Uint8 red = (1 + cos(elapsed * 0.0005)) * 128;
        Uint8 green = (1 + sin(elapsed * 0.0006)) * 128;
        Uint8 blue = (1 + sin(elapsed * 0.0007)) * 128;


        for(int x = 0; x < Screen::WIDTH; x++) {
            for(int y = 0; y < Screen::HEIGHT; y++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }

        screen.update();//Update the screen

        if(!screen.processEvents()) {//Only looking for the Exit button clicked
            break;
        }
    }

    screen.close();

    return 0;
}
