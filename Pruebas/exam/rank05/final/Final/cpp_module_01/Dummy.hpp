#ifndef DUMMY_HPP
#define DUMMY_HPP
#include <iostream>
#include "ATarget.hpp"

// class ATarget;

class Dummy: public ATarget{

    private:
        // std::string name;
        // std::string effects;

    public:
        Dummy();
        // Dummy(Dummy const &copy);
        // Dummy & operator=(Dummy const & rhs);

        // Dummy(std::string const name, std::string const effects);
        ~Dummy();

        // std::string const & getName(void) const;
        // std::string const & getEffects(void) const;

        // void setEffects(std::string const name);
        
        // void introduce() const;

        Dummy * clone() const;
        // void launch(ATarget const & atarget) const;
};


#endif