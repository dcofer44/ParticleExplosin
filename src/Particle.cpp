#include "Particle.h"
#include<cstdlib>

Particle::Particle()
{
    //Initialize the x and y coordinates to a value between -1 and 1
    m_x = (2.0 * rand()) / RAND_MAX - 1;
    m_y = (2.0 * rand()) / RAND_MAX - 1;
}

Particle::~Particle()
{
    //dtor
}
