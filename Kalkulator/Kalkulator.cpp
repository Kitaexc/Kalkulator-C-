#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

unsigned long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    setlocale(LC_ALL, "RUS");
    int choice;
    double num1, num2;

    while (true) {
        cout << "Калькулятор" << endl;
        cout << "1. Сложение" << endl;
        cout << "2. Вычитание" << endl;
        cout << "3. Частное" << endl;
        cout << "4. Произведение" << endl;
        cout << "5. Возведение в степень" << endl;
        cout << "6. Квадратный корень" << endl;
        cout << "7. 1% от числа" << endl;
        cout << "8. Факториал числа" << endl;
        cout << "9. Выйти из программы" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;

        if (choice == 9) break;

        if (choice >= 1 && choice <= 5) {
            clearScreen();
            cout << "Введите два числа: ";
            cin >> num1 >> num2;
        }
        else if (choice == 6 || choice == 7 || choice == 8) {
            clearScreen();
            cout << "Введите число: ";
            cin >> num1;
        }

        switch (choice) {
        case 1:
            cout << "Результат: " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Результат: " << num1 - num2 << endl;
            break;
        case 3:
            if (num2 == 0) {
                cout << "Ошибка: деление на ноль" << endl;
            }
            else {
                cout << "Результат: " << num1 / num2 << endl;
            }
            break;
        case 4:
            cout << "Результат: " << num1 * num2 << endl;
            break;
        case 5:
            cout << "Результат: " << pow(num1, num2) << endl;
            break;
        case 6:
            if (num1 >= 0) {
                cout << "Результат: " << sqrt(num1) << endl;
            }
            else {
                cout << "Ошибка: квадратный корень из отрицательного числа" << endl;
            }
            break;
        case 7:
            cout << "Результат: " << num1 * 0.01 << endl;
            break;
        case 8:
            if (num1 >= 0 && floor(num1) == num1) {
                cout << "Результат: " << factorial(static_cast<int>(num1)) << endl;
            }
            else {
                cout << "Ошибка: факториал отрицательного числа или нецелого числа" << endl;
            }
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }

    cout << "Программа завершена." << endl;
    return 0;
}
