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

std::string		createStringNumber(std::string input, int i);

long double		calculateRoot(long double n);
long double	    findRangeRoot(long double n);
void		    reduceRangeRoot(long double *i, long double *j, long double n);

int				gcd(int x, int y);

bool		    charX(char a);


#endif