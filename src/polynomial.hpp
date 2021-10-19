#ifndef POLYNOMIAL_HPP
# define POLYNOMIAL_HPP

#include "header.hpp"

class polynomial{
	public:
		polynomial(float a, float b, float c, int degree);
		polynomial(polynomial const & src);
		~polynomial();

		polynomial &				operator=(polynomial const & src);

		float 						getA() const;
		float 						getB() const;
		float 						getC() const;
		int							getDegree() const;
		std::vector<float> 			getSolutions() const;
		std::vector<std::string>	getSolutionsFrac() const;
		long double					getDiscriminant() const;

		std::string					getOutput() const;
		std::string					getOutput2() const;

		std::string					getSteps(int i) const;
		std::string					getStepsNegative() const;
		std::string					getStepsD() const;

		void						solve();
		void						solve2();
		void						solveNegative();
		

		void						calculateDiscriminant();
		
		void						calculateFractions();
		

	private:

		float						_a;
		float						_b;
		float						_c;
		long double					_discriminant;

		int							_degree;


		std::vector<float>			_solutions;
		std::vector<std::string>	_solutionsfraction;
};

std::ostream &			operator<<(std::ostream & o, polynomial const & src);

#endif