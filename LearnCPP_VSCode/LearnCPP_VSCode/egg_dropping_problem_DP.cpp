#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int eggDrop(int eggs, int floors)
{
    // dp table where dp[eggs][floors] represents the minimum number of drops with 'eggs' eggs and 'floors' floors
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

    // Base cases
    for (int floor = 1; floor <= floors; ++floor)
    {
        dp[1][floor] = floor; // With 1 egg, need 'floor' drops (linear search)
    }
    for (int egg = 1; egg <= eggs; ++egg)
    {
        dp[egg][1] = 1; // With any number of eggs, 1 floor needs 1 drop
    }

    // Fill the dp table using the recursive relation
    for (int egg = 2; egg <= eggs; ++egg)
    {
        for (int floor = 2; floor <= floors; ++floor)
        {
            dp[egg][floor] = INT_MAX;
            for (int dropFloor = 1; dropFloor <= floor; ++dropFloor)
            {
                // chance1(breaks) = (remaining_eggs, remaning_floors_to_check) 
                // chance2(not breaks) = (all eggs available, floors_to_check) 
                //max(chance1, chance2)
                int worstCaseDrops = 1 + max(dp[egg - 1][dropFloor - 1], dp[egg][floor - dropFloor]); // Worst case scenario
                dp[egg][floor] = min(dp[egg][floor], worstCaseDrops);  // Minimize over all drop floors
            }
        }
    }

    // Return the minimum number of drops needed with 'eggs' eggs and 'floors' floors
    return dp[eggs][floors];
}

int dshdhd()
{
    int eggs = 2;    // Number of eggs
    int floors = 3; // Number of floors

    cout << "Minimum number of drops in worst case: " << eggDrop(eggs, floors) << endl;

    return 0;
}
