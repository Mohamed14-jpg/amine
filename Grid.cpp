#include "Grid.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

Grid::Grid(int width, int height) : width(width), height(height) {
    cells = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));
}

void Grid::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file!");
    }
    file >> width >> height;
    cells = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file >> cells[x][y];
        }
    }
    file.close();
}

void Grid::initializeRandomly() {
    std::srand(std::time(0));
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            cells[x][y] = std::rand() % 2;
        }
    }
}

void Grid::update() {
    std::vector<std::vector<int>> newCells = cells;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            int aliveNeighbors = countAliveNeighbors(x, y);
            if (cells[x][y] == 1) {
                newCells[x][y] = (aliveNeighbors == 2 || aliveNeighbors == 3) ? 1 : 0;
            } else {
                newCells[x][y] = (aliveNeighbors == 3) ? 1 : 0;
            }
        }
    }
    cells = newCells;
}

int Grid::countAliveNeighbors(int x, int y) const {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                count += cells[nx][ny];
            }
        }
    }
    return count;
}

const std::vector<std::vector<int>>& Grid::getCells() const {
    return cells;
}
