# ifndef ATARGET_HPP
# define ATARGET_HPP
# include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{
    private:
        std::string type;
        ATarget(ATarget &copy);
        ATarget& operator=(ATarget & rhs);

    public:
        ATarget();
        ATarget(std::string const type);
        virtual ~ATarget();

        const std::string & getType() const;
        virtual ATarget* clone() const = 0;

        void getHitBySpell(ASpell& aspell);

};

# endif