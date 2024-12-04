#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>

class Grid {
private:
    int width;
    int height;
    std::vector<std::vector<int>> cells;

public:
    Grid(int width, int height);
    void loadFromFile(const std::string& filename);
    void initializeRandomly();
    void update();
    const std::vector<std::vector<int>>& getCells() const;
    int countAliveNeighbors(int x, int y) const;
};

#endif
