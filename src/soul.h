#ifndef SOUL_H
#define SOUL_H

#include <string>
#include <vector>
#include <map>
#include "mote.h" // For Position

class Soul {
private:
    int id;
    std::string name;
    float light; // 0.0 for darkness, 1.0 for light
    Position position;
    std::vector<std::string> motivations;
    std::map<int, std::string> relationships; // Using ID to represent other souls
    std::vector<std::string> drawbacks;

public:
    Soul(int id, const std::string& name, float light, Position position);

    void addMotivation(const std::string& motivation);
    void addRelationship(int soulId, const std::string& relationship);
    void addDrawback(const std::string& drawback);

    // New methods based on design/soul.md
    void persuade(Soul& otherSoul);
    void eliminate(Soul& otherSoul);
    void adjustLight(float amount);


    const std::vector<std::string>& getMotivations() const;
    const std::map<int, std::string>& getRelationships() const;
    const std::vector<std::string>& getDrawbacks() const;
    int getId() const;
    const std::string& getName() const;
    float getLight() const;
    Position getPosition() const;
};

#endif // SOUL_H
