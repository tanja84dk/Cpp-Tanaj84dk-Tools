#include <iostream>
#include <string>
#include <Tanja84dk/Tools/Tools.h>

int main()
{
    bool r = false;
    std::string filenametest = "";
    std::cout << r << std::endl;
    printf("Enter a file there exist: ");
    std::getline(std::cin >> std::ws, filenametest);
    r = Tanja84dk::Tools::doesFileExist(filenametest);
    if (r == true)
    {
        printf("%s Exist", filenametest.c_str());
    }
    return EXIT_SUCCESS;
}