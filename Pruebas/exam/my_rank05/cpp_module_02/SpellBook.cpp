#include "SpellBook.hpp"

SpellBook::SpellBook(){};
// SpellBook::SpellBook(std::string const name, std::string const title): name(name), title(title){
//     std::cout << this->getName() <<": This looks like another boring day." << std::endl;
// };

SpellBook::~SpellBook(){
    if(!this->book.empty()){
        std::map<std::string,ASpell*>::iterator it;
        for(it = this->book.begin(); it != this->book.end(); it++)
            delete (*it).second;
    }
    this->book.clear();
    // std::cout << this->getName() <<": My job here is done!" << std::endl;
};

SpellBook::SpellBook(SpellBook &copy){
    *this = copy;
};

SpellBook& SpellBook::operator=(SpellBook & rhs){
    if (this != &rhs){
        // this->name = rhs.getName();
        // this->title = rhs.getTitle();
    }
    return (*this);
};

// const std::string & SpellBook::getName() const{
//     return (this->name);
// };

// const std::string & SpellBook::getTitle() const{
//     return (this->title);
// };

// void SpellBook::setTitle(std::string & title){
//     this->title = title;
// };

// void SpellBook::introduce() const{
//     std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
// };

void SpellBook::learnSpell(ASpell *aspell){
    std::map<std::string,ASpell*>::iterator it;
    it = this->book.find(aspell->getName());
    if (it == book.end())
        this->book.insert(std::make_pair(aspell->getName(),aspell->clone()));
};

void SpellBook::forgetSpell(std::string const & name){
    std::map<std::string,ASpell*>::iterator it;
    it = this->book.find(name);
    if (it != book.end()){
        delete (*it).second;
        this->book.erase (it);
    }
};

 ASpell* SpellBook::createSpell(std::string const & name){
    std::map<std::string,ASpell*>::iterator it;
    it = this->book.find(name);
    if (it != book.end())
        return((*it).second);
    return((*it).second);
};
