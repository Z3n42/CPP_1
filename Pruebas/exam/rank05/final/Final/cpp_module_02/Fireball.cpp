#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp"){

};

// Fireball::Fireball(std::string const name, std::string const effects): name(name), effects(effects){
//     // std::cout << this->getName() << ": This looks like another boring day." << std::endl;
// };

// Fireball::Fireball(Fireball const &copy){
//     *this = copy;
// };

// Fireball & Fireball::operator=(Fireball const & rhs){
//     if(this != &rhs){
//         this->name = rhs.getName();
//         this->effects = rhs.getEffects();
//     }
//     return (*this);
// };

Fireball::~Fireball(){
    // std::cout << this->getName() << ": My job here is done!" << std::endl;

};

// std::string const & Fireball::getName(void) const{
//     return(this->name);
// };

// std::string const & Fireball::getEffects(void) const{
//     return(this->effects);
// };

// void Fireball::setEffects(std::string const name){
//     this->effects = name;
// };

// void Fireball::introduce() const{
//     std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getEffects() << "!" << std::endl;
// };

// void Fireball::launch(ATarget const & atarget) const{
//     atarget.getHitBySpell(*this);
// };

Fireball * Fireball::clone() const{
    return(new Fireball());
};
