#include "mote.h"

Mote::Mote(int id, float energy, Position position) : id(id), energy(energy), position(position) {
}

void Mote::move(float dx, float dy, float dz) {
    position.x += dx;
    position.y += dy;
    position.z += dz;
}

void Mote::collide(Mote& other) {
    // Combine energy
    this->energy += other.energy;
    // Lose a small percentage (e.g., 5%)
    this->energy *= 0.95f;
    // The other mote is consumed in the collision
    other.energy = 0;
}

void Mote::consume(float amount) {
    energy -= amount;
    if (energy < 0) {
        energy = 0;
    }
}

bool Mote::isAlive() const {
    return energy > 0;
}

int Mote::getId() const {
    return id;
}

float Mote::getEnergy() const {
    return energy;
}

Position Mote::getPosition() const {
    return position;
}
