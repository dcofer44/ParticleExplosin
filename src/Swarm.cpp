#include<SDL2/SDL.h>
#include<cmath>
#include "Swarm.h"


Swarm::Swarm()
{
    m_particles = new Particle[NUM_PARTICLES];
}

void Swarm::update(Screen &screen, int deltaTime)
{
    //We use the trig functions as they only return values between -1 and 1
    //The values returned are "smoothed" by multipling the decimal values
    //1 is added to the result to constrain the result between 0 and 2
    //Multipling by 128 gets values between 0 and 256
    //A value of 256 is only possible if (elapsed * decimal) = PI / 2 for sin() or (elapsed * decimal) = PI for cos()
    //We store the result in a Uint8 to keep the values between 0 and 255
    Uint8 red = (1 + cos(deltaTime * 0.0004)) * 128;
    Uint8 green = (1 + sin(deltaTime * 0.0001)) * 128;
    Uint8 blue = (1 + sin(deltaTime * 0.0006)) * 128;

    for(int i = 0; i < NUM_PARTICLES; i++)
    {
        Particle part = m_particles[i];
        //Map the x, y coordinates of the particle to the screen
        int x = (part.m_x + 1) * (Screen::WIDTH / 2);
        int y = (part.m_y + 1) * (Screen::HEIGHT / 2);

        screen.setPixel(x, y, red, green, blue);

        m_particles[i].update();
    }
}

Swarm::~Swarm()
{
    delete[] m_particles;
}
