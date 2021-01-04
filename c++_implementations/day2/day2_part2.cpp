#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

#include<bits/stdc++.h> 


bool check_password_valid(std::string password, char letter, int first_place, int second_place)
{
    if (password[first_place - 1] == letter && password[second_place - 1] != letter)
    {
        return true;
    }
    else if (password[first_place - 1] != letter && password[second_place - 1] == letter)
    {
        return true;
    }
    else
    {
        return false;
    }
}


std::tuple<std::string, std::string, int, int> split_string(std::string string2split)
{
    int prev=0;
    std::string letter;
    std::string parts[4];
    size_t pos = 0;

    while ((pos = string2split.find_first_of(":- ", prev)) != std::string::npos)
    {
        parts[prev] = string2split.substr(0, pos);
        string2split.erase(0, pos+1);

        ++prev;
    } 

    return std::forward_as_tuple(string2split, parts[2].substr(0,1), std::stoi(parts[0]), std::stoi(parts[1]));
}

int main()
{
    int numberOfInputs;
    
    numberOfInputs = 0;
    std::vector<std::string> password_vector;
    std::vector<std::string> letter_vector;
    std::vector<int> min_times_vector;
    std::vector<int> max_times_vector;
    int min, max, correct_passwords;
    correct_passwords = 0;
    std::string letter;
    std::string password, temp;

    std::ifstream inputFile("c++_try_adventofcode/day2/day2_input.txt");

    while(std::getline(inputFile, temp))
    {
        password_vector.resize(numberOfInputs + 1);
        letter_vector.resize(numberOfInputs + 1);
        min_times_vector.resize(numberOfInputs + 1);
        max_times_vector.resize(numberOfInputs + 1);

        std::tie (password, letter, min, max) = split_string(temp);
        if (check_password_valid(password, letter[0], min, max))
            {
                ++correct_passwords;
            }

        password_vector[numberOfInputs] = password;
        letter_vector[numberOfInputs] = letter;
        min_times_vector[numberOfInputs] = min;
        max_times_vector[numberOfInputs] = max;
        ++numberOfInputs;
    }

    return 0;
}