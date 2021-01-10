#include <iostream>
#include <iostream>
#include <fstream>
#include <bitset>
#include <list>
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
    int seat_ID;
    std::string seat_adress;
    std::list<int> seat_ID_list;
    std::ifstream inputFile("c++_implementations/day5/day5_input.txt");

    while(std::getline(inputFile, seat_adress))
    {   
        seat_ID = calculateSeatID(seat_adress);
        seat_ID_list.push_front(seat_ID);
    }
    seat_ID_list.sort();

    int previous_seat, current_seat;
    current_seat = seat_ID_list.front();
    seat_ID_list.pop_front();
    
    do
    {
        previous_seat = current_seat;
        current_seat = seat_ID_list.front();
        seat_ID_list.pop_front();
    }
    while(current_seat - previous_seat != 2);

    std::cout << "The answer is: " << previous_seat + 1 << std::endl;

    return 0;
}