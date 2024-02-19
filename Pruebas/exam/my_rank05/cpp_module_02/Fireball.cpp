#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp"){
};

// Fireball::Fireball(std::string const name, std::string const effects): name(name), effects(effects){
//     // std::cout << this->getName() <<": This looks like another boring day." << std::endl;
// };

Fireball::~Fireball(){
    // std::cout << this->getName() <<": My job here is done!" << std::endl;
};

// Fireball::Fireball(Fireball &copy){
//     *this = copy;
// };

// Fireball& Fireball::operator=(Fireball & rhs){
//     if (this != &rhs){
//         this->name = rhs.getName();
//         this->effects = rhs.getEffects();
//     }
//     return (*this);
// };

// const std::string & Fireball::getName() const{
//     return (this->name);
// };

// const std::string & Fireball::getEffects() const{
//     return (this->effects);
// };

// void Fireball::launch(ATarget & const atarget){
//     atarget.getHitBySpell(*this);
// };

Fireball* Fireball::clone() const{
    return(new Fireball());
};