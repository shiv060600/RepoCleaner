#ifndef CODECLEANER_DEFINER_H
#define CODECLEANER_DEFINTER_H
#include <string>

class CodeCleaner{
    public:
        CodeCleaner(std::string &root_path, std::string &removal_type, std::string &removal_key);
        ~CodeCleaner();
        void Clean();

    
    private:
        std::string _root_path;
        std::string _removal_type;
        std::string _removal_key;

};


#endif
