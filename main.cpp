#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include "filetype.h"

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " (filetype) (filename) (filepath default ./)" << std::endl;
        return -1;
    }

    std::string file_type = argv[1];
    std::string file_name = argv[2];
    std::string file_dest;
    std::string default_dest = "./";
    std::string config_file_name = "/home/dusandux/.cfile.conf";

    if(argc != 4)
        file_dest = default_dest;
    else 
        file_dest = argv[3];

    if(file_dest[file_dest.length() - 1] != '/')
        file_dest += "/";

    std::ifstream config_file(config_file_name);

    if(!config_file.is_open())
    {
        std::cerr << "Could not open config file in " << config_file_name << std::endl;
        return 1;
    }

    std::string line;
    std::string start_key = "FILETYPE";
    std::string start_delimiter = " ";
    std::string end_key = "END";

    while(std::getline(config_file, line))
    {
        std::size_t start_index = line.rfind(start_key, 0); 
        if(start_index != std::string::npos)
        {
            std::size_t start_pos = line.find(start_delimiter);;
            // Erase start_key
            line.erase(0, start_pos + start_delimiter.length());

            // Get type of the file 
            std::size_t type_pos = line.find(start_delimiter);
            std::string found_type = line.substr(0, type_pos);
            line.erase(0, type_pos + start_delimiter.length());

            // Compare it to the type user entered
            if(found_type.compare(file_type) == 0)
            {
                std::size_t ext_pos = line.find(start_delimiter);
                std::string found_ext = line.substr(0, ext_pos);
                int starting_pos = config_file.tellg();
                std::string full_name = file_dest + file_name + found_ext;
                return create_file(full_name, config_file_name, end_key,starting_pos);
            }
        }
    }
    std::cerr << file_type << " is missing in configuration!" << std::endl;
    config_file.close();
    return 1;
}
