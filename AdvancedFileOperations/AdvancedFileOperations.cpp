// AdvancedFileOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>


int showMenu();
void createFile(std::fstream&);
void displayFile(std::fstream&);
void displayRecord(std::fstream&, int);



int main()
{
    std::fstream fileStream;
    fileStream.open("inventory.dat", std::ios::out);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

int showMenu() {

}
void createFile(std::fstream& stream) {
    const int NAME_SIZE = 40;
    struct Product {
        long number;
        char name[NAME_SIZE];
        double price;
        int quantity;
    };

    Product p1;
    p1.number = 1;
    strcpy(p1.name, "Giant TCR Advanced Pro 1");
    p1.price = 5000.00;
    p1.quantity = 10;

}
void displayRecord(std::fstream& stream, int recordNumber)
{

}


