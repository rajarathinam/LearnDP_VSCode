#include "stub.h"
void reverseString(std::string& str)
{
	std::cout << "Original String:" << str;
	int n = static_cast<int>(str.size());
	for (auto i = 0; i < n / 2; ++i)
	{
		std::swap(str[i], str[n - i - 1]);
	}
	std::cout << "\nReversed String:" << str;

}
int slkmsa()
{
	std::string s1 = "Raja";
	reverseString(s1);
	return 0;
}