#include<SDL2/SDL.h>
#include<CL/cl.hpp>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<ctime>

#include "Screen.h"
#include "Swarm.h"

using namespace std;
int main()
{
    srand(time(nullptr));

    vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);
    cl::Platform plat = platforms[0];

    string vendor = plat.getInfo<CL_PLATFORM_VENDOR>();
    string name = plat.getInfo<CL_PLATFORM_NAME>();
    string version = plat.getInfo<CL_PLATFORM_VERSION>();
    string profile = plat.getInfo<CL_PLATFORM_PROFILE>();
    string extensions = plat.getInfo<CL_PLATFORM_EXTENSIONS>();

    cout<<"Platform Vendor: "<<vendor<<"\n";
    cout<<"Platform Name: " <<name<<"\n";
    cout<<"Platform Version: " <<version<<"\n";
    cout<<"Platform Profile: "<<profile<<"\n";
    cout<<"Extensions: "<<extensions<<endl;

    Screen screen;

    if(!screen.init()) {//Initialize the Screen
        cout<< screen.getErrorMsg() << endl;
        return 1;
    }

    Swarm swarm;
    const Particle * const particles = swarm.getParticles();

    //Begin main loop
    while(true)
    {
        unsigned int  elapsed = SDL_GetTicks();//Get milliseconds since SDL_Init() was called

        //We use the trig functions as they only return values between -1 and 1
        //The values returned are "smoothed" by multipling the decimal values
        //1 is added to the result to constrain the result between 0 and 2
        //Multipling by 128 gets values between 0 and 256
        //A value of 256 is only possible if (elapsed * decimal) = PI / 2 for sin() or (elapsed * decimal) = PI for cos()
        //We store the result in a Uint8 to keep the values between 0 and 255
        Uint8 red = (1 + cos(elapsed * 0.0004)) * 128;
        Uint8 green = (1 + sin(elapsed * 0.0001)) * 128;
        Uint8 blue = (1 + sin(elapsed * 0.0006)) * 128;


        for(int i = 0; i < Swarm::NUM_PARTICLES; i++)
        {
            Particle part = particles[i];
            //Map the x, y coordinates of the particle to the screen
            int x = (part.m_x + 1) * (Screen::WIDTH / 2);
            int y = (part.m_y + 1) * (Screen::HEIGHT / 2);

            screen.setPixel(x, y, red, green, blue);
        }

        screen.update();//Update the screen

        if(!screen.processEvents()) {//Only looking for the Exit button clicked
            break;
        }
    }

    screen.close();

    return 0;
}
