# ifndef FWOOSH_HPP
# define FWOOSH_HPP
# include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"

class Fwoosh: public ASpell{
    private:
        // std::string name;
        // std::string effects;
        // Fwoosh(Fwoosh &copy);
        // Fwoosh& operator=(Fwoosh & rhs);

    public:
        Fwoosh();
        // Fwoosh(std::string const name, std::string const effects);
        ~Fwoosh();

        // const std::string & getName() const;
        // const std::string & getEffects() const;
        Fwoosh* clone() const;

        // void launch(ATarget & const);
};

# endif