//
// Created by Johan on 2018/04/30.
//

#include "Health.h"

HealthValue::HealthValue(unsigned int minValue, unsigned int maxValue, unsigned int value) {
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->value = value;
}

HealthCondition HealthValue::Condition() {
    HealthCondition condition;
    condition.value = value;
    condition.maxValue = maxValue;
    condition.minValue = minValue;

    return condition;
}

HealthValue::~HealthValue() {
    std::cout << "destroying HealthValue" << std::endl;
}

/**
 * Health Constructor
 */
Health::Health() {
    Add(Vitality, 0, 100, 100);
}

Health::~Health() {
    std::cout << "destroying Health" << std::endl;
}

HealthValue Health::Add(HealthType healthType, unsigned int minValue, unsigned int maxValue, unsigned int value) {
    HealthValue v = HealthValue(minValue, maxValue, value);
    HealthValues[healthType] = v;
    return v;
}

HealthValue* Health::HealthByType(HealthType healthType) {
    auto it = HealthValues.find(healthType);

    if (it != HealthValues.end())
    {
        return &it->second;
    }

    return nullptr;
}

std::ostream &operator<<(std::ostream &os, Health &health) {
    auto values = health.HealthByType(Vitality)->Condition();

    os << "min: " << values.minValue << " - max: " << values.maxValue << " - value: " << values.value;
    return os;
}

