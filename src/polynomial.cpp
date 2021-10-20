#include "polynomial.hpp"

polynomial::polynomial(float a, float b, float c, int degree){
	_a = a;
	_b = b;
	_c = c;
	_degree = degree;
	_discriminant = 0;
}

polynomial::polynomial(polynomial const & src){
	*this = src;
}

polynomial::~polynomial(){};

polynomial &				polynomial::operator=(polynomial const & src){
	_a = src.getA();
	_b = src.getB();
	_c = src.getC();
	_degree = src.getDegree();
	_discriminant = src.getDiscriminant();
	_solutions = src.getSolutions();
	_solutionsfraction = src.getSolutionsFractions();
	return *this;
}

float 						polynomial::getA() const{
	return this->_a;
}

float 						polynomial::getB() const{
	return this->_b;
}

float 						polynomial::getC() const{
	return this->_c;
}

int							polynomial::getDegree() const{
	return this->_degree;
}

long double					polynomial::getDiscriminant() const{
	return this->_discriminant;
}

std::vector<float> 			polynomial::getSolutions() const{
	return this->_solutions;
}

std::vector<std::string>	polynomial::getSolutionsFractions() const{
	return this->_solutionsfraction;
}

void						polynomial::solveNegativeDiscriminant(){
	long double root = calculateRoot(_discriminant * -1);
	if (-_b / (2*_a) / static_cast<int>(-_b / (2*_a)) == 1 && (root / (2*_a)) / static_cast<int>(root / (2*_a)) == 1){
		int x = -_b / (2*_a);
		int y = root / (2*_a);
		std::stringstream	str;
		str << x << " + " << y << "i";
		_solutionsfraction.push_back(str.str());
		str.str("");
		str << x << " - " << y << "i";
		_solutionsfraction.push_back(str.str());
	}
	else{
		std::stringstream	str;
		str << "(" << -_b << " + " << root << "i) / " << 2*_a;
		_solutionsfraction.push_back(str.str());
		str.str("");
		str << "(" << -_b << " - " << root << "i) / " << 2*_a;
		_solutionsfraction.push_back(str.str());
	}
}

void						polynomial::solvePolynomial(){
	if (_degree == 2){
		calculateDiscriminant();
		if (_discriminant == 0 && _b == 0)
			_solutions.push_back(0);
		else if (_discriminant == 0)
			_solutions.push_back(-_b/(2*_a));
		else if (_discriminant > 0)
			solvePolynomialDegree2();
		else
			solveNegativeDiscriminant();
		
	}
	if (_degree == 1){
		if (_c == 0)
			_solutions.push_back(0);
		else
			_solutions.push_back((-_c/_b));
	}
	calculateSolutionsFractions();
}


void						polynomial::solvePolynomialDegree2(){
	long double root = calculateRoot(_discriminant);
	if (-_b + static_cast<float>(root) == 0)
		_solutions.push_back(0/(2*_a));
	else
		_solutions.push_back((-_b + root)/(2*_a));
	if (-_b - static_cast<float>(root) == 0)
		_solutions.push_back(0/(2*_a));
	else
		_solutions.push_back((-_b - root)/(2*_a));
}

void						polynomial::calculateDiscriminant(){
	_discriminant = (_b * _b) - 4 * _a * _c;
}

void						polynomial::calculateSolutionsFractions(){
	for(int i = 0; i < _solutions.size(); i++){
		std::stringstream	str;
		float	solution = _solutions[i] * (_solutions[i] < 0 ? -1 : 1);
		int		integ = static_cast<int>(solution);
		int		scale = 1000000;
		int 	flt = static_cast<int>((solution - integ) * scale);
		int		gcdval = gcd(flt, scale);

		int		numerator = (flt / gcdval);
		int		denominator = scale / gcdval;

		if (denominator <= 10000 && flt != 0){
			if (_solutions[i] < 0)
				str << "-";
			str << "(" << (integ * denominator) + numerator << " / " << denominator << ")";
			_solutionsfraction.push_back(str.str());
		}
		else
			_solutionsfraction.push_back("0");
	}
}

