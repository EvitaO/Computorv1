#ifndef POLYNOMIAL_HPP
# define POLYNOMIAL_HPP

#include "utils.hpp"

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
		std::vector<std::string>	getSolutionsFractions() const;
		long double					getDiscriminant() const;

		std::string					getOutputDegree01() const;
		std::string					getOutputDegree2() const;

		std::string					getStepsSolutions(int i) const;
		std::string					getStepsNegativeDiscriminant() const;
		std::string					getStepsDiscriminant() const;

		void						solvePolynomial();
		void						solvePolynomialDegree2();
		void						solveNegativeDiscriminant();
		

		void						calculateDiscriminant();
		
		void						calculateSolutionsFractions();
		

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