# ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <iostream>
# include "ASpell.hpp"
# include "SpellBook.hpp"
# include <map>

class SpellBook;

class Warlock{
    private:
        std::string name;
        std::string title;
        // std::map<std::string, ASpell*> book;
        SpellBook spells;

        Warlock(Warlock &copy);
        Warlock& operator=(Warlock & rhs);

    public:
        Warlock();
        Warlock(std::string const name, std::string const title);
        ~Warlock();

        const std::string & getName() const;
        const std::string & getTitle() const;
        void setTitle(std::string  title);

        void introduce() const;
        void learnSpell(ASpell * aspell);
        void forgetSpell(std::string const & name);
        void launchSpell(std::string const name, ATarget& aspell);
};

# endif