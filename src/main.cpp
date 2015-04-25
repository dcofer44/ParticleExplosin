#include<SDL2/SDL.h>
#include<CL/cl.hpp>
#include<iostream>
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

    //Begin main loop
    while(true)
    {
        int  deltaTime = SDL_GetTicks();//Get milliseconds since SDL_Init() was called

        screen.clear();

        swarm.update(screen, deltaTime);//Update all the particles
        screen.update();//Update the screen

        if(!screen.processEvents()) {//Only looking for the Exit button clicked
            break;
        }
    }

    screen.close();

    return 0;
}
