#include "SpellBook.hpp"

SpellBook::SpellBook(){

};

// SpellBook::SpellBook(std::string const name, std::string const title): name(name), title(title){
//     std::cout << this->getName() << ": This looks like another boring day." << std::endl;
// };

SpellBook::SpellBook(SpellBook const &copy){
    *this = copy;
};

SpellBook & SpellBook::operator=(SpellBook const & rhs){
    if(this != &rhs){
        // this->name = rhs.getName();
        // this->title = rhs.getTitle();
    }
    return (*this);
};

SpellBook::~SpellBook(){
    // std::cout << this->getName() << ": My job here is done!" << std::endl;k

};

// std::string const & SpellBook::getName(void) const{
//     return(this->name);
// };

// std::string const & SpellBook::getTitle(void) const{
//     return(this->title);
// };

// void SpellBook::setTitle(std::string const name){
//     this->title = name;
// };

// void SpellBook::introduce() const{
//     std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
// };


void SpellBook::learnSpell(ASpell * aspell){
    if (aspell){
        std::map<std::string, ASpell *>::iterator it;
        it = this->book.find(aspell->getName());
        if(it == this->book.end())
            this->book.insert(std::make_pair(aspell->getName(), aspell->clone()));
    }
};

void SpellBook::forgetSpell(std::string const & name){
    std::map<std::string, ASpell *>::iterator it;
    it = this->book.find(name);
    if(it != this->book.end()){
        delete it->second;
        this->book.erase(it);
    }
};

ASpell* SpellBook::createSpell(std::string const & name){
    std::map<std::string, ASpell *>::iterator it;
    it = this->book.find(name);
    if(it != this->book.end()){
        return(it->second);
    }  
    return (NULL);
};

// void SpellBook::launchSpell(std::string name, ATarget const & atarget){
//     std::map<std::string, ASpell *>::iterator it;
//     it = this->book.find(name);
//     if(it != this->book.end()){
//         it->second->launch(atarget);
//     } 
// };
