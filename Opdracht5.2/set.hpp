//Author is Erik de Zeeuw
#ifndef SET_HPP
#define SET_HPP

#include <array>
#include <iostream>
#define CATCH_CONFIG_MAIN

template<typename T, unsigned int N>
class set{
private:
    std::array<T, N> array;
    std::array<bool, N> filled;
public:

    set(){
        for(auto & i : array){
            i = 0;
        }
        for(auto & i : filled){
            i = 0;
        }
    }
    
    void add(T number){
        for(unsigned int i = 0; i < array.size(); i++){
            if(array[i] == number && filled[i]){
                return;
            }
        }
        for(unsigned int i = 0; i < array.size(); i++){
            if(!filled[i]){
                array[i] = number;
                filled[i] = true;
                return;
            }
        }
        return;
    }
    
    void remove(T number){
        for(unsigned int i = 0; i < array.size(); i++){
            if(array[i] == number && filled[i]){
                array[i] = 0;
                filled[i] = false;
                return;
            }
        }
    }
    
    bool contains(T number){
        for(unsigned int i = 0; i < array.size(); i++){
            if(array[i] == number && filled[i]){
                return true;
            }
        }
        return false;
    }
    
    friend std::ostream & operator<<(std::ostream & lhs, const set & rhs){
        for(unsigned int i = 0; i < rhs.array.size(); i++){
            if(rhs.filled[i]){
                lhs << rhs.array[i] << '\n';
            }
        }
        return lhs;
    }
    
};

#endif