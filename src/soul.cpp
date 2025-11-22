#include "soul.h"
#include <cmath> // For fabs

Soul::Soul(int id, const std::string& name, float light, Position position) : id(id), name(name), light(light), position(position) {
    if (this->light < 0.0f) this->light = 0.0f;
    if (this->light > 1.0f) this->light = 1.0f;
}

void Soul::addMotivation(const std::string& motivation) {
    motivations.push_back(motivation);
}

void Soul::addRelationship(int soulId, const std::string& relationship) {
    relationships[soulId] = relationship;
}

void Soul::addDrawback(const std::string& drawback) {
    drawbacks.push_back(drawback);
}

void Soul::persuade(Soul& otherSoul) {
    // Persuading brings the other soul's light value closer to this one's.
    // The effectiveness of persuasion could depend on many factors,
    // for now, a simple adjustment.
    float lightDifference = this->light - otherSoul.getLight();
    otherSoul.adjustLight(lightDifference * 0.1f); // Small persuasion effect
}

void Soul::eliminate(Soul& otherSoul) {
    // Eliminating another soul has a price, pushing this soul's light towards the center (0.5).
    // This represents a "negative outcome" on the soul's alignment.
    float adjustment = (0.5f - this->light) * 0.2f; // Significant effect
    this->adjustLight(adjustment);
    // The other soul should be marked as eliminated from the world, but that's outside this class's responsibility.
}

void Soul::adjustLight(float amount) {
    this->light += amount;
    if (this->light < 0.0f) this->light = 0.0f;
    if (this->light > 1.0f) this->light = 1.0f;
}


const std::vector<std::string>& Soul::getMotivations() const {
    return motivations;
}

const std::map<int, std::string>& Soul::getRelationships() const {
    return relationships;
}

const std::vector<std::string>& Soul::getDrawbacks() const {
    return drawbacks;
}

int Soul::getId() const {
    return id;
}

const std::string& Soul::getName() const {
    return name;
}

float Soul::getLight() const {
    return light;
}

Position Soul::getPosition() const {
    return position;
}
