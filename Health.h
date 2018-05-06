//
// Created by Johan on 2018/04/30.
//

#ifndef HEALTH_HEALTH_H
#define HEALTH_HEALTH_H

#include <iostream>
#include <map>

/**
 * What are the health types that you can determine a sprites health from
 */
enum HealthType {
    Vitality = 0,
    Armour = 1,
    Shields = 2
};

/**
 * Data structure that gives you a idea on what a given health type's actual health condition is
 */
struct HealthCondition {
    unsigned int maxValue;
    unsigned int minValue;
    unsigned int value;
};

/**
 * This class manages a health type. It deals with common features such as:
 * 1. Adding Health
 * 2. Removing Health
 * 3. Managing buffs
 */
class HealthValue {
private:
    unsigned int maxValue;
    unsigned int minValue;
    unsigned int value;
public:
    /**
     * Constructor
     * @param minValue: default 0;
     * @param maxValue: default 100;
     * @param value: default 100;
     */
    HealthValue(unsigned int minValue = 0, unsigned int maxValue = 100, unsigned int value = 100);

    ~HealthValue();

    /**
     * What is this current healths condition like
     * @return: HealthCondition
     */
    HealthCondition Condition();
};

class Health {
private:
    /**
     * Map that stores the current health types
     * This object will initialize with a health type Vitality
     */
    std::map<HealthType, HealthValue> HealthValues;

public:
    /**
     * Basic constructor creating a vitality health type for further use
     */
    Health();

    /**
     * Basic destructor
     */
    ~Health();

    /**
     * Operator overload for debugging and printing purposes;
     * @param os
     * @param health
     * @return
     */
    friend std::ostream &operator<<(std::ostream &os, Health &health);

    /**
     * Add a health type.
     * By default vitality would have already been added so this is used when you want to add Armour or Shields
     * @param healthType
     * @param minValue
     * @param maxValue
     * @param value
     * @return: Returns HealthValue
     */
    HealthValue Add(HealthType healthType, unsigned int minValue, unsigned int maxValue, unsigned int value);

    /**
     * Find a health type if it exists
     * @param healthType
     * @return: A pointer to the health type if it exists or nullptr if it does not
     */
    HealthValue* HealthByType(HealthType healthType);
};


#endif //HEALTH_HEALTH_H
