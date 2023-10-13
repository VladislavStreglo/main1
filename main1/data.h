#pragma once

const int MAX_MANAGERS = 100;
const int MAX_COMPUTERS = 100;
const int MAX_COMPONENTS = 100;
const int MAX_STRING_LENGTH = 100;

struct Manager {
    char lastName[MAX_STRING_LENGTH];
    char firstName[MAX_STRING_LENGTH];
    char middleName[MAX_STRING_LENGTH];
    char position[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];
};

struct Computer {
    char name[MAX_STRING_LENGTH];
    char configuration[MAX_STRING_LENGTH];
    int componentCount;
    char components[MAX_COMPONENTS][MAX_STRING_LENGTH];
};

struct Component {
    char name[MAX_STRING_LENGTH];
    char manufacturer[MAX_STRING_LENGTH];
    char features[MAX_STRING_LENGTH];
    double cost;
};



void addManager();
void deleteManager();
void editManager();
void listManagers();
void searchByLastName();

void addComputer();
void deleteComputer();
void editComputer();
void listComputers();

void addComponent();
void deleteComponent();
void editComponent();
void listComponents();

void saveDataToFile();
void loadDataFromFile();