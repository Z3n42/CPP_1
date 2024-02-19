# ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP
# include <iostream>
# include "ATarget.hpp"
# include <map>

class TargetGenerator{
    private:
        // std::string type;
        // std::string title;
        std::map<std::string, ATarget*> book;

        TargetGenerator(TargetGenerator &copy);
        TargetGenerator& operator=(TargetGenerator & rhs);

    public:
        TargetGenerator();
        // TargetGenerator(std::string const type, std::string const title);
        ~TargetGenerator();

        // const std::string & getType() const;
        // const std::string & getTitle() const;
        // void setTitle(std::string & title);

        // void introduce() const;
        void learnTargetType(ATarget * atarget);
        void forgetTargetType(std::string const & type);
        ATarget* createTarget(std::string const & type);
};

# endif