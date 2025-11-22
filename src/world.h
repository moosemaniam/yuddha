#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "soul.h"
#include "mote.h"
#include "raylib.h"

class World {
private:
    int width;
    int height;
    std::vector<Soul> souls;
    std::vector<Mote> motes;
    float lightDarkBalance;
    float frequency;

    void updateLightDarkBalance();

public:
    World(int width, int height, float frequency);
    ~World();

    void addSoul(const Soul& soul);
    void addMote(const Mote& mote);

    void update();
    void draw();
};

#endif // WORLD_H
