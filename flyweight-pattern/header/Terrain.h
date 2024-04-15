//
// Created by tkhle on 15.04.2024.
//

#ifndef GAME_PROGRAMMING_PATTERNS_TERRAIN_H
#define GAME_PROGRAMMING_PATTERNS_TERRAIN_H

#include <string>
#include <utility>

enum Texture {
    GRASS,
    HILL,
    RIVER
};

class Terrain {
private:
    int moveCost;
    bool isWater_;
    Texture texture;
public:
    Terrain(int moveCost, bool isWater, Texture texture): moveCost(moveCost), isWater_(isWater), texture(texture) {}

    int getMoveCost() const {
        return moveCost;
    }

    bool isWater() const {
        return isWater_;
    }

    const Texture getTexture() const {
        return texture;
    }
};

#endif //GAME_PROGRAMMING_PATTERNS_TERRAIN_H
