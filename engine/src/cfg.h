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
        if (value.empty()) return 0;
        switch (value[0])
        {
        case 'T':
        case 't':
        case '1':
            return 1;
        case 'F':
        case 'f':
            return 0;
        default:
            return 0;
        }
        return atoi(value.c_str()) > 0;
    }

    inline int to_int(str value)
    {
        return atoi(value.c_str());
    }

}   //namespace Engine