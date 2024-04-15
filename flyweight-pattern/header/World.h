//
// Created by tkhle on 15.04.2024.
//

#ifndef GAME_PROGRAMMING_PATTERNS_WORLD_H
#define GAME_PROGRAMMING_PATTERNS_WORLD_H

#include "Terrain.h"

constexpr int WIDTH = 1024;
constexpr int HEIGHT = 768;

class World {
private:
    Terrain grassTerrain;
    Terrain hillTerrain;
    Terrain riverTerrain;

    // Although not the safest way, it is still the fastest
    Terrain* tiles[HEIGHT][WIDTH];
public:
    World():
        grassTerrain(1, false, GRASS),
        hillTerrain(3, false, HILL),
        riverTerrain(2, true, RIVER)
        {}

    void setTile(int x, int y, Texture texture) {
        switch (texture) {
            case GRASS:
                tiles[y][x] = &grassTerrain;
                break;
            case HILL:
                tiles[y][x] = &hillTerrain;
                break;
            case RIVER:
                tiles[y][x] = &riverTerrain;
        }
    }

    const Terrain& getTile(int x, int y) const {
        return *tiles[y][x];
    }
};

#endif //GAME_PROGRAMMING_PATTERNS_WORLD_H
