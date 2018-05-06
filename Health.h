//
// Created by Johan on 2018/04/30.
//

#ifndef HEALTH_HEALTH_H
#define HEALTH_HEALTH_H

#include <iostream>
#include <map>

enum HealthType {
    Vitality = 0,
    Armour = 1,
    Shields = 2
};

struct HealthCondition {
    int maxValue;
    int minValue;
    int value;
};

class HealthValue {
private:
    int maxValue;
    int minValue;
    int value;
public:
    HealthValue(int minValue, int maxValue, int value);
    HealthCondition Condition();
};

class Health {
public:
    std::map<HealthType, HealthValue> HealthValues;

    Health();
    ~Health();

    friend std::ostream &operator<<(std::ostream &os, Health &health);

    HealthValue Add(HealthType key, int minValue, int maxValue, int value);
    HealthValue* HealthByType(HealthType key);
};


#endif //HEALTH_HEALTH_H
