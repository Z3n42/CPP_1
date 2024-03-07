#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP
#include <iostream>
#include "ATarget.hpp"

// class ATarget;

class BrickWall: public ATarget{

    private:
        // std::string name;
        // std::string effects;

    public:
        BrickWall();
        // BrickWall(BrickWall const &copy);
        // BrickWall & operator=(BrickWall const & rhs);

        // BrickWall(std::string const name, std::string const effects);
        ~BrickWall();

        // std::string const & getName(void) const;
        // std::string const & getEffects(void) const;

        // void setEffects(std::string const name);
        
        // void introduce() const;

        BrickWall * clone() const;
        // void launch(ATarget const & atarget) const;
};


#endif