#ifndef HEADER_HPP
# define HEADER_HPP

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <sstream>

std::string		stringNumber(std::string input, int i);
bool			compare(std::pair<float, int> p1, std::pair<float, int> p2);

long double		calculateroot(long double n);
long double	    findrange(long double n);
void		    smallerrange(long double *i, long double *j, long double n);

int				gcd(int x, int y);



#endif