# kvadratka
Kvadratka is a program that solves quadratic equations, but it has some features
## Installation

```bash
git clone https://github.com/LexaxaS/kvadratka
make
```

##Usage

```c++
#include "quadratic.cpp"


//lets the user create coefficients
double roots[2] = {0};
double a = 0, b = 0, c = 0;
inPut(&a, &b, &c);

//lets the user solve the equation and get answers
int nRoots = solveEquation(a, b, c, roots);
ansOut(nRoots, roots);
```
