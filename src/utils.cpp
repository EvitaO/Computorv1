#include "header.hpp"
#include <cstring>

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
	float i = 0.0;
	float j = 0.0;
	std::cout << std::setprecision(6) << std::fixed;
	for(; i * i <= n; i++){
		if (i * i == n)
			return i;
	}
	j = i - 1;
	while (i * i - n  > 0.001){
		float mid = (i + j)/2 * (i + j)/2;
		if (j == (i + j)/2 || i == (i + j)/2)
			break;
		else if (mid < n){
			j = (i + j)/2;
		}
		else
			i = (i + j)/2;
	}
	i = (i > j) ? j : i;
    for (; i*i < n; i = i + 0.000001){
		std::cout <<  "i*i: " << i*i << std::endl << n << std::endl;
		if (n - i*i < 0.01)
			break;
	}
    return (i);
}

float		root(float num, float start, float end){

    for (; start*start < num; start = start + 0.000001);

    return (start);
	// float	mid = (start + end)/2;
	// float	tmp = mid * mid;

	// if ((tmp == num) || ((tmp - num) < 0.0001 && (num - tmp) < 0.0001)){
	// 	return mid;
	// }
	// else if (start == end)
	// 	return mid;
	// else if (tmp < num){
	// 	return root(num, mid, end);
	// }
	// else{
	// 	return root(num, start, mid);
	// }
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