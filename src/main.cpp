#include <iostream>
#include "soul.h"

int main() {
    Soul mySoul(1, "MySoul", 0.75f);
    std::cout << "Soul '" << mySoul.getName() << "' created with light value: " << mySoul.getLight() << std::endl;
    return 0;
}
