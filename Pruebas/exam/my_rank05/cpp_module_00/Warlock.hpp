# ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <iostream>

class Warlock{
    private:
        std::string name;
        std::string title;
        Warlock(Warlock &copy);
        Warlock& operator=(Warlock & rhs);

    public:
        Warlock();
        Warlock(std::string const name, std::string const title);
        ~Warlock();

        const std::string & getName() const;
        const std::string & getTitle() const;
        void setTitle(std::string const & title);

        void introduce() const;
};

# endif