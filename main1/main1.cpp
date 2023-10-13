#include <iostream>
#include "data.h"

using namespace std;

int main() {
    setlocale(0, "");
    int choice;

    while (true) {
        cout << "===============================================" << endl;
        cout << "Меню:" << endl;
        cout << "1. Добавить менеджера" << endl;
        cout << "2. Удалить менеджера" << endl;
        cout << "3. Редактировать информацию о менеджере" << endl;
        cout << "4. Вывести список менеджеров" << endl;
        cout << "5. Поиск по фамилии менеджера" << endl;
        cout << "6. Добавить компьютер" << endl;
        cout << "7. Удалить компьютер" << endl;
        cout << "8. Редактировать информацию о компьютере" << endl;
        cout << "9. Вывести список компьютеров" << endl;
        cout << "10. Добавить комплектующую" << endl;
        cout << "11. Удалить комплектующую" << endl;
        cout << "12. Редактировать информацию о комплектующей" << endl;
        cout << "13. Вывести список комплектующих" << endl;
        cout << "14. Сохранить данные в файл" << endl;
        cout << "15. Загрузить данные из файла" << endl;
        cout << "16. Выйти" << endl;
        cout << "Выберите действие: " << endl;
        cout << "===============================================" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            addManager();
            break;
        case 2:
            deleteManager();
            break;
        case 3:
            editManager();
            break;
        case 4:
            listManagers();
            break;
        case 5:
            searchByLastName();
            break;
        case 6:
            addComputer();
            break;
        case 7:
            deleteComputer();
            break;
        case 8:
            editComputer();
            break;
        case 9:
            listComputers();
            break;
        case 10:
            addComponent();
            break;
        case 11:
            deleteComponent();
            break;
        case 12:
            editComponent();
            break;
        case 13:
            listComponents();
            break;
        case 14:
            saveDataToFile();
            break;
        case 15:
            loadDataFromFile();
            break;
        case 16:
            cout << "До свидания!" << endl;
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}


