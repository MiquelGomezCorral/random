#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>
#ifndef functions
#define functions
using namespace std;


vector<string> split(string str, char pattern) {
        int posInit = 0;
        int posFound = 0;
        string splitted;
        vector<string> results;
        
        while(posFound >= 0){
            posFound = str.find(pattern, posInit);
            splitted = str.substr(posInit, posFound - posInit);
            posInit = posFound + 1;
            results.push_back(splitted);
        }
        return results;
}
void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;
 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

template <typename T>
bool contains(vector<T> v, T x) {
    bool found = false;
    for(T i : v) {
        found = i==x;
        if(found) break;
    }    
    return found;  
}

#endif