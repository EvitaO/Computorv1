# ComputorV1

This project aims to make you code a simple equation solving program. It will take polynomial equations into account. These equations will only require exponents. No complex function. The program will have to display its solution(s).</br>
</br>
The program must solve a polynomial of second or lower degree equation and show at least:</br>
• The equation in its reduced form.</br>
• The degree of the equation.</br>
• It’s solution(s) and the polarity of the discriminant if it makes sens.</br>
</br>
Bonus:</br>
• Manage entry mistakes</br>
• Display the intermediate steps</br>
• Display solution as an irreducible fraction if it's interesting</br>

### Compile
```
CMake -B build && cd build
make all
```
### Usage
```
./computor [string]
```
String has to have the following structer:</br>
  • every term has this form a * x^n</br>
  • were n is an exponent of value 0, 1 or 2</br>
Example: "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"

### Output
```
./computor  "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
Reduced form: 4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
Polynomial degree: 2
Discriminant is strictly positive, the two solutions are:

a = -9.3 ,b = 4 , c = 4
Discriminant = b * b - 4 * a * c
Discriminant = 4 * 4 - 4 * -9.3 * 4
Discriminant = 164.8

x = (-b + sqrt(discriminant))/2 * a
x = (-4 + sqrt(164.8)) / (2 * -9.3)
x = 8.83745 / -18.6
x = -0.475131

x = (-b - sqrt(discriminant))/2 * a
x = (-4 - sqrt(164.8)) / (2 * -9.3)
x = -16.8374 / -18.6
x = 0.905239
```

### Tester
```
./test/computor_test
```
