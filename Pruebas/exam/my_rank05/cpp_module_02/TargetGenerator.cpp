#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){};
// TargetGenerator::TargetGenerator(std::string const type, std::string const title): type(type), title(title){
//     std::cout << this->getType() <<": This looks like another boring day." << std::endl;
// };

TargetGenerator::~TargetGenerator(){
    if(!this->book.empty()){
        std::map<std::string,ATarget*>::iterator it;
        for(it = this->book.begin(); it != this->book.end(); it++)
            delete (*it).second;
    }
    this->book.clear();
    // std::cout << this->getType() <<": My job here is done!" << std::endl;
};

TargetGenerator::TargetGenerator(TargetGenerator &copy){
    *this = copy;
};

TargetGenerator& TargetGenerator::operator=(TargetGenerator & rhs){
    if (this != &rhs){
        // this->type = rhs.getType();
        // this->title = rhs.getTitle();
    }
    return (*this);
};

// const std::string & TargetGenerator::getType() const{
//     return (this->type);
// };

// const std::string & TargetGenerator::getTitle() const{
//     return (this->title);
// };

// void TargetGenerator::setTitle(std::string & title){
//     this->title = title;
// };

// void TargetGenerator::introduce() const{
//     std::cout << this->getType() << ": I am " << this->getType() << ", " << this->getTitle() << "!" << std::endl;
// };

void TargetGenerator::learnTargetType(ATarget *atarget){
    std::map<std::string,ATarget*>::iterator it;
    it = this->book.find(atarget->getType());
    if (it == book.end())
        this->book.insert(std::make_pair(atarget->getType(),atarget->clone()));
};

void TargetGenerator::forgetTargetType(std::string const & type){
    std::map<std::string,ATarget*>::iterator it;
    it = this->book.find(type);
    if (it != book.end()){
        delete (*it).second;
        this->book.erase (it);
    }
};

 ATarget* TargetGenerator::createTarget(std::string const & type){
    std::map<std::string,ATarget*>::iterator it;
    it = this->book.find(type);
    if (it != book.end())
        return((*it).second);
    return((*it).second);
};
