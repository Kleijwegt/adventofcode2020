#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include<bits/stdc++.h> 

std::tuple<int, int> check_sum_from_vector_sub(std::vector<int> input_vector, int combined_value = 2020)
{

    for (std::vector<int>::iterator i = input_vector.begin(); i != input_vector.end(); ++i)
    {
        // Check if element 22 exists in vector
        std::vector<int>::iterator it;
        it = std::find(input_vector.begin(),input_vector.end(), combined_value - *i);

        if (it != input_vector.end())
        {
            int j = combined_value - *i;
            return std::forward_as_tuple(*i , j);
        }
    }
    return std::forward_as_tuple(0 , 0);
}

std::tuple<int, int, int> check_sum_from_vector(std::vector<int> input_vector, int combined_value = 2020)
{

    for (std::vector<int>::iterator i = input_vector.begin(); i != input_vector.end(); ++i)
    {
        int second_val, third_val;
        std::tie (second_val, third_val) = check_sum_from_vector_sub(input_vector, combined_value - *i);
        if (*i + second_val + third_val == 2020)
        {
            return std::forward_as_tuple(*i, second_val, third_val);
        }
    }
    return std::forward_as_tuple(0 , 0, 0);
}

int main()
{
    int temp, numberOfInputs;

    numberOfInputs = 0;
    std::vector<int> input_vals;

    std::ifstream inputFile("c++_try_adventofcode/day1/day1_input.txt");

    // while(inputFile >> temp)  // safer way to perform the same check?
    while(!inputFile.eof()) //Check for end-of-file character
    {
        input_vals.resize(numberOfInputs + 1);
        inputFile >> temp;
        input_vals[numberOfInputs] = temp;
        ++numberOfInputs;
    }
    int first_val, second_val, third_val;

    
    std::tie (first_val, second_val, third_val) = check_sum_from_vector(input_vals);

    std::cout << first_val * second_val * third_val;

    return 0;
}