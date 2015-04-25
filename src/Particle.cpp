#include "Particle.h"
#include<cstdlib>

Particle::Particle(): m_x(0), m_y(0)
{
    m_xspeed = 0.001 * generateValue();
    m_yspeed = 0.001 * generateValue();
}

void Particle::update()
{
    m_x += m_xspeed;
    m_y += m_yspeed;

    if(m_x <= -1 || m_x >= 1)
        m_xspeed = -m_xspeed;
    if(m_y <= -1 || m_y >= 1)
        m_yspeed = -m_yspeed;
}

/**
 * Generates a value between -1 and 1
 */
double Particle::generateValue()
{
    return (2.0 * rand()) / RAND_MAX - 1;
}

Particle::~Particle()
{
    //dtor
}
