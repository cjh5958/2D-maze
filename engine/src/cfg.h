#pragma once

#include <fstream>
#include <string>
#include <map>


typedef std::string str;
typedef std::pair<str, str> pair;
typedef std::map<str, str> Map;

#define COMMENT_CHAR '#'

namespace Engine{

    class _CFG_Analyzer
    {
    public:
        

    private:
        Map map;

        const char *filepath;
        std::ifstream is;

        bool fetch();

    public:
        str get(const str);

        _CFG_Analyzer(const char*);
        ~_CFG_Analyzer();

    };  //class _CFG_Analyzer

    inline bool to_bool(const str value)
    {
        return value == "true";
    }

}   //namespace Engine