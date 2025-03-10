#include <iostream>
#include "Math.h"
using namespace std;

int main() {
	Math m;
	std::cout << m.Add(1, 2) << std::endl;
	std::cout << m.Add(1, 2, 3) << std::endl;
	std::cout << m.Add(1.1, 2.2) << std::endl;
	std::cout << m.Add(1.1, 2.2, 3.3) << std::endl;
	std::cout << m.Mul(2, 3) << std::endl;
	std::cout << m.Mul(2, 3, 4) << std::endl;
	std::cout << m.Mul(2.2, 3.3) << std::endl;
	std::cout << m.Mul(2.2, 3.3, 4.4) << std::endl;
	std::cout << m.Add(3, 1, 2, 3) << std::endl;
	std::cout << m.Add("124", "44") << std::endl;



	return 0;
}