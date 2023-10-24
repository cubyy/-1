#include <iostream>
#include <cstring>


using namespace std;

int main() {
    int size;
    cout << "Введите количество задач: ";
    cin >> size;

    // Выделяем динамические массивы для названий, дедлайнов и приоритета задач
    char** names = new char* [size];
    char** priority = new char* [size];
    char** date = new char* [size];

    // Ввод названий, дедлайнов и приоритета задач
    for (int i = 0; i < size; ++i) {
        cout << "Введите название задачи " << i + 1 << ": ";
        cin >> names[i];
        char buffer[100];
        cin.getline(buffer, 100);
        names[i] = new char[strlen(buffer) + 1];
        strcpy(names[i], buffer);

        cout << "Введите приоритет задачи " << i + 1 << ": ";
        cin >> priority[i];

        cout << "Введите дату делайна " << i + 1 << ": ";
        cin >> date[i];
    }

    // Сортировка задач по приоритету
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(priority[j], priority[j + 1]) > 0) {
                swap(priority[j], priority[j + 1]);
                swap(names[j], names[j + 1]);
                swap(date[j], date[j + 1]);
            }
        }
    }

    // Вывод отсортированного списка задач
    cout << "\nОтсортированный список задач\n";
    for (int i = 0; i < size; ++i) {
        cout << "Задача: " << names[i] << ", Приоритет: " << priority[i] << ", Дедлайн: " << date[i] << endl;
    }

    return 0;
}