#include <iostream>
#include <string>
#include <Tanja84dk/tools/tools.h>

int main()
{
    bool r = false;
    std::string filenametest = "";
    std::cout << r << std::endl;
    printf("Enter a file there exist: ");
    std::getline(std::cin >> std::ws, filenametest);
    r = Tanja84dk::tools::file_exists(filenametest);
    if (r == true)
    {
        printf("%s Exist", filenametest.c_str());
    }
    return EXIT_SUCCESS;
}