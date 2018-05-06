#include <iostream>
#include "Health.h"

int main() {
    Health h;
    std::cout << "Health System Initialized" << std::endl;

    h.Add(Vitality, 0, 10, 10);

    HealthValue * values = h.HealthByType(Vitality);

    if (values != nullptr) {
        std::cout << h << std::endl;
    }
    else
    {
        std::cout << "null";
    }
    return 0;
}