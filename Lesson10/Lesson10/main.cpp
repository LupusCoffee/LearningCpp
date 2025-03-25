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

#if 0
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
	bool operator< (const my_struct& s) const
	{
		return value < s.value;
	}
	bool operator> (const my_struct& s) const
	{
		return value > s.value;
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
		{Color::green, 3},
		{Color::blue, 20},
		{Color::red, 8},
		{Color::blue, 4}
	};
	for (auto i : v) std::cout << (int)i.color << ":" << i.value << " ";
	std::cout << std::endl;

	//returns the count of how many items there are in the v vector that satisfy the condition in the lambda function
	int count = std::count_if(v.begin(), v.end(), [](const my_struct& s) { return s.color == Color::blue; });
	std::cout << count << std::endl;

	//std::copy
	std::vector<my_struct> v2(v.size());
	std::copy(v.begin(), v.end(), v2.begin());
	for (auto i : v2) std::cout << (int)i.color << ":" << i.value << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	//std::sort - default sorts in ascending order
	std::sort(v2.begin(), v2.end(), std::less<>());
	for (auto i : v2) std::cout << (int)i.color << ":" << i.value << " ";
	std::cout << std::endl;

	//std::sort - default sorts in descending order
	std::sort(v2.begin(), v2.end(), std::greater<>());
	for (auto i : v2) std::cout << (int)i.color << ":" << i.value << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	//std::sort can also be done with lambda functions
	//ascending order
	std::sort(v2.begin(), v2.end(), [](const my_struct& s1, const my_struct& s2)
	{
		return s1.value < s2.value;
	});
	for (auto i : v2) std::cout << (int)i.color << ":" << i.value << " ";
	std::cout << std::endl;
	//descending order
	std::sort(v2.begin(), v2.end(), [](const my_struct& s1, const my_struct& s2)
	{
		return s1.value > s2.value;
	});
	for (auto i : v2) std::cout << (int)i.color << ":" << i.value << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	return 0;
}
#endif

//std::transform testing
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
	bool operator< (const my_struct& s) const
	{
		return value < s.value;
	}
	bool operator> (const my_struct& s) const
	{
		return value > s.value;
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
		{Color::green, 3},
		{Color::blue, 20},
		{Color::red, 8},
		{Color::blue, 4}
	};

	for (auto my_struct : v) std::cout << (int)my_struct.color << ":" << my_struct.value << " ";
	std::cout << std::endl;

	std::transform(v.begin()+2, v.end(), v.begin()+2, [](my_struct& s)
	{
		s.color = Color::red;
		s.value = -1;
		return s;
	});

	for (auto my_struct : v) std::cout << (int)my_struct.color << ":" << my_struct.value << " ";
	std::cout << std::endl;

	return 0;
}
#endif