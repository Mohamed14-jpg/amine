#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

class Renderer {
private:
    int cellSize;
    sf::RenderWindow window;

public:
    Renderer(int gridWidth, int gridHeight, int cellSize);
    void render(const Grid& grid);
    bool isOpen() const;
    void handleEvents();
};

#endif
