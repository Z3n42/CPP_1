#include "Warlock.hpp"

Warlock::Warlock(){

};

Warlock::Warlock(std::string const name, std::string const title): name(name), title(title){
    std::cout << this->getName() << ": This looks like another boring day." << std::endl;
};

Warlock::Warlock(Warlock const &copy){
    *this = copy;
};

Warlock & Warlock::operator=(Warlock const & rhs){
    if(this != &rhs){
        this->name = rhs.getName();
        this->title = rhs.getTitle();
    }
    return (*this);
};

Warlock::~Warlock(){
    std::cout << this->getName() << ": My job here is done!" << std::endl;

};

std::string const & Warlock::getName(void) const{
    return(this->name);
};

std::string const & Warlock::getTitle(void) const{
    return(this->title);
};

void Warlock::setTitle(std::string const name){
    this->title = name;
};

void Warlock::introduce() const{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
};
