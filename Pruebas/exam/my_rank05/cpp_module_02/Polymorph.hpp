# ifndef POLIMORPH_HPP
# define POLIMORPH_HPP
# include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"

class Polymorph: public ASpell{
    private:
        // std::string name;
        // std::string effects;
        // Polymorph(Polymorph &copy);
        // Polymorph& operator=(Polymorph & rhs);

    public:
        Polymorph();
        // Polymorph(std::string const name, std::string const effects);
        ~Polymorph();

        // const std::string & getName() const;
        // const std::string & getEffects() const;
        Polymorph* clone() const;

        // void launch(ATarget & const);
};

# endif