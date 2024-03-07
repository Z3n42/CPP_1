#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{

    private:
        std::string name;
        std::string effects;

    public:
        ASpell();
        ASpell(ASpell const &copy);
        ASpell & operator=(ASpell const & rhs);

        ASpell(std::string const name, std::string const effects);
        virtual ~ASpell();

        std::string const & getName(void) const;
        std::string const & getEffects(void) const;

        // void setEffects(std::string const name);
        
        // void introduce() const;

        virtual ASpell * clone() const = 0;
        void launch(ATarget const & atarget) const;
};


#endif