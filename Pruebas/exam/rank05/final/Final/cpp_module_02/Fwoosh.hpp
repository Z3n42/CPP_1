#ifndef FWOOSH_HPP
#define FWOOSH_HPP
#include <iostream>
#include "ASpell.hpp"

// class ATarget;

class Fwoosh: public ASpell{

    private:
        // std::string name;
        // std::string effects;

    public:
        Fwoosh();
        // Fwoosh(Fwoosh const &copy);
        // Fwoosh & operator=(Fwoosh const & rhs);

        // Fwoosh(std::string const name, std::string const effects);
        ~Fwoosh();

        // std::string const & getName(void) const;
        // std::string const & getEffects(void) const;

        // void setEffects(std::string const name);
        
        // void introduce() const;

        Fwoosh * clone() const;
        // void launch(ATarget const & atarget) const;
};


#endif