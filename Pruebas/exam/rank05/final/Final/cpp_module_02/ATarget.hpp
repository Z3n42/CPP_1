#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{

    private:
        std::string type;
        // std::string effects;

    public:
        ATarget();
        ATarget(ATarget const &copy);
        ATarget & operator=(ATarget const & rhs);

        ATarget(std::string const type);
        virtual ~ATarget();

        std::string const & getType(void) const;
        // std::string const & getEffects(void) const;

        // void setEffects(std::string const type);

        // void introduce() const;

        virtual ATarget * clone() const = 0;

        void getHitBySpell(ASpell const & aspell) const;
};


#endif