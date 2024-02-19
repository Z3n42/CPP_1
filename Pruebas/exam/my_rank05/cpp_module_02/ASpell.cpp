#include "ASpell.hpp"

ASpell::ASpell(){};
ASpell::ASpell(std::string const name, std::string const effects): name(name), effects(effects){
    // std::cout << this->getName() <<": This looks like another boring day." << std::endl;
};

ASpell::~ASpell(){
    // std::cout << this->getName() <<": My job here is done!" << std::endl;
};

ASpell::ASpell(ASpell &copy){
    *this = copy;
};

ASpell& ASpell::operator=(ASpell & rhs){
    if (this != &rhs){
        this->name = rhs.getName();
        this->effects = rhs.getEffects();
    }
    return (*this);
};

const std::string & ASpell::getName() const{
    return (this->name);
};

const std::string & ASpell::getEffects() const{
    return (this->effects);
};

void ASpell::launch(ATarget & atarget){
    atarget.getHitBySpell(*this);
};