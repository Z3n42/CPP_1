#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed"){

};

// Fwoosh::Fwoosh(std::string const name, std::string const effects): name(name), effects(effects){
//     // std::cout << this->getName() << ": This looks like another boring day." << std::endl;
// };

// Fwoosh::Fwoosh(Fwoosh const &copy){
//     *this = copy;
// };

// Fwoosh & Fwoosh::operator=(Fwoosh const & rhs){
//     if(this != &rhs){
//         this->name = rhs.getName();
//         this->effects = rhs.getEffects();
//     }
//     return (*this);
// };

Fwoosh::~Fwoosh(){
    // std::cout << this->getName() << ": My job here is done!" << std::endl;

};

// std::string const & Fwoosh::getName(void) const{
//     return(this->name);
// };

// std::string const & Fwoosh::getEffects(void) const{
//     return(this->effects);
// };

// void Fwoosh::setEffects(std::string const name){
//     this->effects = name;
// };

// void Fwoosh::introduce() const{
//     std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getEffects() << "!" << std::endl;
// };

// void Fwoosh::launch(ATarget const & atarget) const{
//     atarget.getHitBySpell(*this);
// };

Fwoosh * Fwoosh::clone() const{
    return(new Fwoosh());
};
