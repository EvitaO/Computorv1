#include "polynomial.hpp"
#include "utils.hpp"
#include "validate.hpp"

void	printhelp(){
	std::cerr << "invalid argument" << std::endl;
	std::cout << "Usage: ./computor <string>" << std::endl;
	std::cout << "String has to have the following structer:" << std::endl;
	std::cout << " 	- every term has this form a * x^n" << std::endl;
	std::cout << "	- were n is an exponent of value 0, 1 or 2" << std::endl;
	std::cout << "Example:" << std::endl;
	std::cout << "	\"5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0\"" << std::endl;
}

void	validating(std::string a){
	validate	x(a);
	try {
		x.setup();
		std::cout << x << std::endl;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
		return;
	}
	polynomial poly(x.getFloat(2), x.getFloat(1), x.getFloat(0), x.getDegree());
	poly.solvePolynomial();
	std::cout << poly << std::endl;
}

int		main(int argc, char **argv){
	if (argc != 2){
		printhelp();
		return 0;
	}
	std::string s = argv[1];
	if (s.empty()){
		printhelp();
		return 0;
	}
	validating(argv[1]);
	return 0;
}