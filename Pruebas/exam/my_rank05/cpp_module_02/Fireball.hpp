# ifndef FIREBALL_HPP
# define FIREBALL_HPP
# include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"

class Fireball: public ASpell{
    private:
        // std::string name;
        // std::string effects;
        // Fireball(Fireball &copy);
        // Fireball& operator=(Fireball & rhs);

    public:
        Fireball();
        // Fireball(std::string const name, std::string const effects);
        ~Fireball();

        // const std::string & getName() const;
        // const std::string & getEffects() const;
        Fireball* clone() const;

        // void launch(ATarget & const);
};

# endif