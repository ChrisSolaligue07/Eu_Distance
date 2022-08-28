//
// Created by chris on 27/08/2022.
//

#ifndef EU_CLUSTER_CREATEDATA_H
#define EU_CLUSTER_CREATEDATA_H
#include <random>


template<class T>
T randomNumber_real() {  // random numbers except int
    std::uniform_real_distribution<T> distribution(1, 1000);
    std::random_device rd;
    std::default_random_engine generator(rd());
    return distribution(generator);
}

int randomNumber_int() {  // random numbers except int
    std::uniform_int_distribution<int> distribution(1, 1000);
    std::random_device rd;
    std::default_random_engine generator(rd());
    return distribution(generator);
}

template <class T>
using v_of_vs = std::vector<std::vector<T>>;

template <class T>
void print(v_of_vs<T> data_){
    for(unsigned long long i = 0; i < data_.size(); i++){
        for(unsigned long long j = 0; j < data_[i].size(); j++){
            std::cout << data_[i][j] << " ";
        }
        std::cout << std:: endl;
    }
}

template <class T>
void create_data_real(int dimension, int data, v_of_vs<T> &data_ ){
    std::vector<T> p1(dimension);
    for (int i = 0; i < data; i++) {
        std::generate(p1.begin(), p1.end(), randomNumber_real<T>);
        data_.push_back(p1);
    }
    // std::cout << data_.size() << " " << data_[0].size() << std::endl;
}

void create_data_int(int dimension, int data, v_of_vs<int> &data_ ){
    std::vector<int> p1(dimension);
    for (int i = 0; i < data; i++) {
        std::generate(p1.begin(), p1.end(), randomNumber_int);
        data_.push_back(p1);
    }
    // std::cout << data_.size() << " " << data_[0].size() << std::endl;
}

#endif //EU_CLUSTER_CREATEDATA_H
