#include <iostream>
#include <fstream>
#include <vector>
#include<array>
#include <tuple>
#include <bits/stdc++.h>


int walk_through_forest(int step_horizontal, int step_vertical)
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
    
    int colums_landing = 0;
    // Walk through the entire forest. Don't perform an extra step after the last row!
    for (int rows = 0; rows < input_vals.size() - 1; rows = rows + step_vertical) {
        if (input_vals[rows].substr(colums_landing, 1) == "#")
        {
            ++ trees_hit;
        }
        colums_landing = (colums_landing + step_horizontal) % input_vals[0].size();
    }

    return trees_hit;
}

int main ()
{
    std::array<int,5> horizontal_moves{1, 3, 5, 7, 1, };
    std::array<int,5> vertical_moves{1, 1, 1, 1, 2, };
    unsigned long int trees_encounterd = 1;
    
    for (int i = 0; i < horizontal_moves.size(); i++)
    {   
        int hit = walk_through_forest(horizontal_moves[i], vertical_moves[i]);
        trees_encounterd *= walk_through_forest(horizontal_moves[i], vertical_moves[i]);
    }

    std::cout << "The answer is: " << trees_encounterd << std::endl;  

    return 0;
}