#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include <iostream>
#include "ASpell.hpp"

// class ATarget;

class Fireball: public ASpell{

    private:
        // std::string name;
        // std::string effects;

    public:
        Fireball();
        // Fireball(Fireball const &copy);
        // Fireball & operator=(Fireball const & rhs);

        // Fireball(std::string const name, std::string const effects);
        ~Fireball();

        // std::string const & getName(void) const;
        // std::string const & getEffects(void) const;

        // void setEffects(std::string const name);
        
        // void introduce() const;

        Fireball * clone() const;
        // void launch(ATarget const & atarget) const;
};


#endif