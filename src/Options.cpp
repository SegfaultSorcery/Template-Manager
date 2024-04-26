#include "Options.hpp"
#include <filesystem>
namespace fs = std::filesystem;

Options::Options(){
    template_dir = "/home/vebly/code/Templates";
}
Options::Options(fs::path Template_dir){
    template_dir = Template_dir;
}

void Options::parse(std::vector<std::string>& arg){
    if(arg.empty()){
        _help();
    }
    else if(arg[0] == flags[opts]){
        for(std::string flag : flags){
            std::cout << flag + " ";
        }
        std::cout << std::endl;
    }
    else if(arg[0] == flags[help]){
        _help();
    }
    else if(arg[0] == flags[copy] && arg.size() > 3){
        _copy(arg);
    }
    else if(arg[0] == flags[save]){
        _save(arg);
    }
    else if(arg[0] == flags[browse]){
        _browse(arg);
    }
    else if(arg[0] == flags[temp_dir]){
        _get_template_path(arg);
    }
    else{
        std::cout << "Wrong amount of arguments\n\n";
        _help();
    }
};

void Options::_help(){
    std::string help = R"(
        -h      help
        -c      copy
        -s      save
        -b      browse  
        -p      path to template directory
    )";
    std::cout << help << std::endl;
}
void Options::_copy(std::vector<std::string>& arg){
    fs::path file_path = template_dir;
    file_path / arg[1];
    fs::path destination(arg[2]);

    if(!fs::exists(file_path) || !fs::exists(destination)){
        if(!fs::exists(file_path) ){
            std::cout << "Template: " + file_path.string() + " not found\n\n" ;
        }
        if(!fs::exists(destination)){
            std::cout << "Destination: " + destination.string() + " not found\n\n";
        }
    }
    else{
        fs::copy_file(template_dir / arg[1], fs::path(arg[2]));
    }
}
void Options::_save(std::vector<std::string>& arg){
}
void Options::_browse(std::vector<std::string>& arg){
    std:bool exit = false;
    while(!exit){
        
    }
}
void Options::_get_template_path(std::vector<std::string>& arg){
}
