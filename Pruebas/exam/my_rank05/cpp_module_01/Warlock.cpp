#include "Warlock.hpp"

Warlock::Warlock(){};
Warlock::Warlock(std::string const name, std::string const title): name(name), title(title){
    std::cout << this->getName() <<": This looks like another boring day." << std::endl;
};

Warlock::~Warlock(){
    if(!this->book.empty()){
        std::map<std::string,ASpell*>::iterator it;
        for(it = this->book.begin(); it != this->book.end(); it++)
            delete (*it).second;
    }
    this->book.clear();
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

void Warlock::setTitle(std::string & title){
    this->title = title;
};

void Warlock::introduce() const{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
};

void Warlock::learnSpell(ASpell *aspell){
    std::map<std::string,ASpell*>::iterator it;
    it = this->book.find(name);
    if (it == book.end())
        this->book.insert(std::make_pair(aspell->getName(),aspell->clone()));
};

void Warlock::forgetSpell(std::string const name){
    std::map<std::string,ASpell*>::iterator it;
    it = this->book.find(name);
    if (it != book.end()){
        delete (*it).second;
        this->book.erase (it);
    }
};

void Warlock::launchSpell(std::string const name, ATarget &target){
    std::map<std::string,ASpell*>::iterator it;
    it = this->book.find(name);
    if (it != book.end())
        (*it->second).launch(target);
};