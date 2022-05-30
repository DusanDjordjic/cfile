#include <iostream>
#include <string.h>

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Usage: " << argv[0] << "--(filetype)" << std::endl;
        return -1;
    }

    char * fileType = argv[1];
    if(strcmp(fileType, "cpp") == 0)
        std::cout << "CPP" << std::endl;
    else if(strcmp(fileType, "c") == 0)
        std::cout << "C" << std::endl;
    else
        std::cout << argv[1] << " is not supported yet!" << std::endl;
   
    return 0;
}
