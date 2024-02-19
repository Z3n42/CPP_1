#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed"){
};

// Fwoosh::Fwoosh(std::string const name, std::string const effects): name(name), effects(effects){
//     // std::cout << this->getName() <<": This looks like another boring day." << std::endl;
// };

Fwoosh::~Fwoosh(){
    // std::cout << this->getName() <<": My job here is done!" << std::endl;
};

// Fwoosh::Fwoosh(Fwoosh &copy){
//     *this = copy;
// };

// Fwoosh& Fwoosh::operator=(Fwoosh & rhs){
//     if (this != &rhs){
//         this->name = rhs.getName();
//         this->effects = rhs.getEffects();
//     }
//     return (*this);
// };

// const std::string & Fwoosh::getName() const{
//     return (this->name);
// };

// const std::string & Fwoosh::getEffects() const{
//     return (this->effects);
// };

// void Fwoosh::launch(ATarget & const atarget){
//     atarget.getHitBySpell(*this);
// };

Fwoosh* Fwoosh::clone() const{
    return(new Fwoosh());
};