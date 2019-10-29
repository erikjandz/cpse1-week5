//Author is Erik de Zeeuw
#ifndef SET_HPP
#define SET_HPP

#include <array>
#include <iostream>
#define CATCH_CONFIG_MAIN

class set{
private:
    std::array<int, 10> array;
    unsigned int size;
public:
    set(){
        size = 0;
    }

    void add(int number){
        if(size == 10){
            return;
        }
        for(unsigned int i = 0; i < size; i++){
            if(array[i] == number){
                return;
            }
        }
        array[size] = number;
        size++;
    }

    void remove(int number){
        for(unsigned int i = 0; i < size; i++){
            if(array[i] == number){
                for(unsigned int j = i; j < size - 1; j++){
                    array[j] = array[j + 1];
                }
                size--;
                return;
            }
        }
    }

    bool contains(int number){
        for(unsigned int i = 0; i < size; i++){
            if(array[i] == number){
                return true;
            }
        }
        return false;
    }

    friend std::ostream & operator<<(std::ostream & lhs, const set & rhs){
        for(unsigned int i = 0; i < rhs.size; i++){
            lhs << rhs.array[i] << '\n';
        }
        return lhs;
    }

};

#endif
