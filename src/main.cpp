#include "world.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    World world(screenWidth, screenHeight, 0.5f);

    // Add some souls
    world.addSoul(Soul(1, "Soul1", 0.8f, {(float)screenWidth/2 - 50, (float)screenHeight/2, 0}));
    world.addSoul(Soul(2, "Soul2", 0.2f, {(float)screenWidth/2 + 50, (float)screenHeight/2,.0f}));


    // Main game loop
    while (!WindowShouldClose()) {
        world.update();
        world.draw();
    }

    return 0;
}
