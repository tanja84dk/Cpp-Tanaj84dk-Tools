#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <vector>

namespace Tanja84dk::Tools
{
	std::string createTimestamp(char const *tzdata);
	bool doesFileExist(const std::string &filename);
	std::string readFile(const std::string &filename);
	std::string removeExtention(const std::string &inputFilename);
	void writeFile(const std::string &data, const std::string &filename);
	void writeFile(const std::vector<std::bitset<8>> &data, const std::string &filename);
	void printFile(const std::string &filename);
}