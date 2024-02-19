# ifndef BRICKWALL_HPP
# define BRICKWALL_HPP
# include <iostream>
#include "ATarget.hpp"
// #include "ASpell.hpp"

class BrickWall: public ATarget{
    private:
        // std::string type;
        // BrickWall(BrickWall &copy);
        // BrickWall& operator=(BrickWall & rhs);

    public:
        BrickWall();
        // BrickWall(std::string const type, std::string const effects);
        ~BrickWall();

        // const std::string & getType() const;
        BrickWall* clone() const;

        // void getHitBySpell(ASpell&);

};

# endif