#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <exception>
using namespace std;

#include "Array.h"




int compa(const int& a, const int& b) {
    return a < b;
}

int compequal(const int& a, const int& b) {
    return a == b;
}

/*
int main() {
    try {
        cout << "Creare array cu capacitate 10:\n";
        Array<int> arr(10);

        cout << "Adaugare elemente:\n";
        arr += 50;
        arr += 30;
        arr += 40;
        arr += 10;
        arr += 20;

        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << "\n";

        cout << "Insert element la pozitia 2 (35):\n";
        arr.Insert(2, 35);

        cout << "Stare actuala: ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << "\n";

        cout << "Creare al doilea array si insert in primul:\n";
        Array<int> other(3);
        other += 99;
        other += 88;
        other += 77;

        arr.Insert(1, other);

        cout << "Dupa insert alt array: ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << "\n";

        cout << "Sterge elementul de la pozitia 3:\n";
        arr.Delete(3);

        cout << "Array dupa stergere: ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << "\n";

        cout << "Sortare implicita:\n";
        arr.Sort();
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << "\n";

        cout << "Sortare cu functie externa:\n";
        arr.Sort(compa);
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << "\n";

        cout << "Sortare cu comparator de tip clasa:\n";
		crescator* comp = new crescator;
        arr.Sort(comp);
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << " ";
        cout << "\n";

        cout << "Cautare secventiala (Find) pentru 35:\n";
        int pos = arr.Find(35);
        cout << "Pozitie: " << pos << "\n";

        cout << "Cautare binara (BinarySearch) pentru 35:\n";
        pos = arr.BinarySearch(35);
        cout << "Pozitie: " << pos << "\n";

        cout << "Find cu functie:\n";
        pos = arr.Find(88, compequal);
        cout << "Pozitie: " << pos << "\n";

        cout << "BinarySearch cu clasa comparator:\n";

        pos = arr.BinarySearch(88, comp);
        cout << "Pozitie: " << pos << "\n";

        cout << "Testare operator de atribuire (=):\n";
		Array<int> copy = arr;

        cout << "Copie: ";
        for (int i = 0; i < copy.GetSize(); ++i)
            cout << copy[i] << " ";
        cout << "\n";

        cout << "Testare iteratori:\n";
        ArrayIterator<int> it = arr.GetBeginIterator();
        ArrayIterator<int> end = arr.GetEndIterator();
        while (it != end) {
            cout << *it.GetElement() << " ";
            ++it;
        }
        cout << "\n";

        cout << "Testare exceptie de acces invalid:\n";
        cout << arr[100] << "\n"; // va arunca exceptie

    }
    catch (exception& e) {
        cout << "Exceptie: " << e.what() << endl;
    }

    return 0;
}
*/


int main()
{
	
	Array<int> a(10);
    a += 1;
    a += 2;
    a += 3;
	for (int i = 0; i < a.GetSize(); ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";
	a += 4;
	cout << a.BinarySearch(3) << "\n";
	cout << a.BinarySearch(7) << "\n";
	a.Insert(2, 5);
	Array<int> b(5);
	b += 6;
	b += 7;
	b += 8;
	a.Insert(3, b);

	for (int i = 0; i < a.GetSize(); ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";

	a.Delete(3);
	Array<int> c(a);
	for (int i = 0; i < c.GetSize(); ++i) {
		cout << c[i] << " ";
	}
	cout << "\n";

	crescator* comp = new crescator;
	a.Sort(comp);
	for (int i = 0; i < a.GetSize(); ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";

	

	a.Sort(compa);

	for (int i = 0; i < a.GetSize(); ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";

	if (a.BinarySearch(3)) {
		cout << "Found 3\n";
	}
	else {
		cout << "Not found 3\n";
	}
	if (a.BinarySearch(4, comp)) {
		cout << "Found 4\n";
	}
	else {
		cout << "Not found 4\n";
	}
	if (a.BinarySearch(5, compequal)) {
		cout << "Found 5\n";
	}
	else {
		cout << "Not found 5\n";
	}
	if (a.Find(3)) {
		cout << "Found 3\n";
	}
	else {
		cout << "Not found 3\n";		
	}
	if (a.Find(4, comp)) {
		cout << "Found 4\n";
	}
	else {
		cout << "Not found 4\n";
	}
	if (a.Find(5, compequal)) {
		cout << "Found 5\n";
	}
	else {
		cout << "Not found 5\n";
	}
	
	for (auto it = a.GetBeginIterator(); it != a.GetEndIterator(); ++it) {
		cout << *(it.GetElement()) << " ";
	}
	cout << "\n";


	try {
		Array<int> z(4);
		z += 1;
		z += 2;
		Array<int> y(2);
		y += 3;
		y += 4;
		z.Insert(1, y);
		for (auto it = z.GetBeginIterator(); it != z.GetEndIterator(); ++it) {
			cout << *(it.GetElement()) << " ";
		}
	}
	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;
	}
	
	

    return 0;
}
