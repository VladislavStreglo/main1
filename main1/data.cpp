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

// ������� ��� ���������� ������ � ����
void saveDataToFile() {
    FILE* outFile;
    if (fopen_s(&outFile, "data.bin", "wb") != 0) {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
        return;
    }

    size_t writeResult;
    writeResult = fwrite(&managerCount, sizeof(managerCount), 1, outFile);
    if (writeResult != 1) {
        cerr << "������ ��� ������ � ����." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(managers, sizeof(Manager), managerCount, outFile);
    if (writeResult != managerCount) {
        cerr << "������ ��� ������ � ����." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(&computerCount, sizeof(computerCount), 1, outFile);
    if (writeResult != 1) {
        cerr << "������ ��� ������ � ����." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(computers, sizeof(Computer), computerCount, outFile);
    if (writeResult != computerCount) {
        cerr << "������ ��� ������ � ����." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(&componentCount, sizeof(componentCount), 1, outFile);
    if (writeResult != 1) {
        cerr << "������ ��� ������ � ����." << endl;
        fclose(outFile);
        return;
    }
    writeResult = fwrite(components, sizeof(Component), componentCount, outFile);
    if (writeResult != componentCount) {
        cerr << "������ ��� ������ � ����." << endl;
        fclose(outFile);
        return;
    }

    fclose(outFile);
    cout << "������ ������� ��������� � ����." << endl;
}

// ������� ��� �������� ������ �� �����
void loadDataFromFile() {
    FILE* inFile;
    if (fopen_s(&inFile, "data.bin", "rb") != 0) {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
        return;
    }

    size_t readResult;
    readResult = fread(&managerCount, sizeof(managerCount), 1, inFile);
    if (readResult != 1) {
        cerr << "������ ��� ������ �� �����." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(managers, sizeof(Manager), managerCount, inFile);
    if (readResult != managerCount) {
        cerr << "������ ��� ������ �� �����." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(&computerCount, sizeof(computerCount), 1, inFile);
    if (readResult != 1) {
        cerr << "������ ��� ������ �� �����." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(computers, sizeof(Computer), computerCount, inFile);
    if (readResult != computerCount) {
        cerr << "������ ��� ������ �� �����." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(&componentCount, sizeof(componentCount), 1, inFile);
    if (readResult != 1) {
        cerr << "������ ��� ������ �� �����." << endl;
        fclose(inFile);
        return;
    }
    readResult = fread(components, sizeof(Component), componentCount, inFile);
    if (readResult != componentCount) {
        cerr << "������ ��� ������ �� �����." << endl;
        fclose(inFile);
        return;
    }

    fclose(inFile);
    cout << "������ ������� ��������� �� �����." << endl;
}

// ������� ��� ���������� ���������
void addManager() {
    if (managerCount < MAX_MANAGERS) {
        Manager manager;
        cout << "������� ������� ���������: ";
        cin >> manager.lastName;
        cout << "������� ��� ���������: ";
        cin >> manager.firstName;
        cout << "������� �������� ���������: ";
        cin >> manager.middleName;
        cout << "������� ��������� ���������: ";
        cin.ignore();
        cin.getline(manager.position, MAX_STRING_LENGTH);
        cout << "������� ����� �������� ���������: ";
        cin >> manager.phone;

        managers[managerCount++] = manager;

        cout << "�������� ������� ��������!" << endl;
    }
    else {
        cout << "��������� ������������ ����� ����������." << endl;
    }
}

// ������� ��� �������� ��������� �� �������
void deleteManager() {
    char lastName[MAX_STRING_LENGTH];
    cout << "������� ������� ��������� ��� ��������: ";
    cin >> lastName;

    for (int i = 0; i < managerCount; ++i) {
        if (strcmp(managers[i].lastName, lastName) == 0) {
            for (int j = i; j < managerCount - 1; ++j) {
                managers[j] = managers[j + 1];
            }
            --managerCount;
            cout << "�������� ������� ������!" << endl;
            return;
        }
    }

    cout << "�������� � �������� '" << lastName << "' �� ������." << endl;
}

// ������� ��� �������������� ���������� � ���������
void editManager() {
    char lastName[MAX_STRING_LENGTH];
    cout << "������� ������� ��������� ��� ��������������: ";
    cin >> lastName;

    for (int i = 0; i < managerCount; ++i) {
        if (strcmp(managers[i].lastName, lastName) == 0) {
            cout << "������� ����� �������: ";
            cin >> managers[i].lastName;
            cout << "������� ����� ���: ";
            cin >> managers[i].firstName;
            cout << "������� ����� ��������: ";
            cin >> managers[i].middleName;
            cout << "������� ����� ���������: ";
            cin.ignore();
            cin.getline(managers[i].position, MAX_STRING_LENGTH);
            cout << "������� ����� ����� ��������: ";
            cin >> managers[i].phone;
            cout << "���������� � ��������� ������� ���������������!" << endl;
            return;
        }
    }

    cout << "�������� � �������� '" << lastName << "' �� ������." << endl;
}

// ������� ��� ������ ������ ����������
void listManagers() {
    if (managerCount == 0) {
        cout << "������ ���������� ����." << endl;
        return;
    }

    cout << "������ ����������:" << endl;
    for (int i = 0; i < managerCount; ++i) {
        cout << "�������: " << managers[i].lastName << endl;
        cout << "���: " << managers[i].firstName << endl;
        cout << "��������: " << managers[i].middleName << endl;
        cout << "���������: " << managers[i].position << endl;
        cout << "����� ��������: " << managers[i].phone << endl;
        cout << "---------------------------" << endl;
    }
}

// ������� ��� ������������� ������ �� ������� ���������
void searchByLastName() {
    char lastName[MAX_STRING_LENGTH];
    cout << "������� ������� ��������� ��� ������: ";
    cin >> lastName;

    cout << "���������� ������:" << endl;
    for (int i = 0; i < managerCount; ++i) {
        if (strcmp(managers[i].lastName, lastName) == 0) {
            cout << "�������: " << managers[i].lastName << endl;
            cout << "���: " << managers[i].firstName << endl;
            cout << "��������: " << managers[i].middleName << endl;
            cout << "���������: " << managers[i].position << endl;
            cout << "����� ��������: " << managers[i].phone << endl;
            cout << "---------------------------" << endl;
        }
    }
}

// ������� ��� ���������� ����������
void addComputer() {
    if (computerCount < MAX_COMPUTERS) {
        Computer computer;
        cout << "������� �������� ����������: ";
        cin.ignore();
        cin.getline(computer.name, MAX_STRING_LENGTH);
        cout << "������� ������������ ����������: ";
        cin.getline(computer.configuration, MAX_STRING_LENGTH);
        cout << "������� ���������� �������������: ";
        cin >> computer.componentCount;

        cout << "������� �������� �������������:" << endl;
        for (int i = 0; i < computer.componentCount; ++i) {
            cin.ignore();
            cin.getline(computer.components[i], MAX_STRING_LENGTH);
        }

        computers[computerCount++] = computer;

        cout << "��������� ������� ��������!" << endl;
    }
    else {
        cout << "��������� ������������ ����� �����������." << endl;
    }
}

// ������� ��� �������� ���������� �� ��������
void deleteComputer() {
    char name[MAX_STRING_LENGTH];
    cout << "������� �������� ���������� ��� ��������: ";
    cin.ignore();
    cin.getline(name, MAX_STRING_LENGTH);

    for (int i = 0; i < computerCount; ++i) {
        if (strcmp(computers[i].name, name) == 0) {
            for (int j = i; j < computerCount - 1; ++j) {
                computers[j] = computers[j + 1];
            }
            --computerCount;
            cout << "��������� ������� ������!" << endl;
            return;
        }
    }

    cout << "��������� � ��������� '" << name << "' �� ������." << endl;
}

// ������� ��� �������������� ���������� � ����������
void editComputer() {
    char name[MAX_STRING_LENGTH];
    cout << "������� �������� ���������� ��� ��������������: ";
    cin.ignore();
    cin.getline(name, MAX_STRING_LENGTH);

    for (int i = 0; i < computerCount; ++i) {
        if (strcmp(computers[i].name, name) == 0) {
            cout << "������� ����� �������� ����������: ";
            cin.getline(computers[i].name, MAX_STRING_LENGTH);
            cout << "������� ����� ������������ ����������: ";
            cin.getline(computers[i].configuration, MAX_STRING_LENGTH);
            cout << "������� ����� ���������� �������������: ";
            cin >> computers[i].componentCount;

            cout << "������� �������� �������������:" << endl;
            for (int j = 0; j < computers[i].componentCount; ++j) {
                cin.ignore();
                cin.getline(computers[i].components[j], MAX_STRING_LENGTH);
            }

            cout << "���������� � ���������� ������� ���������������!" << endl;
            return;
        }
    }

    cout << "��������� � ��������� '" << name << "' �� ������." << endl;
}

// ������� ��� ������ ������ �����������
void listComputers() {
    if (computerCount == 0) {
        cout << "������ ����������� ����." << endl;
        return;
    }

    cout << "������ �����������:" << endl;
    for (int i = 0; i < computerCount; ++i) {
        cout << "��������: " << computers[i].name << endl;
        cout << "������������: " << computers[i].configuration << endl;
        cout << "���������� �������������: " << computers[i].componentCount << endl;
        cout << "�������������:" << endl;
        for (int j = 0; j < computers[i].componentCount; ++j) {
            cout << "  - " << computers[i].components[j] << endl;
        }
        cout << "---------------------------" << endl;
    }
}

// ������� ��� ���������� �������������
void addComponent() {
    if (componentCount < MAX_COMPONENTS) {
        Component component;
        cout << "������� �������� �������������: ";
        cin.ignore();
        cin.getline(component.name, MAX_STRING_LENGTH);
        cout << "������� ������������� �������������: ";
        cin.getline(component.manufacturer, MAX_STRING_LENGTH);
        cout << "������� �������������� �������������: ";
        cin.getline(component.features, MAX_STRING_LENGTH);
        cout << "������� ��������� �������������: ";
        cin >> component.cost;

        components[componentCount++] = component;

        cout << "������������� ������� ���������!" << endl;
    }
    else {
        cout << "��������� ������������ ����� �������������." << endl;
    }
}

// ������� ��� �������� ������������� �� ��������
void deleteComponent() {
    char name[MAX_STRING_LENGTH];
    cout << "������� �������� ������������� ��� ��������: ";
    cin.ignore();
    cin.getline(name, MAX_STRING_LENGTH);

    for (int i = 0; i < componentCount; ++i) {
        if (strcmp(components[i].name, name) == 0) {
            for (int j = i; j < componentCount - 1; ++j) {
                components[j] = components[j + 1];
            }
            --componentCount;
            cout << "������������� ������� �������!" << endl;
            return;
        }
    }

    cout << "������������� � ��������� '" << name << "' �� �������." << endl;
}

// ������� ��� �������������� ���������� � �������������
void editComponent() {
    char name[MAX_STRING_LENGTH];
    cout << "������� �������� ������������� ��� ��������������: ";
    cin.ignore();
    cin.getline(name, MAX_STRING_LENGTH);

    for (int i = 0; i < componentCount; ++i) {
        if (strcmp(components[i].name, name) == 0) {
            cout << "������� ����� �������� �������������: ";
            cin.getline(components[i].name, MAX_STRING_LENGTH);
            cout << "������� ������ ������������� �������������: ";
            cin.getline(components[i].manufacturer, MAX_STRING_LENGTH);
            cout << "������� ����� �������������� �������������: ";
            cin.getline(components[i].features, MAX_STRING_LENGTH);
            cout << "������� ����� ��������� �������������: ";
            cin >> components[i].cost;
            cout << "���������� � ������������� ������� ���������������!" << endl;
            return;
        }
    }

    cout << "������������� � ��������� '" << name << "' �� �������." << endl;
}

// ������� ��� ������ ������ �������������
void listComponents() {
    if (componentCount == 0) {
        cout << "������ ������������� ����." << endl;
        return;
    }

    cout << "������ �������������:" << endl;
    for (int i = 0; i < componentCount; ++i) {
        cout << "��������: " << components[i].name << endl;
        cout << "�������������: " << components[i].manufacturer << endl;
        cout << "��������������: " << components[i].features << endl;
        cout << "���������: " << components[i].cost << endl;
        cout << "---------------------------" << endl;
    }
}