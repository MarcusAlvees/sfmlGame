#include "Headers/DrawMap.hpp"
#include "Headers/Global.hpp"

DrawMap::DrawMap() {
    gridLength = 16;
    initialState();
    setUpTiles();
}

void DrawMap::initialState() {
    map_sketch.loadFromFile("Resources/testmap.png");    
}

void DrawMap::setUpTiles() {
    for (int y = 0; y < map_sketch.getSize().y; y++)
    {
        for (int x = 0; x < map_sketch.getSize().x; x++)
        {
            sf::Color pixel = map_sketch.getPixel(x, y);
            if(pixel.a == 255)
            {
                if(pixel == sf::Color(0, 0, 0, 255))
                {
                    tiles.push_back(new GameTile("Resources/brick.png", CELL_SIZE * x, CELL_SIZE * y, true, true));
                }
            }
            else {
                tiles.push_back(new GameTile(" ", CELL_SIZE * x, CELL_SIZE * y, false, false));
            }
        }
    }
}

void DrawMap::drawTiles(sf::RenderWindow& window) {
    for (int i = 0; i < tiles.size(); i++)
    {
        if(tiles[i]->needToDraw == true) {
            window.draw(tiles[i]->spr);
        }
    }
}