
#include <iostream>
#include <vector>
#include <algorithm>

void generateCombinations(const std::vector<int>& values, std::vector<Interval>& intervals, std::vector<int>& combination, int index, int NON)
{
    if (index == NON)
    {
        intervals.push_back({ combination });
        return;
    }

    for (int i = 0; i < values.size(); i++)
    {
        if (std::find(combination.begin(), combination.end(), values[i]) == combination.end())
        {
            combination[index] = values[i];
            generateCombinations(values, intervals, combination, index + 1);
        }
    }
}