# ifndef DUMMY_HPP
# define DUMMY_HPP
# include <iostream>
#include "ATarget.hpp"
// #include "ASpell.hpp"

class Dummy: public ATarget{
    private:
        // std::string type;
        // Dummy(Dummy &copy);
        // Dummy& operator=(Dummy & rhs);

    public:
        Dummy();
        // Dummy(std::string const type, std::string const effects);
        ~Dummy();

        // const std::string & getType() const;
        Dummy* clone() const;

        // void getHitBySpell(ASpell&);

};

# endif