#include "cfg.h"
#include "utility/utility.h"
using namespace Engine;


_CFG_Analyzer::_CFG_Analyzer(const char* _filepath):
    filepath(_filepath){
        if(!fetch())
            printf("Cannot fetch data from 'format.cfg'\n\n");
}

_CFG_Analyzer::~_CFG_Analyzer()
{
    if(is.is_open()) is.close();
}

inline bool is_space(const char ch)
{
    return ch==' ' || ch=='\t';
}

inline void trim(str &_str)
{
    if(_str.empty()) goto END;

    size_t fpos, epos;
    for(fpos=0;fpos<_str.size();++fpos)
    {
        if(is_space(_str[fpos])) continue;
        break;
    }

    for(epos=_str.size()-1;epos>=0;--epos)
    {
        if(is_space(_str[epos])) continue;
        break;
    }

    _str = _str.substr(fpos, epos-fpos+1);

    END:;
}


inline pair analyze(str _line)
{
    str key, value;

    int pos ;

    if((pos = _line.find(COMMENT_CHAR)) != -1)
    {
        _line = _line.substr(0, pos);
    }

    if((pos = _line.find_first_of('=')) == -1)
    {
        key = "None";
        value = "None";
    }
    else
    {
        key = _line.substr(0, pos);
        trim(key);

        value = _line.substr(pos+1);
        trim(value);
    }

    return make_pair(key, value);
}

bool _CFG_Analyzer::fetch()
{
    Utility::Logger().System("Fetching data from the configuration...\n");

    this->is.open(this->filepath);
    if(this->is.fail()) 
        return false;

    this->map.clear();

    str line;

    while(getline(this->is, line))
    {
        if(line.empty() || line[0]==COMMENT_CHAR) continue;

        this->map.insert(analyze(line));
    }

    this->is.close();

    return true;
}

str _CFG_Analyzer::get(const str key)
{
    return this->map[key];
}