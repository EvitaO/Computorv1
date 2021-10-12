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

float			root(float num, float brange, float erange);
float			calculateroot(float n);

int				gcd(int x, int y);



#endif