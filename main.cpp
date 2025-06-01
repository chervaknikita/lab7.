#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, k;
    
    // Ввід розмірів матриці
    cout << "Введіть кількість рядків (m): ";
    cin >> m;
    cout << "Введіть кількість стовпців (n): ";
    cin >> n;
    
    // Ініціалізація матриці
    vector<vector<int>> matrix(m, vector<int>(n));
    
    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < m; ++i) {
        cout << "Рядок " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Ввід номера рядка
    cout << "Введіть номер рядка K (1 ≤ K ≤ " << m << "): ";
    cin >> k;

    // Перевірка коректності значення k
    if (k < 1 || k > m) {
        cout << "Помилка: Невірний номер рядка." << endl;
        return 1;
    }

    // Обчислення суми та добутку
    int sum = 0;
    int product = 1;
    for (int j = 0; j < n; ++j) {
        sum += matrix[k - 1][j];
        product *= matrix[k - 1][j];
    }

    // Виведення результатів
    cout << "Сума елементів " << k << "-го рядка: " << sum << endl;
    cout << "Добуток елементів " << k << "-го рядка: " << product << endl;

    return 0;
}
