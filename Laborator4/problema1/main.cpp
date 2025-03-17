#include <iostream>
#include "Sort.h"


int main() {

    Sort s1(10ULL, 1, 100);
    std::cout << "Vector random:\n";
    s1.Print();

    Sort s2 = { 10, 40, 100, 5, 70 };
    std::cout << "Vector din initializer_list:\n";
    s2.Print();

    int arr[] = { 30, 20, 10, 50, 40 };
    Sort s3(arr, 5);
    std::cout << "Vector din array existent:\n";
    s3.Print();

    Sort s4(6, 90, 80, 70, 60, 50, 40);
    std::cout << "Vector din parametri variadici:\n";
    s4.Print();

    Sort s5("7,2,8,5,1,9");
    std::cout << "Vector din string:\n";
    s5.Print();

    std::cout << "\n--- Sorting ---\n";

    s1.BubbleSort(true);
    std::cout << "Bubble Sort ascendent:\n";
    s1.Print();

    s2.InsertSort(false);
    std::cout << "Insertion Sort descendent:\n";
    s2.Print();

    s3.QuickSort(true);
    std::cout << "Quick Sort ascendent:\n";
    s3.Print();

    std::cout << "Elementul de pe indexul 2 din s4: " << s4.GetElementFromIndex(2) << "\n";
    std::cout << "Numar total de elemente in s5: " << s5.GetElementsCount() << "\n";

    return 0;
}
