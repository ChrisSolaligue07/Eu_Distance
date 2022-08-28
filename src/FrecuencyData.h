//
// Created by chris on 27/08/2022.
//

#ifndef EU_CLUSTER_FRECUENCYDATA_H
#define EU_CLUSTER_FRECUENCYDATA_H

void frecuency_data(std::vector<float> &vec, std::vector<std::pair<int, float>> &frec) {
    std::map<float, int> res;
    for (float & i : vec) {
        if (res.find(i) == res.end()) {
            res[i] = 1;
        }
        else {
            res[i]++;
        }
    }
    for (auto i: res) {
        frec.emplace_back(i.second, i.first);
    }
    /*
    for (auto i : frec){
        std::cout << i.first << " " << i.second << std::endl;
    }
     */
}

#endif //EU_CLUSTER_FRECUENCYDATA_H
