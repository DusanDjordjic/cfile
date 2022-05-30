#include <iostream>
#include <fstream>
#include "filetype.h"

void create_cpp(const std::string& file_name, const std::string& path)
{
    std::cout << "Create cpp file by name of \"" << file_name << "\" at " << path << std::endl;
    std::string full_path;
    if(*(path.end() - 1) != '/')
        full_path = path + "/" + file_name + ".cpp";
    else
        full_path = path + file_name + ".cpp";

    std::ofstream file(full_path);

    file << "#include <iostream>\n\nint main(int argc, char* argv[]\n{\n\n\treturn 0;\n}" << std::endl;
    file.close();
}

void create_c(const std::string& file_name, const std::string& path)
{
    std::cout << "Create c file by name of \"" << file_name << "\" at " << path << std::endl;
    std::string full_path;
    if(*(path.end() - 1) != '/')
        full_path = path + "/" + file_name + ".c";
    else
        full_path = path + file_name + ".c";

    std::ofstream file(full_path);

    file << "#include <stdio.h>\n\nint main(int argc, char* argv[]\n{\n\n\treturn 0;\n}" << std::endl;
    file.close();
}

void create_node(const std::string& file_name, const std::string& path)
{
    std::cout << "Create node file by name of " << file_name << " at " << path << std::endl;
    std::string full_path;
    if(*(path.end() - 1) != '/')
        full_path = path + "/" + file_name + ".js";
    else
        full_path = path + file_name + ".js";

    std::ofstream file(full_path);

    file << "const http = require('http');\n\nconst hostname = '127.0.0.1';\nconst port = 3000;\n\nconst server = http.createServer((req, res) => {\n\tres.statusCode = 200;\n\tres.setHeader('Content-Type', 'text/plain');\n\tres.end('Hello World');\n});\n\nserver.listen(port, hostname, () => {\n\tconsole.log(`Server running at http://${hostname}:${port}/`);\n});" << std::endl;
    file.close();
}
