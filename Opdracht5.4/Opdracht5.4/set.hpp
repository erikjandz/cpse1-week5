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

    T get(unsigned int index){
        if(index >= size){
          index = size;
        }
        return array[index];
    }

    T max(){
        if(size == 0){
            for(;;){}
        }
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

bool operator>(const std::array<char, 3> & lhs, const std::array<char, 3> & rhs){
    char max1 = lhs[0];
    if(lhs[1] > max1){
        max1 = lhs[1];
    }
    if(lhs[2] > max1){
        max1 = lhs[2];
    }
    char max2 = lhs[0];
    if(lhs[1] > max2){
        max2 = lhs[1];
    }
    if(lhs[2] > max2){
        max2 = lhs[2];
    }
    return max1 > max2;
}
#endif
