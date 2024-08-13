#include <iostream>

#include "ntree/nvector.h"
int main(int argc, char** argv)
{
	NVector<int, 3> a;
	a.coords[0] = 1;
	a.coords[2] = 3;
	NVector<int, 3> b;
	b += a;
	b *= 3;
	b.coords[1] = 2;
	std::cout << a.print() << b.print() << std::endl;

	return 0;
}