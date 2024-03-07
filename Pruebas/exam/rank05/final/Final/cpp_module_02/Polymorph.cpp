#include "Polymorph.hpp"

Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter"){

};

// Polymorph::Polymorph(std::string const name, std::string const effects): name(name), effects(effects){
//     // std::cout << this->getName() << ": This looks like another boring day." << std::endl;
// };

// Polymorph::Polymorph(Polymorph const &copy){
//     *this = copy;
// };

// Polymorph & Polymorph::operator=(Polymorph const & rhs){
//     if(this != &rhs){
//         this->name = rhs.getName();
//         this->effects = rhs.getEffects();
//     }
//     return (*this);
// };

Polymorph::~Polymorph(){
    // std::cout << this->getName() << ": My job here is done!" << std::endl;

};

// std::string const & Polymorph::getName(void) const{
//     return(this->name);
// };

// std::string const & Polymorph::getEffects(void) const{
//     return(this->effects);
// };

// void Polymorph::setEffects(std::string const name){
//     this->effects = name;
// };

// void Polymorph::introduce() const{
//     std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getEffects() << "!" << std::endl;
// };

// void Polymorph::launch(ATarget const & atarget) const{
//     atarget.getHitBySpell(*this);
// };

Polymorph * Polymorph::clone() const{
    return(new Polymorph());
};
