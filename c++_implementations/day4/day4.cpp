#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

#include<bits/stdc++.h> 


std::string single_entry(std::ifstream& inputFile)
{
    std::string line, full_entry="";
    while(std::getline(inputFile, line) && line != "")
    {
        full_entry = full_entry + " " + line; 
    }
    return full_entry;
}

bool check_passport(std::string passport_data)
{
    std::string required_fields[7] = {"byr", "iyr","eyr", "hgt", "hcl", "ecl", "pid"};
    for (std::string field_name: required_fields)
    {
        if (passport_data.find(field_name) == std::string::npos)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int correct_entries=0;
    std::string one_entry;

    std::ifstream inputFile("c++_implementations/day4/day4_input.txt");
    while(!inputFile.eof())
    {
        one_entry = single_entry(inputFile);
        if (check_passport(one_entry))
            {
                correct_entries += 1;
            }
    }
    std::cout << "The answer is: " << correct_entries << std::endl;
}