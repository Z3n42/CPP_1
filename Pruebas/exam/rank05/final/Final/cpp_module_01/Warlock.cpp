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


void Warlock::learnSpell(ASpell * aspell){
    if (aspell){
        std::map<std::string, ASpell *>::iterator it;
        it = this->book.find(aspell->getName());
        if(it == this->book.end())
            this->book.insert(std::make_pair(aspell->getName(), aspell->clone()));
    }
};

void Warlock::forgetSpell(std::string const & name){
    std::map<std::string, ASpell *>::iterator it;
    it = this->book.find(name);
    if(it != this->book.end()){
        delete it->second;
        this->book.erase(it);
    }
};

void Warlock::launchSpell(std::string name, ATarget const & atarget){
    std::map<std::string, ASpell *>::iterator it;
    it = this->book.find(name);
    if(it != this->book.end()){
        it->second->launch(atarget);
    } 
};
