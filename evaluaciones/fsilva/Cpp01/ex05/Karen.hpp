#ifndef KAREN_HPP
# define KAREN_HPP
# define NUM_LEVELS 4
#include <string>

class Karen{
	public:
		Karen();
		~Karen();
		void complain(std::string level);
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
};

#endif
