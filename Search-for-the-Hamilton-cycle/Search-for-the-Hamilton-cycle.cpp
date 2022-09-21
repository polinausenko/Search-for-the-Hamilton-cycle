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
            }
        }
    }

    bool check_vert(int* D, int nvert) {
        for (int i = 0; i < size; i++) {
            if (D[i] == nvert) {
                return false;
            }
        }
        return true;
    }
    bool add_free(int* D, int nvert) {
        for (int i = 0; i < size; i++) {
            if (D[i] == 0) {
                D[i] = nvert;
                return true;
            }
        }
        return false;
    }
    void del_last(int* D, int k) {
        for (int i = 0; i < size + 1; i++) {
            if (i > k) {
                D[i] = 0;
            }
        }
    }
    void solve_step(int* D, int i, int k) {
        int j;

        if (check_vert(D, i + 1)) {
            D[k] = i + 1;
            for (j = 0; j < size; j++) {
                if (mat[i][j] != 0) {
                    solve_step(D, j, k + 1);
                    del_last(D, k);
                }
            }
        }
        else {
            D[k] = i + 1;
            if (D[0] == D[size]) {

                cout << "\nS = {";
                for (j = 0; j < k + 1; j++) {
                    if (D[j] != 0) {
                        cout << D[j] << " ";
                    }
                }
                cout << "}\n";

                return;
            }
            D[k] = 0;
        }
    }
    void solve() {
        int i, j;
        int* D = new int[size + 1];
        for (i = 0; i < size + 1; i++) {
            D[i] = 0;
        }

        solve_step(D, 0, 0);

    }


};

int main()
{
    system("chcp 1251");
    system("cls");
    setlocale(LC_ALL, "Russian_Russia.1251");

    gamelt_cycle a;
    a.solve();

    system("pause");
}