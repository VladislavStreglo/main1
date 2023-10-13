#include "data.h"
#include <iostream>
#include <cstring>

using namespace std;

Manager managers[MAX_MANAGERS];
Computer computers[MAX_COMPUTERS];
Component components[MAX_COMPONENTS];

int managerCount = 0;
int computerCount = 0;
int componentCount = 0;

// Функция для сохранения данных в файл
void saveDataToFile() {
    FILE* outFile;
    if (fopen_s(&outFile, "data.bin", "wb") != 0) {
        cerr << "Не удалось открыть файл для записи." << endl;
        return;
    }

    size_t writeResult;
    writeResult = fwrite(&managerCount, sizeof(managerCount), 1, outFile);
    if (writeResult != 1) {
        cerr << "Ошибка при записи в файл." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(managers, sizeof(Manager), managerCount, outFile);
    if (writeResult != managerCount) {
        cerr << "Ошибка при записи в файл." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(&computerCount, sizeof(computerCount), 1, outFile);
    if (writeResult != 1) {
        cerr << "Ошибка при записи в файл." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(computers, sizeof(Computer), computerCount, outFile);
    if (writeResult != computerCount) {
        cerr << "Ошибка при записи в файл." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(&componentCount, sizeof(componentCount), 1, outFile);
    if (writeResult != 1) {
        cerr << "Ошибка при записи в файл." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(components, sizeof(Component), componentCount, outFile);
    if (writeResult != componentCount) {
        cerr << "Ошибка при записи в файл." << endl;
        fclose(outFile);
        return;
    }

    fclose(outFile);
    cout << "Данные успешно сохранены в файл." << endl;
}

// Функция для загрузки данных из файла
void loadDataFromFile() {
    FILE* inFile;
    if (fopen_s(&inFile, "data.bin", "rb") != 0) {
        cerr << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    size_t readResult;
    readResult = fread(&managerCount, sizeof(managerCount), 1, inFile);
    if (readResult != 1) {
        cerr << "Ошибка при чтении из файла." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(managers, sizeof(Manager), managerCount, inFile);
    if (readResult != managerCount) {
        cerr << "Ошибка при чтении из файла." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(&computerCount, sizeof(computerCount), 1, inFile);
    if (readResult != 1) {
        cerr << "Ошибка при чтении из файла." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(computers, sizeof(Computer), computerCount, inFile);
    if (readResult != computerCount) {
        cerr << "Ошибка при чтении из файла." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(&componentCount, sizeof(componentCount), 1, inFile);
    if (readResult != 1) {
        cerr << "Ошибка при чтении из файла." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(components, sizeof(Component), componentCount, inFile);
    if (readResult != componentCount) {
        cerr << "Ошибка при чтении из файла." << endl;
        fclose(inFile);
        return;
    }

    fclose(inFile);
    cout << "Данные успешно загружены из файла." << endl;
}

// Функция для добавления менеджера
void addManager() {
    if (managerCount < MAX_MANAGERS) {
        Manager manager;
        cout << "Введите фамилию менеджера: ";
        cin >> manager.lastName;
        cout << "Введите имя менеджера: ";
        cin >> manager.firstName;
        cout << "Введите отчество менеджера: ";
        cin >> manager.middleName;
        cout << "Введите должность менеджера: ";
        cin.ignore();
        cin.getline(manager.position, MAX_STRING_LENGTH);
        cout << "Введите номер телефона менеджера: ";
        cin >> manager.phone;

        managers[managerCount++] = manager;

        cout << "Менеджер успешно добавлен!" << endl;
    }
    else {
        cout << "Достигнут максимальный лимит менеджеров." << endl;
    }
}

// Функция для удаления менеджера по фамилии
void deleteManager() {
    char lastName[MAX_STRING_LENGTH];
    cout << "Введите фамилию менеджера для удаления: ";
    cin >> lastName;

    for (int i = 0; i < managerCount; ++i) {
        if (strcmp(managers[i].lastName, lastName) == 0) {
            for (int j = i; j < managerCount - 1; ++j) {
                managers[j] = managers[j + 1];
            }
            --managerCount;
            cout << "Менеджер успешно удален!" << endl;
            return;
        }
    }

    cout << "Менеджер с фамилией '" << lastName << "' не найден." << endl;
}

// Функция для редактирования информации о менеджере
void editManager() {
    char lastName[MAX_STRING_LENGTH];
    cout << "Введите фамилию менеджера для редактирования: ";
    cin >> lastName;

    for (int i = 0; i < managerCount; ++i) {
        if (strcmp(managers[i].lastName, lastName) == 0) {
            cout << "Введите новую фамилию: ";
            cin >> managers[i].lastName;
            cout << "Введите новое имя: ";
            cin >> managers[i].firstName;
            cout << "Введите новое отчество: ";
            cin >> managers[i].middleName;
            cout << "Введите новую должность: ";
            cin.ignore();
            cin.getline(managers[i].position, MAX_STRING_LENGTH);
            cout << "Введите новый номер телефона: ";
            cin >> managers[i].phone;
            cout << "Информация о менеджере успешно отредактирована!" << endl;
            return;
        }
    }

    cout << "Менеджер с фамилией '" << lastName << "' не найден." << endl;
}

// Функция для вывода списка менеджеров
void listManagers() {
    if (managerCount == 0) {
        cout << "Список менеджеров пуст." << endl;
        return;
    }

    cout << "Список менеджеров:" << endl;
    for (int i = 0; i < managerCount; ++i) {
        cout << "Фамилия: " << managers[i].lastName << endl;
        cout << "Имя: " << managers[i].firstName << endl;
        cout << "Отчество: " << managers[i].middleName << endl;
        cout << "Должность: " << managers[i].position << endl;
        cout << "Номер телефона: " << managers[i].phone << endl;
        cout << "---------------------------" << endl;
    }
}

// Функция для осуществления поиска по фамилии менеджера
void searchByLastName() {
    char lastName[MAX_STRING_LENGTH];
    cout << "Введите фамилию менеджера для поиска: ";
    cin >> lastName;

    cout << "Результаты поиска:" << endl;
    for (int i = 0; i < managerCount; ++i) {
        if (strcmp(managers[i].lastName, lastName) == 0) {
            cout << "Фамилия: " << managers[i].lastName << endl;
            cout << "Имя: " << managers[i].firstName << endl;
            cout << "Отчество: " << managers[i].middleName << endl;
            cout << "Должность: " << managers[i].position << endl;
            cout << "Номер телефона: " << managers[i].phone << endl;
            cout << "---------------------------" << endl;
        }
    }
}

// Функция для добавления компьютера
void addComputer() {
    if (computerCount < MAX_COMPUTERS) {
        Computer computer;
        cout << "Введите название компьютера: ";
        cin.ignore();
        cin.getline(computer.name, MAX_STRING_LENGTH);
        cout << "Введите конфигурацию компьютера: ";
        cin.getline(computer.configuration, MAX_STRING_LENGTH);
        cout << "Введите количество комплектующих: ";
        cin >> computer.componentCount;

        cout << "Введите названия комплектующих:" << endl;
        for (int i = 0; i < computer.componentCount; ++i) {
            cin.ignore();
            cin.getline(computer.components[i], MAX_STRING_LENGTH);
        }

        computers[computerCount++] = computer;

        cout << "Компьютер успешно добавлен!" << endl;
    }
    else {
        cout << "Достигнут максимальный лимит компьютеров." << endl;
    }
}

// Функция для удаления компьютера по названию
void deleteComputer() {
    char name[MAX_STRING_LENGTH];
    cout << "Введите название компьютера для удаления: ";
    cin.ignore();
    cin.getline(name, MAX_STRING_LENGTH);

    for (int i = 0; i < computerCount; ++i) {
        if (strcmp(computers[i].name, name) == 0) {
            for (int j = i; j < computerCount - 1; ++j) {
                computers[j] = computers[j + 1];
            }
            --computerCount;
            cout << "Компьютер успешно удален!" << endl;
            return;
        }
    }

    cout << "Компьютер с названием '" << name << "' не найден." << endl;
}

// Функция для редактирования информации о компьютере
void editComputer() {
    char name[MAX_STRING_LENGTH];
    cout << "Введите название компьютера для редактирования: ";
    cin.ignore();
    cin.getline(name, MAX_STRING_LENGTH);

    for (int i = 0; i < computerCount; ++i) {
        if (strcmp(computers[i].name, name) == 0) {
            cout << "Введите новое название компьютера: ";
            cin.getline(computers[i].name, MAX_STRING_LENGTH);
            cout << "Введите новую конфигурацию компьютера: ";
            cin.getline(computers[i].configuration, MAX_STRING_LENGTH);
            cout << "Введите новое количество комплектующих: ";
            cin >> computers[i].componentCount;

            cout << "Введите названия комплектующих:" << endl;
            for (int j = 0; j < computers[i].componentCount; ++j) {
                cin.ignore();
                cin.getline(computers[i].components[j], MAX_STRING_LENGTH);
            }

            cout << "Информация о компьютере успешно отредактирована!" << endl;
            return;
        }
    }

    cout << "Компьютер с названием '" << name << "' не найден." << endl;
}

// Функция для вывода списка компьютеров
void listComputers() {
    if (computerCount == 0) {
        cout << "Список компьютеров пуст." << endl;
        return;
    }

    cout << "Список компьютеров:" << endl;
    for (int i = 0; i < computerCount; ++i) {
        cout << "Название: " << computers[i].name << endl;
        cout << "Конфигурация: " << computers[i].configuration << endl;
        cout << "Количество комплектующих: " << computers[i].componentCount << endl;
        cout << "Комплектующие:" << endl;
        for (int j = 0; j < computers[i].componentCount; ++j) {
            cout << "  - " << computers[i].components[j] << endl;
        }
        cout << "---------------------------" << endl;
    }
}

// Функция для добавления комплектующей
void addComponent() {
    if (componentCount < MAX_COMPONENTS) {
        Component component;
        cout << "Введите название комплектующей: ";
        cin.ignore();
        cin.getline(component.name, MAX_STRING_LENGTH);
        cout << "Введите производителя комплектующей: ";
        cin.getline(component.manufacturer, MAX_STRING_LENGTH);
        cout << "Введите характеристики комплектующей: ";
        cin.getline(component.features, MAX_STRING_LENGTH);
        cout << "Введите стоимость комплектующей: ";
        cin >> component.cost;

        components[componentCount++] = component;

        cout << "Комплектующая успешно добавлена!" << endl;
    }
    else {
        cout << "Достигнут максимальный лимит комплектующих." << endl;
    }
}

// Функция для удаления комплектующей по названию
void deleteComponent() {
    char name[MAX_STRING_LENGTH];
    cout << "Введите название комплектующей для удаления: ";
    cin.ignore();
    cin.getline(name, MAX_STRING_LENGTH);

    for (int i = 0; i < componentCount; ++i) {
        if (strcmp(components[i].name, name) == 0) {
            for (int j = i; j < componentCount - 1; ++j) {
                components[j] = components[j + 1];
            }
            --componentCount;
            cout << "Комплектующая успешно удалена!" << endl;
            return;
        }
    }

    cout << "Комплектующая с названием '" << name << "' не найдена." << endl;
}

// Функция для редактирования информации о комплектующей
void editComponent() {
    char name[MAX_STRING_LENGTH];
    cout << "Введите название комплектующей для редактирования: ";
    cin.ignore();
    cin.getline(name, MAX_STRING_LENGTH);

    for (int i = 0; i < componentCount; ++i) {
        if (strcmp(components[i].name, name) == 0) {
            cout << "Введите новое название комплектующей: ";
            cin.getline(components[i].name, MAX_STRING_LENGTH);
            cout << "Введите нового производителя комплектующей: ";
            cin.getline(components[i].manufacturer, MAX_STRING_LENGTH);
            cout << "Введите новые характеристики комплектующей: ";
            cin.getline(components[i].features, MAX_STRING_LENGTH);
            cout << "Введите новую стоимость комплектующей: ";
            cin >> components[i].cost;
            cout << "Информация о комплектующей успешно отредактирована!" << endl;
            return;
        }
    }

    cout << "Комплектующая с названием '" << name << "' не найдена." << endl;
}

// Функция для вывода списка комплектующих
void listComponents() {
    if (componentCount == 0) {
        cout << "Список комплектующих пуст." << endl;
        return;
    }

    cout << "Список комплектующих:" << endl;
    for (int i = 0; i < componentCount; ++i) {
        cout << "Название: " << components[i].name << endl;
        cout << "Производитель: " << components[i].manufacturer << endl;
        cout << "Характеристики: " << components[i].features << endl;
        cout << "Стоимость: " << components[i].cost << endl;
        cout << "---------------------------" << endl;
    }
}