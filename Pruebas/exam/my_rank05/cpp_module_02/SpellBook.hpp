# ifndef SPELLBOCK_HPP
# define SPELLBOCK_HPP
# include <iostream>
# include "ASpell.hpp"
# include <map>

class SpellBook{
    private:
        // std::string name;
        // std::string title;
        std::map<std::string, ASpell*> book;

        SpellBook(SpellBook &copy);
        SpellBook& operator=(SpellBook & rhs);

    public:
        SpellBook();
        // SpellBook(std::string const name, std::string const title);
        ~SpellBook();

        // const std::string & getName() const;
        // const std::string & getTitle() const;
        // void setTitle(std::string & title);

        // void introduce() const;
        void learnSpell(ASpell * aspell);
        void forgetSpell(std::string const & name);
        ASpell* createSpell(std::string const & name);
};

# endif