#if 0
#include <iostream>
#include <vector>
//#include <algorithm>

enum class Color { red, green, blue };

struct my_struct
{
	Color color;
	int value;

	bool operator == (const Color& c) const
	{
		return color == c;
	}
};

int main()
{
	std::vector<my_struct> v =
	{
		{Color::red, 5},
		{Color::blue, 64},
		{Color::green, 1},
		{Color::green, 3},
		{Color::blue, 2},
		{Color::blue, 20},
		{Color::red, 8},
		{Color::blue, 4}
	};
	for (auto i : v) std::cout << i.value << " ";
	std::cout << std::endl;

	std::vector<my_struct>::iterator it = std::find(v.begin(), v.end(), Color::red);
	std::cout << it->value;
	std::cout << std::endl;

	//can also find all values of a certain type - this oen finds all the values with the color blue
	for (std::vector<my_struct>::iterator it = std::find(v.begin(), v.end(), Color::blue); it != v.end(); it = std::find(it + 1, v.end(), Color::blue))
		std::cout << it->value << " ";
	std::cout << std::endl;

	//can also use a lambda function as the predicate to find values with a certain color, using std::find_if
	std::vector<my_struct>::iterator it2 = std::find_if(v.begin(), v.end(), [](const my_struct& s) {return s.color == Color::green; });
	std::cout << it2->value;

	return 0;
}
#endif

#if 1
#include <iostream>
#include <vector>
#include <algorithm>

enum class Color { red, green, blue };

struct my_struct
{
	Color color;
	int value;

	bool operator == (const Color& c) const
	{
		return color == c;
	}
};

int main()
{
	std::vector<my_struct> v =
	{
		{Color::red, 5},
		{Color::blue, 64},
		{Color::green, 1},
		{Color::green, 3},
		{Color::blue, 2},
		{Color::blue, 20},
		{Color::red, 8},
		{Color::blue, 4}
	};
	for (auto i : v) std::cout << (int)i.color << ":" << i.value << " ";
	std::cout << std::endl;

	//count how many items there are in the v vector that satisfy the condition in the lambda function
	int count = std::count_if(v.begin(), v.end(), [](const my_struct& s) { return s.color == Color::blue; });
	std::cout << count << std::endl;

	return 0;
}
#endif