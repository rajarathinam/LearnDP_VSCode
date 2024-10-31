#include <iostream>
#include <map>
#include <memory>

using namespace std;

#include <iostream>
#include<typeinfo>
#include <vector>

std::vector<int> RemoveDuplicatesWithExtraSpace(std::vector<int>& arr)
{
    std::vector<int> result;
    int n = arr.size();

    int j = 0;
    for (int i = 0; i <= n - 2; ++i)
    {
        if (arr[i] != arr[i + 1])
        {
            result.push_back(arr[i]);
        }
    }
    result.push_back(arr[n - 1]);

    return result;
}
std::vector<int> RemoveDuplicatesWithoutExtraSpace(std::vector<int>& arr)
{
    
    int n = arr.size();

    int j = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[j] = arr[i];
            j++;
        }
    }
    arr[j] = arr[n - 1];
    arr.erase(arr.begin() + j +1, arr.end());

    return arr;
}

int ghgfh()
{
    std::vector<int> arr = { 11, 22, 22, 33 };
    std::vector<int> arr2 = RemoveDuplicatesWithoutExtraSpace(arr);



    for (int num : arr2)
    {
        std::cout << num << " ";
    }

    return 0;
}
