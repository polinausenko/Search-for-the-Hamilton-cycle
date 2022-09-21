#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

class gamelt_cycle {
    int** mat = NULL;
    int** mat1 = NULL;
    int size = 0;
public:
    gamelt_cycle() {
        ifstream file;
        file.open("input.txt");
        if (!file.is_open()) {
            cout << "Ошибка чтения файла";
        }
        else {
            int i, j;
            file >> size;
            if (size > 0) {
                mat = new int* [size];
                for (i = 0; i < size; i++) {
                    mat[i] = new int[size];
                }
                for (i = 0; i < size; i++) {
                    for (j = 0; j < size; j++) {
                        file >> mat[i][j];
                    }
                }
                cout << "Входная матрица: " << endl;
                for (i = 0; i < size; i++) {
                    for (j = 0; j < size; j++) {
                        cout << "\t" << mat[i][j];
                    }
                    cout << endl;
                }

                mat1 = new int* [size];
                for (i = 0; i < size; i++) {
                    mat1[i] = new int[size];
                }

                for (i = 0; i < size; i++) {
                    for (j = 0; j < size; j++) {
                        mat1[i][j] = 0;
                    }
                }

                for (i = 0; i < size; i++) {
                    for (j = 0; j < size; j++) {
                        if (mat[i][j] != 0) {
                            mat1[i][j] = mat[i][j];
                            mat1[j][i] = mat[i][j];
                        }
                    }
                }