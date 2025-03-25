#if 0
#include <iostream>
#include "Windows.h"

typedef float(*MathFunc)(float, float); //an alias for a pointer to a function with the signature int(int, int) - i.e. "int GetRandNum(int min, int max)" > i dont get it

int main()
{
	//try to load the library
	HINSTANCE hMath = LoadLibraryA("NewMath.dll");
	if (hMath == nullptr)
	{
		std::cout << "Failed to load M_Math library" << std::endl;
		return 1;
	}

	//try to get the address of the function from NewMath.dll
	MathFunc M_MathFunc = (MathFunc)GetProcAddress(hMath, "Division");
	if (M_MathFunc == nullptr)
	{
		std::cout << "Failed to get the address of the function" << std::endl;
		return 1;
	}

	std::cout << "Random number: " << M_MathFunc(1, 10) << std::endl;
	std::cout << "Random number: " << M_MathFunc(2, 10) << std::endl;

	return 0;
}
#endif

#if 1
#include <iostream>
#include "Windows.h"

typedef float(*MathFunc)(float, float);
int main()
{
	HINSTANCE hMath = LoadLibraryA("NewMath.dll");
	MathFunc M_MathFunc;

	const char* funcList[] = { "Addition", "Subtraction", "Multiplication", "Division" };
	for (auto mathFunc : funcList)
	{
		M_MathFunc = (MathFunc)GetProcAddress(hMath, mathFunc);
		std::cout << "Func Result: " << M_MathFunc(2, 2) << std::endl;
		std::cout << "Func Result: " << M_MathFunc(10, 5) << std::endl;
		std::cout << "\n";
	}

	return 0;
}
#endif