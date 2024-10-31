#pragma once
#include "stub.h"

void RemoveDuplicateChars(std::string& str)
{
	int size = static_cast<int>(str.length());
	int checker = 0;
	int write_index = 0;
	for (int i = 0; i < size; ++i)
	{
		int bitAtIndex = str[i] - 'a';
		if ((checker & (1 << bitAtIndex)) == 0) // not duplicate, > 0 means duplicate
		{
			checker |= (1 << bitAtIndex);
			str[write_index] = str[i];
			++write_index;
		}

	}
	str.resize(write_index);
	std::cout << "\nResultString:" << str;

}
int sjdkjs()
{
	std::string s1 = "Raja";
	RemoveDuplicateChars(s1);
	return 0;
}
