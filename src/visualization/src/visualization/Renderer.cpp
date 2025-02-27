bool Renderer::loadTextures() {
    // Create a simple surface directly with a solid color to avoid SDL_MapRGB issues
    surface = SDL_CreateSurface(20, 10, SDL_PIXELFORMAT_RGBA8888);
    if (!surface) {
        DebugLogger::log("Failed to create surface: " + std::string(SDL_GetError()), DebugLogger::LogLevel::ERROR);
        return false;
    }

    // Fill with black color using a simpler approach
    // Create a color value manually
    Uint32 blackColor = 0x000000FF; // RGBA format: black with full alpha

    // Fill the entire surface with this color
    SDL_FillSurfaceRect(surface, NULL, blackColor);

    carTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    surface = nullptr;

    if (!carTexture) {
        DebugLogger::log("Failed to create car texture: " + std::string(SDL_GetError()), DebugLogger::LogLevel::ERROR);
        return false;
    }

    return true;
} 