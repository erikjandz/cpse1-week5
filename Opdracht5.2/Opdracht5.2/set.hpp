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
    unsigned int size;
public:
    set(){
        size = 0;
    }

    T max(){
        T max = array[0];
        for(unsigned int i = 1; i < size; i++){
            if(array[i] > max){
                max = array[i];
            }
        }
        return max;
    }


    void add(T number){
        if(size == N){
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

    void remove(T number){
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

    bool contains(T number){
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
