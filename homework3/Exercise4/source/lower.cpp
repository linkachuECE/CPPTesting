#include "../include/lower.h"

std::string lower(std::string data){
    std::transform(data.begin(), data.end(), data.begin(),
        [](unsigned char c){ return std::tolower(c); });
    
    return data;
}