#include "ATarget.hpp"

ATarget::ATarget(){};
ATarget::ATarget(std::string const type): type(type){
    // std::cout << this->getType() <<": This looks like another boring day." << std::endl;
};

ATarget::~ATarget(){
    // std::cout << this->getType() <<": My job here is done!" << std::endl;
};

ATarget::ATarget(ATarget &copy){
    *this = copy;
};

ATarget& ATarget::operator=(ATarget & rhs){
    if (this != &rhs){
        this->type = rhs.getType();
    }
    return (*this);
};

const std::string & ATarget::getType() const{
    return (this->type);
};

void ATarget::getHitBySpell(ASpell& aspell){
    std::cout << this->getType() << " has been " << aspell.getEffects() << "!" << std::endl;
};