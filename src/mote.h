#ifndef MOTE_H
#define MOTE_H

struct Position {
    float x, y, z;
};

class Mote {
private:
    int id;
    float energy;
    Position position;

public:
    Mote(int id, float energy, Position position);

    void move(float dx, float dy, float dz);
    void collide(Mote& other);
    void consume(float amount);
    bool isAlive() const;

    int getId() const;
    float getEnergy() const;
    Position getPosition() const;
};

#endif // MOTE_H
