#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){

};

// TargetGenerator::TargetGenerator(std::string const type, std::string const title): type(type), title(title){
//     std::cout << this->getType() << ": This looks like another boring day." << std::endl;
// };

TargetGenerator::TargetGenerator(TargetGenerator const &copy){
    *this = copy;
};

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & rhs){
    if(this != &rhs){
        // this->type = rhs.getType();
        // this->title = rhs.getTitle();
    }
    return (*this);
};

TargetGenerator::~TargetGenerator(){
    // std::cout << this->getType() << ": My job here is done!" << std::endl;k

};

// std::string const & TargetGenerator::getType(void) const{
//     return(this->type);
// };

// std::string const & TargetGenerator::getTitle(void) const{
//     return(this->title);
// };

// void TargetGenerator::setTitle(std::string const type){
//     this->title = type;
// };

// void TargetGenerator::introduce() const{
//     std::cout << this->getType() << ": I am " << this->getType() << ", " << this->getTitle() << "!" << std::endl;
// };


void TargetGenerator::learnTargetType(ATarget * atarget){
    if (atarget){
        std::map<std::string, ATarget *>::iterator it;
        it = this->book.find(atarget->getType());
        if(it == this->book.end())
            this->book.insert(std::make_pair(atarget->getType(), atarget->clone()));
    }
};

void TargetGenerator::forgetTargetType(std::string const & type){
    std::map<std::string, ATarget *>::iterator it;
    it = this->book.find(type);
    if(it != this->book.end()){
        delete it->second;
        this->book.erase(it);
    }
};

ATarget* TargetGenerator::createTarget(std::string const & type){
    std::map<std::string, ATarget *>::iterator it;
    it = this->book.find(type);
    if(it != this->book.end()){
        return(it->second);
    }  
    return (NULL);
};

// void TargetGenerator::launchTargetType(std::string type, ATarget const & atarget){
//     std::map<std::string, ATarget *>::iterator it;
//     it = this->book.find(type);
//     if(it != this->book.end()){
//         it->second->launch(atarget);
//     } 
// };
