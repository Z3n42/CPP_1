#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP
#include <iostream>
#include "ASpell.hpp"

// class ATarget;

class Polymorph: public ASpell{

    private:
        // std::string name;
        // std::string effects;

    public:
        Polymorph();
        // Polymorph(Polymorph const &copy);
        // Polymorph & operator=(Polymorph const & rhs);

        // Polymorph(std::string const name, std::string const effects);
        ~Polymorph();

        // std::string const & getName(void) const;
        // std::string const & getEffects(void) const;

        // void setEffects(std::string const name);
        
        // void introduce() const;

        Polymorph * clone() const;
        // void launch(ATarget const & atarget) const;
};


#endif