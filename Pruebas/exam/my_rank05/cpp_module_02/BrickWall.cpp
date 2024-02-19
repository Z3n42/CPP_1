#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick Wall"){};
// BrickWall::BrickWall(std::string const type, std::string const effects): type(type){
//     // std::cout << this->getType() <<": This looks like another boring day." << std::endl;
// };

BrickWall::~BrickWall(){
    // std::cout << this->getType() <<": My job here is done!" << std::endl;
};

BrickWall* BrickWall::clone() const{
    return(new BrickWall);
};

// BrickWall::BrickWall(BrickWall &copy){
//     *this = copy;
// };

// BrickWall& BrickWall::operator=(BrickWall & rhs){
//     if (this != &rhs){
//         this->type = rhs.getType();
//     }
//     return (*this);
// };

// const std::string & BrickWall::getType() const{
//     return (this->type);
// };

// void BrickWall::getHitBySpell(ASpell& aspell){
//     std::cout << this->getType() << " has been " << aspell.getEffects() << "!" << std::endl;
// };