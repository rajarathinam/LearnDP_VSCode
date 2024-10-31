#include <iostream>
#include <string>

bool hasAllUniqueChars(const std::string& str) {
    int checker = 0;
    for (char c : str) {
        int bitAtIndex = c - 'a';
        if ((checker & (1 << bitAtIndex)) > 0) // value will be greater than 0 only if the  same bit is set 
        {
            return false;
        }
        checker |= (1 << bitAtIndex);
    }
    return true;
}

int sss() {
    std::string str = "aba";
    if (hasAllUniqueChars(str)) {
        std::cout << "All characters are unique" << std::endl;
    }
    else {
        std::cout << "Characters are not unique" << std::endl;
    }
    return 0;
}