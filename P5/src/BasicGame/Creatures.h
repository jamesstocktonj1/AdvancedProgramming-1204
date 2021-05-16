#include <string>
#include <iostream>



class Creature {
private:
    int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
    int strength; // How much damage we can inflict
    int hitpoints; // How much damage we can sustain
    std::string getSpecies(); // Returns type of species

public:
    // Initialize to human, 10 strength, 10 hit points
    Creature();

    // Initialize creature to new type, strength, hit points
    Creature(int newType, int newStrength, int newHit);

    // Also add appropriate accessor and mutator functions
    // for type, strength, and hit points
    int getDamage();

    int getStrength();
    void setStrength(int newStrength);

    int getHitpoints();
    void setHitpoints(int newHit);
    
};




class Human : public Creature {

public:
    Human() : Creature() {};        //default type is human

    int getDamage();
    std::string getSpecies();
};


class Elf : public Creature {

public:
    Elf() : Creature(3, 10, 10) {};     //initialise elf

    int getDamage();
    std::string getSpecies();
};


class Demon : public Creature {

public:
    Demon(int newType) : Creature(newType, 10, 10) {};       //initialise with newType (either cyberdemon or balrog)

    int getDamage();
};




class Cyberdemon : public Demon {

public:
    Cyberdemon() : Demon(1) {};

    int getDamage();
    std::string getSpecies();
};

class Balrog : public Demon {

public:
    Balrog() : Demon(2) {};

    int getDamage();
    std::string getSpecies();
};