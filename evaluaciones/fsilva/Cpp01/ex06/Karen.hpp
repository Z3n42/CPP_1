#ifndef KAREN_HPP
# define KAREN_HPP
# include <string>
# define NUM_LEVELS 4

class Karen{
	public:
		Karen();
		~Karen();
		void complain(std::string level) const;
};

#endif
