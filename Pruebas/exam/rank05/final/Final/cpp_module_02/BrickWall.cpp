#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick Wall"){

};

// BrickWall::BrickWall(std::string const name, std::string const effects): name(name), effects(effects){
//     // std::cout << this->getName() << ": This looks like another boring day." << std::endl;
// };

// BrickWall::BrickWall(BrickWall const &copy){
//     *this = copy;
// };

// BrickWall & BrickWall::operator=(BrickWall const & rhs){
//     if(this != &rhs){
//         this->name = rhs.getName();
//         this->effects = rhs.getEffects();
//     }
//     return (*this);
// };

BrickWall::~BrickWall(){
    // std::cout << this->getName() << ": My job here is done!" << std::endl;

};

// std::string const & BrickWall::getName(void) const{
//     return(this->name);
// };

// std::string const & BrickWall::getEffects(void) const{
//     return(this->effects);
// };

// void BrickWall::setEffects(std::string const name){
//     this->effects = name;
// };

// void BrickWall::introduce() const{
//     std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getEffects() << "!" << std::endl;
// };

// void BrickWall::launch(ATarget const & atarget) const{
//     atarget.getHitBySpell(*this);
// };

BrickWall * BrickWall::clone() const{
    return(new BrickWall());
};
