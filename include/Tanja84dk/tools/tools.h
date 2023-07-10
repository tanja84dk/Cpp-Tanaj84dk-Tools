#pragma once

#include <string>
#include <vector>
#include <bitset>

namespace Tanja84dk::tools
{
	std::string get_timestamp(char const *tzdata);
	bool file_exists(const std::string &filename);
	std::string read_file(const std::string &filename);
	std::string remove_extention(const std::string &inputFilename);
	void write_file(const std::string &data, const std::string &filename) noexcept;
	void write_file(const std::string &data, const std::string &filename, bool append) noexcept;
	void write_file(const std::vector<std::bitset<8>> &data, const std::string &filename) noexcept;
	void write_file(const std::vector<std::bitset<8>> &data, const std::string &filename, bool append) noexcept;
	void print_file(const std::string &filename);
}