#ifndef SWARM_H
#define SWARM_H

#include "Screen.h"
#include "Particle.h"
class Swarm
{
    public:
        const static int NUM_PARTICLES = 1000;

        Swarm();

        inline const Particle * const getParticles() { return m_particles; };

        void update(Screen &screen, int deltaTime);

        virtual ~Swarm();
    private:
        Particle *m_particles;
};

#endif // SWARM_H
