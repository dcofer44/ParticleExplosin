#ifndef SWARM_H
#define SWARM_H
#include "Particle.h"

class Swarm
{
    public:
        const static int NUM_PARTICLES = 5000;

        Swarm();

        inline const Particle * const getParticles() { return m_particles; }

        virtual ~Swarm();
    private:
        Particle *m_particles;
};

#endif // SWARM_H
