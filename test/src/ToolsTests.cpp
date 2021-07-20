#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <fstream>
#include <streambuf>
#include <algorithm>
#include <sstream>
#include <Tools/Tools.h>

int main()
{
    printf("Test about writing a Binary Vector to a text file");
    std::vector<std::bitset<8>> binaryVector = { 01001000, 01100101, 01101100, 01101100, 01101111, 00100000, 01010111, 01101111, 01110010, 01101100, 01100100};
    Tools::writeFile(binaryVector, "testfile.txt");

    Tools::printFile("testfile.txt");
    return EXIT_SUCCESS;
}