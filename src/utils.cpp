#include "utils.hpp"
#include <cstring>

std::string		createStringNumber(std::string input, int i){
	std::string	number;
	int point = 0;
	if (input[i] == '.' && isdigit(input[i + 1]))
	{
		number += "0.";
		point++;
		i++;
	}
	else if (input[i] == '.')
		throw std::runtime_error("invalid format");
	while (isdigit(input[i]) && point <= 1){
		number += input[i];
		if (input[i + 1] == '.'){
			number += input[i + 1];
			i++;
			point++;
		}
		i++;
	}
	if (point > 1)
		throw std::runtime_error("invalid format");
	return number;
}

bool		charX(char a){
	if (a == 'x' || a == 'X')
		return true;
	return false;
}

long double	findRangeRoot(long double n){
	long double i = 0;
	for (; i * i < n ; i++){}
	return i;
}

void		reduceRangeRoot(long double *i, long double *j, long double n){
	while(1){
		float mid = (*i + *j)/2 * (*i + *j)/2;
		if (*j == (*i + *j)/2 || *i == (*i + *j)/2)
			break;
		else if (mid < n){
			*j = (*i + *j)/2;
		}
		else
			*i = (*i + *j)/2;
	}
}

long double		calculateRoot(long double n){
	long double i = 0.0;
	long double j = 0.0;
	if (n < 0)
		return 0.0/0.0;
	i = findRangeRoot(n);
	if (i * i == n)
		return i;
	j = i - 1;
	reduceRangeRoot(&i, &j, n);
	i = i - 0.000000001;
    for (; j*j < n; j = j + 0.000000001){
		if (i == j)
			break;
		i = j;
	}
    return (i);
}

int		gcd(int x, int y){
	if (x < 0){x *= -1;}
	if (y< 0){y *= -1;}
	if (x == 0)
		return y;
	else if (y == 0)
		return x;
	else if (x < y)
		return gcd(x, (y % x));
	else
		return gcd(y, (x % y));
}