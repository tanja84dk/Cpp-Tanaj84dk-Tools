#ifndef TOOLS_TOOLS_H
#define TOOLS_TOOLS_H

#include <iostream>
#include <string>
#include <fstream>

namespace Tools
{
	std::string createTimestamp(char const *tzdata);
	bool doesFileExist(const std::string &filename);
	void writeFile(const std::string &data,const std::string &filename);
	void printFile(const std::string &filename);
}

#endif // !TOOLS_TOOLS_H
