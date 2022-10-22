#include <Tanja84dk/Tools/Tools.h>

namespace Tanja84dk::Tools
{
    std::string createTimestamp(char const *tzdata)
    /*
     * Creating a timestamp string
     */
    {
        char timeBuffer[80];
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(timeBuffer, sizeof(timeBuffer), tzdata, timeinfo);
        std::string timeNow(timeBuffer);
        return timeNow;
    };

    bool doesFileExist(const std::string &filename)
    /*
     * Checking if the ile exist and return a bool
     */
    {
        const std::filesystem::path p = filename;
        return (std::filesystem::exists(p));
    };

    void printFile(const std::string &filename)
    /*
     * Printing a file to console
     */
    {
        bool StatusCode;
        StatusCode = Tools::doesFileExist(filename);
        if (StatusCode == true)
        {
            std::cout << std::endl;
            std::ifstream fileHandler(filename, std::ifstream::in);
            std::cout << std::endl
                      << fileHandler.rdbuf() << std::endl;
            fileHandler.close();
        }
    }

    std::string readFile(const std::string &filename)
    {
        std::string outputData;
        std::ifstream fileHandler(filename, std::ifstream::in);
        fileHandler.seekg(0, std::ios::end);
        outputData.reserve(fileHandler.tellg());
        fileHandler.seekg(0, std::ios::beg);
        outputData.assign((std::istreambuf_iterator<char>(fileHandler)),
                          std::istreambuf_iterator<char>());
        return outputData;
    }

    std::string removeExtention(const std::string &inputFilename)
    /*
     * Remove the extention from the filename
     */
    {
        size_t lastDot;

        lastDot = inputFilename.find_last_of('.');
        return inputFilename.substr(0, lastDot);
    }

    void writeFile(const std::string &data, const std::string &filename)
    /*
     * Writing string to a text file
     */
    {
        std::ofstream fileHandler;
        fileHandler.open(filename);
        fileHandler << data;
        fileHandler.close();
    }

    void writeFile(const std::vector<std::bitset<8>> &data, const std::string &filename)
    /*
     * Writing the Binary Ascii to a text file
     */
    {
        std::ofstream fileHandler;
        fileHandler.open(filename);
        for (size_t i = 0; i < data.size(); i++)
        {
            fileHandler << data[i];
            if (i != data.size() - 1)
            {
                fileHandler << ' ';
            }
        }
        fileHandler.close();
    }
};