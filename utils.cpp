#include "header.hpp"

std::string		stringNumber(std::string input, int i){
	std::string	number;
	if (input[i] == '.')
	{
		number += "0.";
		i++;
	}
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

float		calculateroot(float n){
	float	i = 1;
	float res;
	if (n < 0)
		n = n * -1;

	while (1){
		if (i*i == n)
			return i;
		else if (i * i > n){
			res = root(n, i - 1, i);
			return res;
		}
		i++;
	}
}

float		root(float num, float start, float end){
	float	mid = (start + end)/2;
	float	tmp = mid * mid;

	if ((tmp == num) || ((tmp - num) < 0.0001 && (num - tmp) < 0.0001)){
		return mid;
	}
	else if (start == end)
		return mid;
	else if (tmp < num){
		return root(num, mid, end);
	}
	else{
		return root(num, start, mid);
	}
}

int		gcd(int x, int y){
	if (x == 0)
		return y;
	else if (y == 0)
		return x;
	else if (x < y)
		return gcd(x, (y % x));
	else
		return gcd(y, (x % y));
}