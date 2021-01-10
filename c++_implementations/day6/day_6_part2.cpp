#include <iostream>
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
#include <list>
#include <set>

int main()
{
    std::list<int> group_answers;
    std::string answers = "";
    std::set<char> unique_answers;
    int total_answers = 0;
    int persons_in_group = 0;
    std::string single_line;
    std::ifstream inputFile("c++_implementations/day6/day6_input.txt");

    while(std::getline(inputFile, single_line))
    {
        if (single_line != "")
        {   
            persons_in_group += 1;
            answers += single_line;
        }
        else
        {
            for (int it = 0; it < answers.length(); it++)
            {
                int count = std::count(answers.begin(), answers.end(), answers[it]);
                if (count == persons_in_group  && answers[it] != '_')
                {
                    total_answers ++;
                }
                std::replace(answers.begin(), answers.end(), answers[it], '_');
            } 
            persons_in_group = 0;
            answers = "";
        }
        
    }

    // Run once more to also add the answers of the last group.
    if (single_line != "")
    {   
        persons_in_group += 1;
        answers += single_line;
    }
    else
    {
        for (int it = 0; it < answers.length(); it++)
        {
            int count = std::count(answers.begin(), answers.end(), answers[it]);
            if (count == persons_in_group  && answers[it] != '_')
            {
                total_answers ++;
            }
            std::replace(answers.begin(), answers.end(), answers[it], '_');
        } 
        persons_in_group = 0;
        answers = "";
    }

    std::cout << "The answer is: " << total_answers << std::endl;

    return 0;
}