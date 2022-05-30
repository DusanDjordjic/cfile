#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include "filetype.h"

int create_file(const std::string& full_path, const std::string& config_file_name, const std::string end_key, int starting_pos)
{
    std::string line;
    std::ifstream config_file(config_file_name);
    if(!config_file.is_open())
    {
        std::cerr << "Error while reading file " << config_file_name << std::endl;
        return 1;
    }

    config_file.seekg(starting_pos);
    std::ofstream output_file(full_path);
    if(!output_file.is_open())
    {
        std::cerr << "Error while writing file " << full_path << std::endl;
        return 2;
    }

    while(std::getline(config_file, line))
    {
        std::size_t end_index = line.rfind(end_key, 0); 
        if(end_index != std::string::npos)
        {
            std::cout << "Created file at " << full_path << std::endl;
            config_file.close();
            output_file.close();
            return 0;
        }
        output_file << line << '\n';
    }
   
    std::cout << "ERROR: Did not find " << end_key << std::endl;
    std::cout << "Created file at " << full_path << std::endl;
    config_file.close();
    output_file.close();

    return 0;
}
