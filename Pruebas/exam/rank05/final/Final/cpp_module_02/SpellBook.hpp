#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook{

    private:
        // std::string name;
        // std::string title;
        std::map<std::string, ASpell *> book;

        SpellBook(SpellBook const &copy);
        SpellBook & operator=(SpellBook const & rhs);

    public:
        SpellBook();
        // SpellBook(std::string const name, std::string const title);
        ~SpellBook();

        // std::string const & getName(void) const;
        // std::string const & getTitle(void) const;

        // void setTitle(std::string const name);
        
        // void introduce() const;

        void learnSpell(ASpell * aspell);
        void forgetSpell(std::string const & name);
        // void launchSpell(std::string name, ATarget const & atarget);
        ASpell* createSpell(std::string const & name);
};


#endif