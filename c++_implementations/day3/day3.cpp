#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include<bits/stdc++.h>






int main()
{
    int numberOfInputs, trees_hit=0;
    std::string temp;

    numberOfInputs = 0;
    std::vector<std::string> input_vals;

    std::ifstream inputFile("c++_implementations/day3/day3_input.txt");

    while(!inputFile.eof()) //Check for end-of-file character
    {
        input_vals.resize(numberOfInputs + 1);
        inputFile >> temp;
        input_vals[numberOfInputs] = temp;
        ++numberOfInputs;
    }


    int step_horizontal = 3;
    int step_vertical = 1;
    
    int colums_landing = 0;
    // Walk through all the rows with a step of 1 down per 3 right. Don't perform an extra step after the last row!
    for (int rows = 0; rows < input_vals.size() - 1; rows = rows + step_vertical) {
        if (input_vals[rows].substr(colums_landing, 1) == "#")
        {
            ++ trees_hit;
        }
        colums_landing = (colums_landing + step_horizontal) % input_vals[0].size();
    }

    std::cout << "The answer is: " << trees_hit << std::endl;  

    return 0;
}