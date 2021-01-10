#include <iostream>
#include <iostream>
#include <fstream>
#include <bitset>
#include <boost/algorithm/string/replace.hpp>

std::string text2binFormat(std::string bin_text, std::string high_char, std::string low_char)
{
    boost::replace_all(bin_text, high_char, "1");
    boost::replace_all(bin_text, low_char, "0");
    return bin_text;
}


int calculateSeatID(std::string seat_adress)
{
    // Get row number
    std::bitset<7> row_bin(text2binFormat(seat_adress.substr(0,7), "B", "F"));
    int row = row_bin.to_ulong();
    
    // Get column number
    std::bitset<3> column_bin(text2binFormat(seat_adress.substr(7,9), "R", "L"));
    int column = column_bin.to_ulong();
    return row * 8 + column;
}


int main()
{
    int seat_ID, max_seat_ID = 0;
    std::string seat_adress;
    std::ifstream inputFile("c++_implementations/day5/day5_input.txt");

    while(std::getline(inputFile, seat_adress))
    {
        seat_ID = calculateSeatID(seat_adress);
        max_seat_ID = std::max(max_seat_ID, seat_ID);
    }

    std::cout << "The answer is: " << max_seat_ID << std::endl;

    return 0;
}