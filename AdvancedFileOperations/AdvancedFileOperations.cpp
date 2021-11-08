// AdvancedFileOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Joe Blommel  
// CIS 1202 801
// November 1, 2021


#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


const int NAME_SIZE = 40;
struct Product {
    long number;
    char name[NAME_SIZE];
    double price;
    int quantity;
};
int showMenu();
void displayMenuChoices();
int getRecordNumber();
void createFile(std::fstream&);
void displayFile(std::fstream&);
void displayRecord(std::fstream&, int);
void modifyAProduct(std::fstream&, int);
void showProduct(Product);
long byteNum(int);


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
    

    stream.open("inventory.dat", std::ios::out|std::ios::binary);
    Product p1;
    p1.number = 1;
    strcpy_s(p1.name, "Giant TCR Advanced Pro 1");
    p1.price = 5000.00;
    p1.quantity = 10;
    stream.write(reinterpret_cast<char *>(&p1), sizeof(p1));

    Product p2;
    p2.number = 2;
    strcpy_s(p2.name, "Cannondale SystemSix");
    p2.price = 7500.00;
    p2.quantity = 5;
    stream.write(reinterpret_cast<char *>(&p2), sizeof(p2));

    Product p3;
    p3.number = 3;
    strcpy_s(p3.name, "Colnago C64");
    p3.price = 12000.00;
    p3.quantity = 2;
    stream.write(reinterpret_cast<char *>(&p3), sizeof(p3));

    Product p4;
    p4.number = 4;
    strcpy_s(p4.name, "Winspace T1500");
    p4.price = 2500.00;
    p4.quantity = 25;
    stream.write(reinterpret_cast<char *>(&p4), sizeof(p4));

        std::cout << sizeof(p1) << std::endl;
        std::cout << sizeof(p2) << std::endl;
        std::cout << sizeof(p3) << std::endl;
        std::cout << sizeof(p4) << std::endl;

        stream.close();
}

//display all records in the file
void displayFile(std::fstream& stream) {
    stream.open("inventory.dat", std::ios::in | std::ios::binary);
    stream.clear();
    std::cout << stream.eof() << std::endl;
    Product productToRead;
    stream.seekg(byteNum(0),std::ios::beg);
    std::cout << stream.tellg() << std::endl;
    stream.read(reinterpret_cast<char*>(&productToRead), sizeof(Product));
    int recordNumber = 0;
    while (!stream.eof())
    {
        std::cout << stream.tellg() << std::endl;
        std::cout << "Record Number: " << recordNumber << std::endl;
        showProduct(productToRead);
        stream.read(reinterpret_cast<char*>(&productToRead), sizeof(Product));
        recordNumber++;
    }
    stream.close();
}
void displayRecord(std::fstream& stream, int recordNumber)
{
    stream.open("inventory.dat", std::ios::in | std::ios::binary);
    stream.clear();
    int byteNumber = recordNumber - 1;
    stream.seekg(byteNum(byteNumber),std::ios::beg);
    Product productToRead;
    stream.read(reinterpret_cast<char*>(&productToRead), sizeof(Product));
    showProduct(productToRead);
    stream.close();
}


int getRecordNumber() {
    std::cout << "Please enter the record number you would like to see." << std::endl;
    int recordNumber;
    std::cin >> recordNumber;
    return recordNumber;
}

long byteNum(int recordNumber) {
    return sizeof(Product) * recordNumber;
}

void modifyAProduct(std::fstream& stream, int recordNumber) {
    Product productToModify;
    stream.open("inventory.dat", std::ios::in | std::ios::out | std::ios::binary);
    std::string tempInput;
    std::cin.ignore();
    stream.seekg(byteNum(recordNumber), std::ios::beg);
    stream.read(reinterpret_cast<char*>(&productToModify), sizeof(Product));
    showProduct(productToModify);
    stream.seekp(byteNum(recordNumber), std::ios::beg);
    
    std::cout << "Enter the new information: " << std::endl;
    std::cout << "Product Name: " << std::endl;
    
    std::getline(std::cin, tempInput);
    /*struct Product {
        long number;
        char name[NAME_SIZE];
        double price;
        int quantity;
    };*/
    strcpy_s(productToModify.name,tempInput.c_str());
    std::cin.clear();
    std::cout << "Product Price: " << std::endl;
    std::getline(std::cin, tempInput);
    productToModify.price = stod(tempInput);
    std::cin.clear();
    std::cout << "Number in inventory: " << std::endl;
    std::getline(std::cin, tempInput);
    productToModify.quantity = stoi(tempInput);
    stream.write(reinterpret_cast<char*>(&productToModify), sizeof(Product));
    stream.close();

}

void showProduct(Product product) {
    std::cout << "Product Number: " << product.number << std::endl;
    std::cout << "Product Name: " << product.name << std::endl;
    std::cout << "Product Price: " << product.price << std::endl;
    std::cout << "Product Quantity: " << product.quantity << std::endl;
}