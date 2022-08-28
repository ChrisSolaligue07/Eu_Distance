//
// Created by chris on 27/08/2022.
//

#ifndef EU_CLUSTER_EU_DISTANCE_H
#define EU_CLUSTER_EU_DISTANCE_H
#include "ConvertDm.h"


template <class T>
using v_of_vs = std::vector<std::vector<T>>;

template <class T>
void eu_distance(std::vector<float> &eu_res, v_of_vs<T> data_, int dimension){
    for(unsigned long long i = 0; i < data_.size(); i++){
        eu_res.push_back(dimension_n(data_[0], data_[i], dimension));
    }
    eu_res.erase(eu_res.begin());   // Elimina el primer dato, es el punto contra si mismo.
}

void print_v(std::vector<float> vec){
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<float>(std::cout, " "));
}

#endif //EU_CLUSTER_EU_DISTANCE_H
