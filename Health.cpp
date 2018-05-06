//
// Created by Johan on 2018/04/30.
//

#include "Health.h"

/**
 * Health Value constructor
 * @param minValue: minimum value, default 0
 * @param maxValue: maximum value: default 100
 * @param value: health value, default maxValue
 */
HealthValue::HealthValue(int minValue = 0, int maxValue = 100, int value = 100) {
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

/**
 * Health Constructor
 */
Health::Health() {
    Add(Vitality, 0, 100, 100);
}

Health::~Health() {

}

HealthValue Health::Add(HealthType key, int minValue, int maxValue, int value) {
    HealthValue v = HealthValue(minValue, maxValue, value);
    HealthValues[key] = v;
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

