#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy"){

};

// Dummy::Dummy(std::string const name, std::string const effects): name(name), effects(effects){
//     // std::cout << this->getName() << ": This looks like another boring day." << std::endl;
// };

// Dummy::Dummy(Dummy const &copy){
//     *this = copy;
// };

// Dummy & Dummy::operator=(Dummy const & rhs){
//     if(this != &rhs){
//         this->name = rhs.getName();
//         this->effects = rhs.getEffects();
//     }
//     return (*this);
// };

Dummy::~Dummy(){
    // std::cout << this->getName() << ": My job here is done!" << std::endl;

};

// std::string const & Dummy::getName(void) const{
//     return(this->name);
// };

// std::string const & Dummy::getEffects(void) const{
//     return(this->effects);
// };

// void Dummy::setEffects(std::string const name){
//     this->effects = name;
// };

// void Dummy::introduce() const{
//     std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getEffects() << "!" << std::endl;
// };

// void Dummy::launch(ATarget const & atarget) const{
//     atarget.getHitBySpell(*this);
// };

Dummy * Dummy::clone() const{
    return(new Dummy());
};
