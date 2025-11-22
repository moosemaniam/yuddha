#include "world.h"

World::World(int width, int height, float frequency)
    : width(width), height(height), frequency(frequency), lightDarkBalance(0.5f) {
    InitWindow(width, height, "Yuddha - World");
    SetTargetFPS(60);
}

World::~World() {
    CloseWindow();
}

void World::addSoul(const Soul& soul) {
    souls.push_back(soul);
}

void World::addMote(const Mote& mote) {
    motes.push_back(mote);
}

void World::updateLightDarkBalance() {
    if (souls.empty()) {
        lightDarkBalance = 0.5f;
        return;
    }

    float totalLight = 0.0f;
    for (const auto& soul : souls) {
        totalLight += soul.getLight();
    }
    lightDarkBalance = totalLight / souls.size();
}

void World::update() {
    updateLightDarkBalance();

    // Mote creation logic that slows down as the number of motes approaches MOTES_MAX
    if (motes.size() < MOTES_MAX) {
        float scalingFactor = (float)(MOTES_MAX - motes.size()) / MOTES_MAX;
        if (GetRandomValue(0, 1000) < frequency * 100 * scalingFactor) {
            Position pos = {
                (float)GetRandomValue(0, width),
                (float)GetRandomValue(0, height),
                0.0f
            };
            Mote newMote(GetRandomValue(1000, 9999), 100.0f, pos);
            addMote(newMote);
        }
    }

    // Update motes (e.g., simple movement)
    for (auto& mote : motes) {
        mote.move(GetRandomValue(-1, 1), GetRandomValue(-1, 1), 0);
    }
}

void World::draw() {
    BeginDrawing();

    // Clear background with a color based on light/dark balance
    Color bgColor = {
        (unsigned char)(255 * (1.0f - lightDarkBalance)), // Red component for dark
        (unsigned char)(255 * lightDarkBalance),         // Green component for light
        128,                                              // Blue component
        255
    };
    ClearBackground(bgColor);

    // Draw souls (as circles)
    for (const auto& soul : souls) {
        Position pos = soul.getPosition();
        DrawCircle(pos.x, pos.y, 10, WHITE);
    }

    // Draw motes (as smaller circles)
    for (const auto& mote : motes) {
        Position pos = mote.getPosition();
        DrawCircle(pos.x, pos.y, 5, YELLOW);
    }

    EndDrawing();
}
