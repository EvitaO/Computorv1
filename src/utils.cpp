#include "header.hpp"
#include <cstring>

std::string		stringNumber(std::string input, int i){
	std::string	number;
	if (input[i] == '.' && isdigit(input[i + 1]))
	{
		number += "0.";
		i++;
	}
	else if (input[i] == '.')
		throw std::runtime_error("invalid format");
	while (isdigit(input[i])){
		number += input[i];
		if (input[i + 1] == '.'){
			number += input[i + 1];
			i++;
		}
		i++;
	}
	return number;
}

bool		compare(std::pair<float, int> p1, std::pair<float, int> p2){
		if (p1.first == 0)
			return true;
		if (p2.first == 0)
			return false;
		return p1.second<p2.second;
}

long double	findrange(long double n){
	long double i = 0;
	for (; i * i < n ; i++){}
	return i;
}

void		smallerrange(long double *i, long double *j, long double n){
	//while (*i * *i - n  > 0.0001){
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

long double		calculateroot(long double n){
	long double i = 0.0;
	long double j = 0.0;
	if (n < 0)
		return 0.0/0.0;
	i = findrange(n);
	if (i * i == n)
		return i;
	j = i - 1;
	smallerrange(&i, &j, n);
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