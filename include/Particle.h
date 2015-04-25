#ifndef PARTICLE_H
#define PARTICLE_H


struct Particle
{
        double m_x;
        double m_y;

        double m_xspeed;
        double m_yspeed;
    public:
        Particle();
        void update();
        virtual ~Particle();
    private:
        double generateValue();
};

#endif // PARTICLE_H
