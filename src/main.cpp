#include <iostream>
#include <string>
#include <unistd.h> //gcwd  
#include <filesystem>
#include <vector>

#include "get_cwd.hpp"
#include "Options.hpp"



int main(int argc, char* argv[]){
    Options options;
    std::string cwd = get_cwd();
    std::vector<std::string> arg;
    for(int i = 1; i < argc; i++){
        arg.push_back(argv[i]);
    }
    if(!arg.empty()){
        options.parse(arg);
    }
}



