//
// Created by chris on 27/08/2022.
//

#ifndef EU_CLUSTER_CONVERTDM_H
#define EU_CLUSTER_CONVERTDM_H

template<class T>
T dimension_1(T xi, T xj) {
    return std::pow(xi - xj, 2);
}
template<class T>
float dimension_n(std::vector<T> xi, std::vector<T> xj, int dimension) {
    // n = dimension.
    // xi = un punto con n dimensiones.
    // xj = un punto con n dimensiones.
    float res = 0;
    for(int i = 0; i < dimension; i++)
        res = res + (dimension_1(xi[i], xj[i]));
    res = std::sqrt(res);
    return std::truncf(res * 10) / 10;
}

#endif //EU_CLUSTER_CONVERTDM_H
