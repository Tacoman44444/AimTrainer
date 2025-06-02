#pragma once
#include "SDL2/SDL.h"

class GameObject;
class IComponent {
public:
    virtual void HandleInput(SDL_Event& e) = 0;
    virtual void Update() = 0;
    virtual ~IComponent() = default;
};