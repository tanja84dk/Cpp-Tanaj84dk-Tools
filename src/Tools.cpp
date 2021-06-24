#include <Tools/Tools.h>

namespace Tools
{
    std::string createTimestamp(char const *tzdata)
    /*
    */
    {
        char timeBuffer[80];
        time_t rawtime;
        struct tm* timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(timeBuffer, sizeof(timeBuffer), tzdata, timeinfo);
        std::string timeNow(timeBuffer);
        return timeNow;
    };

    bool doesFileExist(const std::string &filename)
    /*
    */
    {
        std::ifstream _file;
        bool __statusCode;
        _file.open(filename, std::ifstream::in);
        if (_file.is_open())
        {
            __statusCode = true;
        } else {
            __statusCode = false;
        }
        _file.close();
        //std::cout << __statusCode << std::endl;
        return __statusCode;
    };

    void printFile(const std::string &filename)
    {
        bool printFileStatusCode;
        printFileStatusCode = Tools::doesFileExist(filename);
        if ( printFileStatusCode == true )
        {
            std::cout << std::endl;
            std::ifstream fileHandler(filename, std::ifstream::in);
            std::cout << std::endl << fileHandler.rdbuf() << std::endl;
            fileHandler.close();
        }
    }
    
    void writeFile(const std::string &data, const std::string &filename)
    /*
     * Function to write data to files
     */
    {
        std::ofstream fileHandler;
        fileHandler.open(filename);
        fileHandler << data;
        fileHandler.close();
    }
};
