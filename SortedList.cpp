//*****************************************************************************************************
//
//		File:					SortedList.cpp
//
//		This program will impliment and test sort types.
//	
//		Other files required: 
//         1. stock.h
//         2.sortedlist.h
//			
//*****************************************************************************************************

#include"stock.h"
#include"sortedlist.h"
#include<fstream>
#include <iostream>

//*****************************************************************************************************

using namespace std;

//*****************************************************************************************************


int main() 
{
    SortedList<Stock> stockList;

    ifstream inputFile("stock.txt");
    if (!inputFile.is_open()) 
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;
    string companyName, stockSymbol, priceStr;

    while (!inputFile.eof())
    {
        if (getline(inputFile, companyName) &&
            getline(inputFile, stockSymbol) &&
            getline(inputFile, priceStr)) 
        {
            try
            {
                double price = stod(priceStr);
                Stock newStock(companyName, stockSymbol, price);
                stockList.insert(newStock);
            }
            catch (const invalid_argument& e) 
            {
                cout << "Invalid price format: " << priceStr << endl;
            }
        }
    }

    inputFile.close();


    stockList.randomise();
    cout << "\nList after randomization:\n";
    stockList.display();


    stockList.selectionSortA();
    cout << "\nList after selection sort (ascending):\n";
    stockList.display();

    stockList.randomise();
    cout << "\nList after randomization:\n";
    stockList.display();

    stockList.selectionSortD();
    cout << "\nList after selection sort (descending):\n";
    stockList.display();

    stockList.randomise();
    cout << "\nList after randomization:\n";
    stockList.display();

    stockList.quickSortA();
    cout << "\nList after quick sort (ascending):\n";
    stockList.display();

    stockList.randomise();
    cout << "\nList after randomization:\n";
    stockList.display();

    stockList.quickSortD();
    cout << "\nList after quick sort (descending):\n";
    stockList.display();

    return 0;
}

//*****************************************************************************************************
