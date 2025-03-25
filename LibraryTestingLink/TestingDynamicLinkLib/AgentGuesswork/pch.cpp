// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.

#include <vector>
extern "C" __declspec(dllexport) //__declspec(dllexport) exportes the function to be used in the DLL, making it accessible to other programs! "extern 'C'" prevents C++ name mangling
int GetRandNum(int min, int max)
{
	return rand() % (max - min + 1) + min;
}