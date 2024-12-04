#include "Grid.h"
#include "Renderer.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Vérifier les arguments
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    // Initialisation
    const int cellSize = 10;
    Grid grid(80, 80);  // Taille par défaut
    try {
        grid.loadFromFile(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    Renderer renderer(grid.getCells().size(), grid.getCells()[0].size(), cellSize);

    // Boucle principale
    while (renderer.isOpen()) {
        renderer.handleEvents();
        grid.update();
        renderer.render(grid);
        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
