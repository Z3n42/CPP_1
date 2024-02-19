#include "Polymorph.hpp"

Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter"){
};

// Polymorph::Polymorph(std::string const name, std::string const effects): name(name), effects(effects){
//     // std::cout << this->getName() <<": This looks like another boring day." << std::endl;
// };

Polymorph::~Polymorph(){
    // std::cout << this->getName() <<": My job here is done!" << std::endl;
};

// Polymorph::Polymorph(Polymorph &copy){
//     *this = copy;
// };

// Polymorph& Polymorph::operator=(Polymorph & rhs){
//     if (this != &rhs){
//         this->name = rhs.getName();
//         this->effects = rhs.getEffects();
//     }
//     return (*this);
// };

// const std::string & Polymorph::getName() const{
//     return (this->name);
// };

// const std::string & Polymorph::getEffects() const{
//     return (this->effects);
// };

// void Polymorph::launch(ATarget & const atarget){
//     atarget.getHitBySpell(*this);
// };

Polymorph* Polymorph::clone() const{
    return(new Polymorph());
};