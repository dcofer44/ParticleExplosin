#ifndef SCREEN_H
#define SCREEN_H

#include<SDL2/SDL.h>
#include<string>

class Screen
{
    public:
        const static int WIDTH = 800;
        const static int HEIGHT = 600;
        const static int NUM_PIXELS = WIDTH * HEIGHT;

        Screen();

        bool init();
        void update();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        bool processEvents();
        void close();
        void clear();

        std::string getErrorMsg();

        virtual ~Screen();

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
        Uint32* m_pixels;
        std::string errorStr;

        bool errorOccurred();
};

#endif // SCREEN_H
