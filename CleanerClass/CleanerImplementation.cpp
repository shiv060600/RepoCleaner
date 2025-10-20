#include <iostream>
#include <string>
#include <filesystem>
#include "CleanerDefiner.h"


CodeCleaner::CodeCleaner(std::string &root_path, std::string &removal_type, std::string &removal_key){
    this->_root_path = root_path;
    this->_removal_type = removal_type;
    this->_removal_key = removal_key;
}

void CodeCleaner::Clean(){
    std::filesystem::path rootPath(_root_path);
    std::error_code ec;

    if (!std::filesystem::exists(rootPath,ec)){
        std::cout << "This path does not exist" << std::endl;
        std::cout << "error" << ec.message() << std::endl;
        std::exit(EXIT_FAILURE);
    }

    auto options = std::filesystem::directory_options::skip_permission_denied;

    for(std::filesystem::recursive_directory_iterator it(rootPath,options,ec),end; it != end; it.increment(ec)){
        if (ec){
            std::cout << "Error: " << ec.message() << std::endl;
            ec.clear();
            continue;
        }
        
        //use *it to get the current object the iterator is at
        const auto& currObject = *it; 
        const auto& currObjectPath = currObject.path();
        std::string currObjectFilename = currObjectPath.filename().string();

        bool matches = false;
        
        if(_removal_type == "A"){
            //case starts with
            if(currObjectFilename.starts_with(_removal_key) == true){
                matches = true;
            }
        } else if(_removal_type == "B"){
            if(currObjectFilename.ends_with(_removal_key) == true){
                matches = true;
            }
        }else{
            //case contaiins
            if(currObjectFilename.find(_removal_key) != std::string::npos){
                matches = true;
            }
        }
    }




}


