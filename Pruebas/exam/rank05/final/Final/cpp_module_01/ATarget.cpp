#include "ATarget.hpp"

ATarget::ATarget(){

};

ATarget::ATarget(std::string const type): type(type){
    // std::cout << this->getType() << ": This looks like another boring day." << std::endl;
};

ATarget::ATarget(ATarget const &copy){
    *this = copy;
};

ATarget & ATarget::operator=(ATarget const & rhs){
    if(this != &rhs){
        this->type = rhs.getType();
        // this->effects = rhs.getEffects();
    }
    return (*this);
};

ATarget::~ATarget(){
    // std::cout << this->getType() << ": My job here is done!" << std::endl;

};

std::string const & ATarget::getType(void) const{
    return(this->type);
};

// std::string const & ATarget::getEffects(void) const{
//     return(this->effects);
// };

// void ATarget::setEffects(std::string const type){
//     this->effects = type;
// };

// void ATarget::introduce() const{
//     std::cout << this->getType() << ": I am " << this->getType() << ", " << this->getEffects() << "!" << std::endl;
// };

void ATarget::getHitBySpell(ASpell const & aspell) const{
    // if (aspell)
    std::cout << this->getType() << " has been " << aspell.getEffects() << "!" << std::endl;
};