// AdvancedFileOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int showMenu();
void displayMenuChoices();
int getRecordNumber();
void createFile(std::fstream&);
void displayFile(std::fstream&);
void displayRecord(std::fstream&, int);
void modifyAProduct(std::fstream&, int);


int main()
{
    std::fstream fileStream;
    
    createFile(fileStream);
    int menuFunction = 0;

    do {
        menuFunction = showMenu();
        switch (menuFunction)
        {
        case 1: displayFile(fileStream);
            break;
        case 2: displayRecord(fileStream, getRecordNumber());
            break;
        case 3: modifyAProduct(fileStream, getRecordNumber());
            break;
        case 4: exit(0);
            break;
        default:
            break;
        }
    } while (menuFunction != 4);


}

int showMenu() {
    std::cout << "Please pick a menu option from the choices below." << std::endl;
    displayMenuChoices();
    int menuChoice;
    std::cin >> menuChoice;
    while (menuChoice < 1 || menuChoice > 5)
    {
        std::cout << "That is not a menu choice. Please enter a choice between 1 and 4." << std::endl;
        displayMenuChoices();
        std::cin >> menuChoice;
    }

    return menuChoice;
}

void displayMenuChoices() {
    std::cout << "1. Display the entire inventory" << std::endl;
    std::cout << "2. Display a particular product" << std::endl;
    std::cout << "3. Modify a product" << std::endl;
    std::cout << "4. Exit" << std::endl;
}
void createFile(std::fstream& stream) {
    const int NAME_SIZE = 40;
    struct Product {
        long number;
        char name[NAME_SIZE];
        double price;
        int quantity;
    };

    stream.open("inventory.dat", std::ios::out);
    Product p1;
    p1.number = 1;
    strcpy(p1.name, "Giant TCR Advanced Pro 1");
    p1.price = 5000.00;
    p1.quantity = 10;
    stream.write(reinterpret_cast<char *>(&p1), sizeof(p1));

    Product p2;
    strcpy(p2.name, "Cannondale SystemSix");
    p2.number = 2;
    p2.price = 7500.00;
    p2.quantity = 5;
    stream.write(reinterpret_cast<char *>(&p2), sizeof(p2));

    Product p3;
    p3.number = 3;
    strcpy(p3.name, "Colnago C64");
    p3.price = 12000.00;
    p3.quantity = 2;
    stream.write(reinterpret_cast<char *>(&p3), sizeof(p3));

    Product p4;
    strcpy(p4.name, "Winspace T1500");
    p4.number = 4;
    p4.price = 2500;
    p4.quantity = 25;
    stream.write(reinterpret_cast<char *>(&p4), sizeof(p4));

        std::cout << sizeof(p1) << std::endl;
        std::cout << sizeof(p2) << std::endl;
        std::cout << sizeof(p3) << std::endl;
        std::cout << sizeof(p4) << std::endl;

}
//void displayRecord(std::fstream& stream, int recordNumber)
//{
//    int byteNumber = recordNumber - 1;
//    stream.seekg(byteNum(byteNumber),std::ios::beg);
//}


int getRecordNumber() {
    std::cout << "Please enter the record number you would like to see." << std::endl;
    int recordNumber;
    std::cin >> recordNumber;
    return recordNumber;
}

long byteNum(int recordNumber) {
    return (40 * recordNumber);
}