#ifndef _FORMAT_ARRAY_H_
#define _FORMAT_ARRAY_H_

#include <array>

template<class S, class A>
inline S& format_array(S& s, const A& arr, const char *delimiter = ", ", const char *header = "", const char *trailer = "")
{
    s << header;
    if(!arr.empty()) {
        auto b = arr.begin(),   e = arr.end();
        s << *b++;
        for(; b!=e; ++b)
            s << delimiter << *b;
    }
    s << trailer;
    return s;
}

#endif // _FORMAT_ARRAY_H_