std::string					polynomial::getStepsDiscriminant() const{
	std::stringstream s;
	s << "\na = " << _a << " ,b = " << _b << " , c = " << _c << std::endl;
	s << "Discriminant = b * b - 4 * a * c\n" << "Discriminant = " << _b << " * " << _b << " - 4 * " << _a << " * " << _c << std::endl;
	s << "Discriminant = " << _discriminant << std::endl << std::endl;
	return s.str();
}

std::string					polynomial::getStepsSolutions(int i) const{
	std::stringstream s;
	if (_discriminant == 0){
		s << "x = -b / (2*a)\n" << "x = " << -_b << " / (2*" << _a << ")\n" << "x = " << -_b << " / " << 2*_a << std::endl;
		return s.str();
	}
	if (i == 0){
		s << "x = (-b + sqrt(discriminant))/2 * a\n" << "x = (" << (-_b) << " + sqrt(" << _discriminant << ")) / (2 * " << _a << ")" << std::endl;
		s << "x = " << (-_b + calculateRoot(_discriminant)) << " / " << (2 * _a) << std::endl;  	
		return s.str();
	}
	else {
		s << "x = (-b - sqrt(discriminant))/2 * a\n" << "x = (" << -_b << " - sqrt(" << _discriminant << ")) / (2 * " << _a << ")" << std::endl;
		s << "x = " << (-_b - calculateRoot(_discriminant)) << " / " << (2 * _a) << std::endl;  	
		return s.str();
	}
}

std::string					polynomial::getStepsNegativeDiscriminant() const{
	std::stringstream s;

	s << "x = (-b +-i sqrt(discriminant * -1))/2 * a\n" << "x = (" << (-_b) << " +-i sqrt(" << (_discriminant * -1) << ")) / (2 * " << _a << ")" << std::endl;
	s << "x = " << "(" << -_b << " +-i " << calculateRoot(_discriminant * -1) << ")" << " / " << (2 * _a) << std::endl << std::endl;
	s << "x = " << _solutionsfraction[0] << std::endl;
	s << "or" << std::endl;
	s << "x = " << _solutionsfraction[1] << std::endl;
	return s.str();
}

std::string					polynomial::getOutputDegree2() const{
	std::stringstream s;
	if (getDiscriminant() > 0){
		s << "Discriminant is strictly positive, the two solutions are:\n" << getStepsDiscriminant();
		for (int i = 0; i < getSolutions().size(); i++){
			s << getStepsSolutions(i);
			s << "x = " << getSolutions()[i];
			if (getSolutionsFractions()[i] != "0")
				s << "	=	" << getSolutionsFractions()[i];
			if (i + 1 < getSolutions().size())
				s << std::endl << std::endl;
		}
	}
	else if (getDiscriminant() == 0){
		s << "Discriminant is zero, the solution is: \n" << getStepsDiscriminant() << getStepsSolutions(0);
		s << "x = " << getSolutions()[0];
		if (getSolutionsFractions()[0] != "0")
			s << "	=	" << getSolutionsFractions()[0];
	}
	else
		s << "Discriminant is strictly negative, the two complex solutions are:\n" << getStepsDiscriminant() << getStepsNegativeDiscriminant();
	return s.str();
}

std::string					polynomial::getOutputDegree01() const{
	if (_a == 0 && _b == 0){
		if (_c == 0)
			return "Every real number is a solutions";
		else
			return "No solution possible";
	}
	else if (getDegree() == 1){
		std::stringstream s;
		s << "The solution is:\n" << "x = -c/b\n" << "x = " << -_c << "/" << _b << "\n" << "x = " << getSolutions()[0];
		if (getSolutionsFractions()[0] != "0")
			s << "	=	" << getSolutionsFractions()[0];
		return s.str();
	}
	else
		return getOutputDegree2();
}


std::ostream &				operator<<(std::ostream & o, polynomial const & src){
	o << std::setprecision(6);
	o << src.getOutputDegree01();
	return o;
}	