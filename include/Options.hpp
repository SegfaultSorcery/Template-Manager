#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>

class Options{
public:
    Options();
    Options(std::filesystem::path Template_dir);
    void parse(std::vector<std::string>& arg);

private:
    enum flags_enum{
        opts, help, copy, save, browse, temp_dir
    };

    std::vector<std::string> flags = {"--get-opts", "-h", "-c", "s", "-b", "-p"};
    std::filesystem::path template_dir;
    void _help();
    void _copy(std::vector<std::string>& arg);
    void _save(std::vector<std::string>& arg); 
    void _browse(std::vector<std::string>& arg);
    void _get_template_path(std::vector<std::string>& arg);
};
