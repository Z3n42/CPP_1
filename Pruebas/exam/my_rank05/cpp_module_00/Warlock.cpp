#include "Warlock.hpp"

Warlock::Warlock(){};
Warlock::Warlock(std::string const name, std::string const title): name(name), title(title){
    std::cout << this->getName() <<": This looks like another boring day." << std::endl;
};

Warlock::~Warlock(){
    std::cout << this->getName() <<": My job here is done!" << std::endl;
};

Warlock::Warlock(Warlock &copy){
    *this = copy;
};

Warlock& Warlock::operator=(Warlock & rhs){
    if (this != &rhs){
        this->name = rhs.getName();
        this->title = rhs.getTitle();
    }
    return (*this);
};

const std::string & Warlock::getName() const{
    return (this->name);
};

const std::string & Warlock::getTitle() const{
    return (this->title);
};

void Warlock::setTitle(std::string const & title){
    this->title = title;
};

void Warlock::introduce() const{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
};