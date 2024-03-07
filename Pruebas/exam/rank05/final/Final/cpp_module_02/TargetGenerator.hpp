#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator{

    private:
        // std::string type;
        // std::string title;
        std::map<std::string, ATarget *> book;

        TargetGenerator(TargetGenerator const &copy);
        TargetGenerator & operator=(TargetGenerator const & rhs);

    public:
        TargetGenerator();
        // TargetGenerator(std::string const type, std::string const title);
        ~TargetGenerator();

        // std::string const & getName(void) const;
        // std::string const & getTitle(void) const;

        // void setTitle(std::string const type);
        
        // void introduce() const;

        void learnTargetType(ATarget * atarget);
        void forgetTargetType(std::string const & type);
        // void launchTargetType(std::string type, ATarget const & atarget);
        ATarget* createTarget(std::string const & type);
};


#endif