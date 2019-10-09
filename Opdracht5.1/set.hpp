//Author is Erik de Zeeuw
#ifndef SET_HPP
#define SET_HPP

#include <array>
#include <iostream>
#define CATCH_CONFIG_MAIN

class set{
private:
    std::array<int, 10> array;
    std::array<bool, 10> filled;
public:

    set(){
        for(auto & i : array){
            i = 0;
        }
        for(auto & i : filled){
            i = 0;
        }
    }
    
    void add(int number){
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
    
    void remove(int number){
        for(unsigned int i = 0; i < array.size(); i++){
            if(array[i] == number && filled[i]){
                array[i] = 0;
                filled[i] = false;
                return;
            }
        }
    }
    
    bool contains(int number){
        for(unsigned int i = 0; i < array.size(); i++){
            if(array[i] == number && filled[i]){
                return true;
            }
        }
        return false;
    }
    
    friend std::ostream & operator<<(std::ostream & lhs, const set & rhs);
    
};

std::ostream & operator<<(std::ostream & lhs, const set & rhs){
        for(unsigned int i = 0; i < rhs.array.size(); i++){
            if(rhs.filled[i]){
                lhs << rhs.array[i] << '\n';
            }
        }
        return lhs;
}

#endif