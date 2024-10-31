#include <iostream>
#include <string>
#include <vector>

int hcshcdkdjdk() {
    const std::string s1 = "liaten";
    const std::string s2 = "silent";

    // Check if lengths are the same
    if (s1.length() != s2.length()) {
        std::cout << "Not anagrams" << std::endl;
        return 0;
    }

    // Create a frequency count vector
    std::vector<int> chars(256, 0);

    // Count frequencies in s1 and s2
    for (char ch : s1) {
        chars[ch]++;
    }
    for (char ch : s2) {
        chars[ch]--;
        if (chars[ch] < 0)
        {
            std::cout << "Not anagrams" << std::endl;
            break;
        }
    }

    std::cout << "Anagrams" << std::endl;
    return 0;
}
