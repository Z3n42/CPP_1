#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock{

    private:
        std::string name;
        std::string title;
        std::map<std::string, ASpell *> book;

        Warlock();
        Warlock(Warlock const &copy);
        Warlock & operator=(Warlock const & rhs);

    public:
        Warlock(std::string const name, std::string const title);
        ~Warlock();

        std::string const & getName(void) const;
        std::string const & getTitle(void) const;

        void setTitle(std::string const name);
        
        void introduce() const;

        void learnSpell(ASpell * aspell);
        void forgetSpell(std::string const & name);
        void launchSpell(std::string name, ATarget const & atarget);
};


#endif