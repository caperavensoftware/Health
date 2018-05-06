#include <iostream>
#include "Health.h"

int main() {
    Health h;

    std::cout << "Hello, World!" << std::endl;
    HealthValue * values = h.HealthByType(Vitality);

    if (values != nullptr) {
        std::cout << h << std::endl;
        //std::cout << values->maxValue << std::endl;
    }
    else
    {
        std::cout << "null";
    }
    return 0;
}