#include <iostream>
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
#include <list>
#include <set> 

int main()
{
    std::set<char> answers;
    int total_answers = 0;
    std::string single_line;
    std::ifstream inputFile("c++_implementations/day6/day6_input.txt");

    while(std::getline(inputFile, single_line))
    {
        if (single_line != "")
        {   
            for (int it = 0; it < single_line.length(); it++)
            {
                answers.insert(single_line[it]);
            } 
        }
        else
        {
            total_answers += answers.size();
            answers.clear();
        }
        
    }

    std::cout << "The answer is: " << total_answers += answers.size() << std::endl;

    return 0;
}