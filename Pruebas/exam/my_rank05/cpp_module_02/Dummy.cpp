#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy"){};
// Dummy::Dummy(std::string const type, std::string const effects): type(type){
//     // std::cout << this->getType() <<": This looks like another boring day." << std::endl;
// };

Dummy::~Dummy(){
    // std::cout << this->getType() <<": My job here is done!" << std::endl;
};

Dummy* Dummy::clone() const{
    return(new Dummy);
};

// Dummy::Dummy(Dummy &copy){
//     *this = copy;
// };

// Dummy& Dummy::operator=(Dummy & rhs){
//     if (this != &rhs){
//         this->type = rhs.getType();
//     }
//     return (*this);
// };

// const std::string & Dummy::getType() const{
//     return (this->type);
// };

// void Dummy::getHitBySpell(ASpell& aspell){
//     std::cout << this->getType() << " has been " << aspell.getEffects() << "!" << std::endl;
// };