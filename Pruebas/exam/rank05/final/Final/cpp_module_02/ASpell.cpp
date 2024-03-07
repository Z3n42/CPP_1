#include "ASpell.hpp"

ASpell::ASpell(){

};

ASpell::ASpell(std::string const name, std::string const effects): name(name), effects(effects){
    // std::cout << this->getName() << ": This looks like another boring day." << std::endl;
};

ASpell::ASpell(ASpell const &copy){
    *this = copy;
};

ASpell & ASpell::operator=(ASpell const & rhs){
    if(this != &rhs){
        this->name = rhs.getName();
        this->effects = rhs.getEffects();
    }
    return (*this);
};

ASpell::~ASpell(){
    // std::cout << this->getName() << ": My job here is done!" << std::endl;

};

std::string const & ASpell::getName(void) const{
    return(this->name);
};

std::string const & ASpell::getEffects(void) const{
    return(this->effects);
};

// void ASpell::setEffects(std::string const name){
//     this->effects = name;
// };

// void ASpell::introduce() const{
//     std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getEffects() << "!" << std::endl;
// };

void ASpell::launch(ATarget const & atarget) const{
    atarget.getHitBySpell(*this);
};
