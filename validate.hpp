#ifndef VALIDATE_HPP
# define VALIDATE_HPP

#include "header.hpp"

class	validate{
	public:
		validate(std::string str);
		validate(validate const & src);
		~validate();

		validate &				operator=(validate const & src);
		void					createChunks();
		void					controlChunks();
		void					controlChunk(std::string input);
		int						checkSigns(std::string input, int i);

		void					setup();

		void					setDegree();
		int						getDegree() const;
		void					addpair(float n, int exp);

		void					createReduced();
		std::string				getReduced() const;

		int						saveNbr(std::string input, int i, int sign);

		float					getFloat(int exp);


	private:
		validate();

		std::string							_input;
		std::string							_reducedform;
		std::vector<std::string>			_chunks;
		std::vector<std::pair<float, int> >	_order;
		int									_degree;
		float								_nbr;
};

std::ostream &			operator<<(std::ostream & o, validate const & src);


#endif