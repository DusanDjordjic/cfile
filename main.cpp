#include <iostream>
#include <string.h>
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

    if(argc != 4)
        file_dest = default_dest;
    else 
        file_dest = argv[3];


    if(file_type.compare("cpp") == 0)
    {
        create_cpp(file_name, file_dest);
    }
    else if(file_type.compare("c") == 0)
    {
        create_c(file_name, file_dest);
    }
    else if (file_type.compare("node") == 0)
    {
        create_node(file_name, file_dest);
    }
    else
        std::cout << argv[1] << " is not supported yet!" << std::endl;
   
    return 0;
}
