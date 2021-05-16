#include <string>
#include <iostream>
#include "Creatures.h"



// Initialize to human, 10 strength, 10 hit points
Creature::Creature() {
    type = 0;           //human type
    strength = 10;      
    hitpoints = 10;
};

// Initialize creature to new type, strength, hit points
Creature::Creature(int newType, int newStrength, int newHit) {
    type = newType;
    strength = newStrength;
    hitpoints = newHit;
};


std::string Human::getSpecies() {
    return "Human";
}

std::string Elf::getSpecies() {
    return "Elf";
}

std::string Cyberdemon::getSpecies() {
    return "Cyberdemon";
}

std::string Balrog::getSpecies() {
    return "Balrog";
}


int Human::getDamage() {
    return getDamage();
}

int Elf::getDamage() {
    return getDamage();
}

int Cyberdemon::getDamage() {
    return getDamage();
}

int Balrog::getDamage() {
    return getDamage() * 2;
}





int Creature::getStrength() {
    return strength;
}

void Creature::setStrength(int newStrength) {
    strength = newStrength;
}


int Creature::getHitpoints() {
    return hitpoints;
}

void Creature::setHitpoints(int newHit) {
    hitpoints = newHit;
}








// Returns amount of damage this creature
// inflicts in one round of combat
std::string Creature::getSpecies(){

    switch (type) {
        case 0: return "Human";
        case 1: return "Cyberdemon";
        case 2: return "Balrog";
        case 3: return "Elf";
    }
    return "Unknown";
};



int Creature::getDamage() {
    int damage;

    // All creatures inflict damage, which is a
    // random number up to their strength
    damage = (rand() % strength) + 1;

    std::cout << getSpecies() << " attacks for " << damage << " points!" << std::endl;

    // Demons can inflict damage of 50 with a 5% chance
    if ((type = 2) || (type == 1)) {
        if ((rand( ) % 100) < 5) {
            damage = damage + 50;
            std::cout << "Demonic attack inflicts 50 " << " additional damage points!" << std::endl;
        }
    }

    // Elves inflict double magical damage with a 10% chance
    if(type == 3) {
        if ((rand( ) % 10)==0) {
            std::cout << "Magical attack inflicts " << damage <<
            " additional damage points!" << std::endl;
            damage = damage * 2;
        }
    }

    // Balrogs are so fast they get to attack twice
    if (type == 2) {
        int damage2 = (rand() % strength) + 1;

        std::cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << std::endl;

        damage = damage + damage2;
    }
    return damage;
};