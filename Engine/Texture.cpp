#include "Texture.h"
#include "Renderer.h" 
#include <SDL.h> 
#include <SDL_image.h> 

namespace defender
{
    Texture::~Texture()
    {
        // !! if texture not null SDL_DestroyTexture 
        if (m_texture)
        {
            SDL_DestroyTexture(m_texture);
        }
    }

    bool Texture::Create(Renderer& renderer, const std::string& filename)
    {
        // load surface 
        SDL_Surface* surface = IMG_Load(filename.c_str()); 

        // create texture 
        // !! call SDL_CreateTextureFromSurface passing in renderer and surface
        // !! the first parameter takes in the m_renderer from renderer 

        SDL_CreateTextureFromSurface(renderer, surface);
        m_texture = // 
        // !! call SDL_FreeSurface with surface as the parameter 
        // !! no need to keep surface after texture is created
        SDL_FreeSurface(surface);

        return true;
    }

    defender::Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);

        return Vector2 point.x, Vector2 point.y;
    }
}
