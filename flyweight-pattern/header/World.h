//
// Created by tkhle on 15.04.2024.
//

#ifndef GAME_PROGRAMMING_PATTERNS_WORLD_H
#define GAME_PROGRAMMING_PATTERNS_WORLD_H

#include <array>
#include "Terrain.h"

constexpr int WIDTH = 1024;
constexpr int HEIGHT = 768;

class World {
private:
    Terrain grassTerrain;
    Terrain hillTerrain;
    Terrain riverTerrain;

    std::shared_ptr<Terrain> grassPtr{ std::make_shared<Terrain>(grassTerrain) };
    std::shared_ptr<Terrain> hillPtr{ std::make_shared<Terrain>(hillTerrain) };
    std::shared_ptr<Terrain> riverPtr{ std::make_shared<Terrain>(riverTerrain) };

    // Although we are using now more safe containers, our code got >10x slower. One would have to check what is more important
    std::array<std::array<std::shared_ptr<Terrain>, WIDTH>, HEIGHT> tiles;
public:
    World() :
            grassTerrain(1, false, GRASS),
            hillTerrain(3, false, HILL),
            riverTerrain(2, true, RIVER) {

        for (auto &row: tiles) {
            for (auto &tile: row) {
                tile = grassPtr;
            }
        }
    }

    void setTile(int x, int y, Texture texture) {
        switch (texture) {
            case GRASS:
                tiles[y][x] = grassPtr;
                break;
            case HILL:
                tiles[y][x] = hillPtr;
                break;
            case RIVER:
                tiles[y][x] = riverPtr;
        }
    }

    const Terrain &getTile(int x, int y) const {
        return *tiles[y][x];
    }
};

#endif //GAME_PROGRAMMING_PATTERNS_WORLD_H
