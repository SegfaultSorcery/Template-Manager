#include "Logger.hpp"

void Logger::help(){
    std::string help = R"(
        -h      help
        -g      get 
        -s      save
        -b      browse  
        -p      path to template directory
    )";
    std::cout << help << std::endl;
}
void Logger::get(){
    std::cout << "-g <filename> <location>\n";
}

