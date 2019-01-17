#include <iostream>

template<typename T>
void iter(T * addr, int len, void (f)(T const &))
{
	for (int i = 0; i < len; i++)
		f(addr[i]);
}

void func_print(int const & nb)
{
	std::cout << nb << "\n";
}

template<typename T>
void template_print(T const & val)
{
	std::cout << val << "\n";
}

int main()
{
	int arr1[] = {1, 2, 3, 4};
	std::string arr2[] = {"abc", "def", "ghi"};

	iter(arr1, 4, func_print);
	iter(arr1, 4, template_print);
	iter(arr2, 3, template_print);
	return 0;
}