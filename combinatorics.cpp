#include <iostream>
#include <vector>
#include <algorithm>

struct Interval
{
    std::vector<std::string> key; // Вектор для зберігання комбінацій
};

// Функція для генерації всіх можливих комбінацій
void generateCombinations(std::vector<std::string>& values, std::vector<Interval>& intervals, std::vector<std::string>& combination, int non)
{
    if (combination.size() == non)
    {
        intervals.push_back({ combination }); // Додаємо знайдену комбінацію до вектору intervals
        return;
    }

    for (int i = 0; i < values.size(); i++)
    {
        combination.push_back(values[i]); // Додаємо значення до поточної комбінації
        std::vector<std::string> remainingValues(values.begin(), values.end());
        remainingValues.erase(remainingValues.begin() + i); // Видаляємо використане значення зі списку доступних значень
        generateCombinations(remainingValues, intervals, combination, non); // Рекурсивний виклик для генерації наступного елемента комбінації
        combination.pop_back(); // Повертаємося назад і видаляємо останнє додане значення для перебору інших варіантів
    }
}

int main()
{
    int non;
    std::cout << "Введіть значення NON (від 1 до 12): ";
    std::cin >> non;

    if (non < 1 || non > 12)
    {
        std::cout << "Недійсне значення NON. Будь ласка, введіть значення від 1 до 12." << std::endl;
        return 1;
    }

    std::vector<std::string> values(non);
    for (int i = 0; i < non; i++)
    {
        std::cout << "Введіть значення " << i + 1 << ": ";
        std::cin >> values[i]; // Введення значень для формування комбінацій
    }

    std::vector<Interval> intervals;
    std::vector<std::string> combination;
    generateCombinations(values, intervals, combination, non); // Генерація всіх можливих комбінацій

    // Виведення результату
    for (const auto& interval : intervals)
    {
        for (int i = 0; i < non; i++)
        {
            std::cout << interval.key[i] << " "; // Виведення комбінації
        }
        std::cout << std::endl;
    }

    return 0;
}
