#include <Tanja84dk/tools/tools.h>

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <filesystem>

namespace Tanja84dk::tools
{
  std::string get_timestamp(char const *tzdata)
  /*
   * Creating a timestamp string
   */
  {
    char time_buffer[80];
    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(time_buffer, sizeof(time_buffer), tzdata, time_info);
    std::string time_stamp_now(time_buffer);
    return time_stamp_now;
  };

  bool file_exists(const std::string &filename)
  /*
   * Checking if the ile exist and return a bool
   */
  {
    const std::filesystem::path p = filename;
    return (std::filesystem::exists(p));
  };

  void print_file(const std::string &filename)
  /*
   * Printing a file to console
   */
  {
    bool status_code_bool;
    status_code_bool = Tanja84dk::tools::file_exists(filename);
    if (status_code_bool == true)
    {
      std::cout << std::endl;
      std::ifstream file_handler(filename, std::ifstream::in);
      std::cout << std::endl
                << file_handler.rdbuf() << std::endl;
      file_handler.close();
    }
  }

  std::string read_file(const std::string &filename)
  {
    std::string output_data_string;
    std::ifstream file_handler(filename, std::ifstream::in);
    file_handler.seekg(0, std::ios::end);
    output_data_string.reserve(file_handler.tellg());
    file_handler.seekg(0, std::ios::beg);
    output_data_string.assign((std::istreambuf_iterator<char>(file_handler)),
                              std::istreambuf_iterator<char>());
    return output_data_string;
  }

  std::string remove_extention(const std::string &filename)
  /*
   * Remove the extention from the filename
   */
  {
    size_t pos_last_dot;

    pos_last_dot = filename.find_last_of('.');
    return filename.substr(0, pos_last_dot);
  }

  void write_file(const std::string &data, const std::string &filename) noexcept
  {
    Tanja84dk::tools::write_file(data, filename, false);
  }

  void write_file(const std::string &data, const std::string &filename, bool append = false) noexcept
  /*
   * Writing string to a text file
   */
  {
    std::ofstream file_handler;
    if (append == true)
    {
      file_handler.open(filename, std::ios_base::app);
    }
    else
    {
      file_handler.open(filename);
    }
    file_handler << data;
    file_handler.close();
  }

  void write_file(const std::vector<std::bitset<8>> &data, const std::string &filename) noexcept
  {
    Tanja84dk::tools::write_file(data, filename, false);
  }

  void write_file(const std::vector<std::bitset<8>> &data, const std::string &filename, bool append) noexcept
  /*
   * Writing the Binary Ascii to a text file
   */
  {
    std::ofstream file_handler;
    if (append == true)
    {
      file_handler.open(filename, std::ios_base::app);
    }
    else
    {
      file_handler.open(filename);
    }

    for (size_t i = 0; i < data.size(); i++)
    {
      file_handler << data[i];
      if (i != data.size() - 1)
      {
        file_handler << ' ';
      }
    }
    file_handler.close();
  }
};