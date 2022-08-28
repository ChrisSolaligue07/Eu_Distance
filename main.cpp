#include <algorithm>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <random>
#include "src/ConvertDm.h"
#include "src/CreateData.h"
#include "src/EU_distance.h"
#include "src/FrecuencyData.h"
#include "src/csv_rw.h"
using namespace std;


void test_(){
    vector<vector<float>> data_float;
    vector<float> distancia_eu;
    vector<pair<int, float>> frec_data;

    int test[5] = {10, 20, 30, 40, 50};
    int test_vec[5] = {10000, 20000, 30000, 40000, 50000};
    int x = 1;

    // 10 dimensiones -> 10k, 20k, 30k, 40k, 50k
    // 20 dimensiones -> 10k, 20k, 30k, 40k, 50k
    // 30 dimensiones -> 10k, 20k, 30k, 40k, 50k
    // 40 dimensiones -> 10k, 20k, 30k, 40k, 50k
    // 50 dimensiones -> 10k, 20k, 30k, 40k, 50k

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            // cout << test[i] << " - " << test_vec[j] << " - " <<  x << endl;
            
            create_data_real(test[i], test_vec[j], data_float);
            eu_distance(distancia_eu, data_float, test[i]);
            frecuency_data(distancia_eu, frec_data);
            create_test(frec_data, x);

            data_float.clear();
            distancia_eu.clear();
            frec_data.clear();
            cout << "Archivo " << x << " creado." << endl;
            x++;
        }
        
    }
    
}

int main() {
    bool test;

    cout << "Realizar test completo[1]\nRealizar test unitario[0]\n-> ";
    cin >> test;
    if (test) {
        test_();
    } else {
        vector<vector<int>> data_int;
        vector<vector<float>> data_float;
        vector<float> distancia_eu;
        vector<pair<int, float>> frec_data;
        int dimensiones, c_datos;
        bool tpo_dato;

        cout << "Ingrese la cantidad de dimensiones:" << endl; // Dimensiones
        cin >> dimensiones;
        cout << "Datos de tipo int [1]\nDatos de tipo float[0]\n-> " << endl;    // int o float
        cin >> tpo_dato;
        cout << "Ingrese la cantidad de datos/vectores:" << endl;   // Cantidad de vectores - datos
        cin >> c_datos;

        if(tpo_dato){   // INT
            create_data_int(dimensiones, c_datos, data_int);
            // print(data_int);
            eu_distance(distancia_eu, data_int, dimensiones);
            // print_v(distancia_eu);
            frecuency_data(distancia_eu, frec_data);
            create(frec_data, dimensiones, c_datos);
        } else {    // Float, double
            create_data_real(dimensiones, c_datos, data_float);
            // print(data_float);
            eu_distance(distancia_eu, data_float, dimensiones);
            // print_v(distancia_eu);
            frecuency_data(distancia_eu, frec_data);
            create(frec_data, dimensiones, c_datos);
        }
    }
    return 0;
}