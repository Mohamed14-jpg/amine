#include "Renderer.h"

Renderer::Renderer(int gridWidth, int gridHeight, int cellSize)
    : cellSize(cellSize), window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life") {}

void Renderer::render(const Grid& grid) {
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    const auto& cells = grid.getCells();
    for (int x = 0; x < cells.size(); ++x) {
        for (int y = 0; y < cells[x].size(); ++y) {
            if (cells[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

bool Renderer::isOpen() const {
    return window.isOpen();
}

void Renderer::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}


// test git