#include "Screen.h"

Screen::Screen(): m_window(NULL),
    m_renderer(NULL), m_texture(NULL),
    m_pixels(NULL), errorStr(""){}

bool Screen::init()
{
    //Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        return errorOccurred();
    }
    //Create the window
    m_window = SDL_CreateWindow("Particle Explosion",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if(!m_window) {
        return errorOccurred();
    }

    //Create the renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(!m_renderer) {
        return errorOccurred();
    }

    //Create the texture
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ARGB8888,
                                            SDL_TEXTUREACCESS_STATIC,
                                            WIDTH, HEIGHT);
    if(!m_texture) {
        return errorOccurred();
    }

    //Create the pixel array
    m_pixels = new Uint32[Screen::NUM_PIXELS];

    memset(m_pixels, 0, NUM_PIXELS * sizeof(Uint32));//Change all pixel values to black

    return true;
}

void Screen::update()
{
    SDL_UpdateTexture(m_texture, NULL, m_pixels, WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
    /*if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) //Check if pixel is off the screen
        return*/
    Uint32 pixel = (0xFF << 24) | (red << 16) | (green << 8) | (blue);
    m_pixels[y * WIDTH + x] = pixel;
}

bool Screen::processEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type)
        {
        case SDL_QUIT: //Exit button was pressed
            return false;
            break;
        }
    }
    return true;
}

bool Screen::close()
{
    delete[] m_pixels;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return true;
}

std::string Screen::getErrorMsg()
{
    return errorStr;
}

bool Screen::errorOccurred()
{
    errorStr = SDL_GetError();
    return false;
}

Screen::~Screen()
{
    //dtor
}
