//
// Created by chris on 27/08/2022.
//

#ifndef EU_CLUSTER_CSV_RW_H
#define EU_CLUSTER_CSV_RW_H

#include <fstream>

void create(const std::vector<std::pair<int, float>> &res, int dimension, int vectores){
    std::fstream csv_;
    csv_.open("res_info.csv", std::ios::out);
    csv_ << "frec" << "," << "data" << "," << dimension << "," << vectores << "\n";
    for(auto i : res){
        csv_ << i.first << ", " << i.second << "\n";
    }
}
void create_test(const std::vector<std::pair<int, float>> &res, int case_){
    std::fstream csv_;
    csv_.open("test/res_info"+ std::to_string(case_) +".csv", std::ios::out);
    csv_ << "frec" << "," << "data" << "\n";
    for(auto i : res){
        csv_ << i.first << ", " << i.second << "\n";
    }
    csv_.close();
}

#endif //EU_CLUSTER_CSV_RW_H
