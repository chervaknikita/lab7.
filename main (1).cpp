#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cout << "Введіть кількість рядків (m): ";
    cin >> m;
    cout << "Введіть кількість стовпців (n): ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    vector<vector<int>> result(m, vector<int>(n));

    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < m; ++i) {
        cout << "Рядок " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            result[i][j] = matrix[i][j]; // Копіюємо у допоміжну матрицю
        }
    }

    // Перевірка на локальний мінімум
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            bool isMin = true;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int ni = i + dx;
                    int nj = j + dy;
                    if ((dx != 0 || dy != 0) && ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if (matrix[i][j] >= matrix[ni][nj]) {
                            isMin = false;
                        }
                    }
                }
            }
            if (isMin) {
                result[i][j] = 0;
            }
        }
    }

    cout << "Оновлена матриця:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
