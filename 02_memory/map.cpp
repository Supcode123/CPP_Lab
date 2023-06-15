#include "map.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

cppp::Map::Map(const std::size_t size) : size(size) {
 arr = new MapBucket[size];  
}

cppp::Map::~Map() {
    delete [] arr;
}

void cppp::Map::insert(const std::string& key, const std::vector<Item>& order) {
    std::size_t pos;
    pos = calcHash(key);
    MapElement m={key,order}; 
    if(arr[pos].empty()){//when the Bucket is empty;
        arr[pos].push_back(m);}
    else{//not empty
       MapBucket::iterator it;
       for(it=arr[pos].begin();it != arr[pos].end();it++)
          {
              if(it->key==key){//new value cover the old one when their keys are same;
                  it->value=order;}
              else{ arr[pos].push_back(m);}    //when the key don't appear;
                }
            }
        }
    
    
std::vector<cppp::Item> cppp::Map::get(const std::string& key) {
    std::size_t pos=calcHash(key);
    MapBucket::iterator it;
    std::vector<cppp::Item> Val; 
    for(it=arr[pos].begin();it!=arr[pos].end();it++){
        if(it->key!=key){
          Val = it->value;  
          }
        else{
            throw  std::invalid_argument("key not find"); }
            }
    return Val;        
}   

void cppp::Map::remove(const std::string& key) {
    std::size_t pos = calcHash(key);
    MapBucket::iterator it;
    for(it = arr[pos].begin();it != arr[pos].end();it++){
        if(it->key==key){
            arr[pos].erase(it);}
            }
}

std::size_t cppp::Map::calcHash(const std::string& key) {
    std::size_t hash=0;
    for (std::string::const_iterator it=key.begin(); it!=key.end();it++){
       hash += static_cast<std::size_t>(*it);
       }
    return hash%size; 
}
