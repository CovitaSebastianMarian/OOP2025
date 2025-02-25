#pragma warning(disable : 4996)

/*
* Prima problema
#include <stdio.h>

int main() {
    FILE* file;
    char line[100];
    int sum = 0;

    file = fopen("in.txt", "r");

    while (fgets(line, sizeof(line), file) != NULL) {
        int num = 0;
        int i = 0;

        while (line[i] >= '0' && line[i] <= '9') {
            num = num * 10 + (line[i] - '0');
            i++;
        }

        sum += num;
    }

    fclose(file);
    printf("Suma numerelor din fisier este: %d\n", sum);
    return 0;
}
*/
/*
// problema 2
#include <stdio.h>
#include <cstring>

char input[1000];
char cuvinte[100][100];

int main() {
    int cnt = 0;
    fgets(input, sizeof(input), stdin);

    char* cuvant = strtok(input, " \n");
    while (cuvant != NULL) {
        strcpy(cuvinte[cnt], cuvant);
        cnt++;
        cuvant = strtok(NULL, " \n");
    }

    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < cnt - 1; ++i) {
            if (strlen(cuvinte[i]) < strlen(cuvinte[i + 1])) {
                char aux[100];
                strcpy(aux, cuvinte[i]);
                strcpy(cuvinte[i], cuvinte[i + 1]);
                strcpy(cuvinte[i + 1], aux);
                ok = true;
            }
            else if (strlen(cuvinte[i]) == strlen(cuvinte[i + 1])) {
                if (strcmp(cuvinte[i], cuvinte[i + 1]) > 0) {
                    char aux[100];
                    strcpy(aux, cuvinte[i]);
                    strcpy(cuvinte[i], cuvinte[i + 1]);
                    strcpy(cuvinte[i + 1], aux);
                    ok = true;
                }
            }
        }
    }

    for (int i = 0; i < cnt; ++i) {
        printf("%s\n", cuvinte[i]);
    }

    return 0;
}
*/
/*
//problema 3
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";
    return 0;
}
*/
/*
* //problema 4
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

enum VALORI {
    INMULTIRE = 0,
    SUMA,
    REZERVAT1,
    DIFERENTA,
    REZERVAT2,
    IMPARTIRE
};

typedef int (*func)(int, int);

struct Content {
    int p1;
    int p2;
};

int Sum(int a, int b);
int Dif(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);

*/
/*
#include "header.h"
int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

int main(int argc, char* argv[])
{
    char input[39] = "---H***E+++L+++L///O---P+++O/+-**O---";
    func Operatori[4] = {Sum, Dif, Mul, Div};
    int S = 0, V;
    Content x = {0, 0};
    double idx;

    int i;
    for (i = 0; i < strlen(input); i++)
    {
        switch (input[i] - 42)
        {
            case INMULTIRE:
                idx = 2;
                x.p1 = 3;
                x.p2 = 3;
                break;
            case SUMA:
                idx = 0;
                x.p1 = 7;
                x.p2 = 5;
                break;
            case DIFERENTA:
                idx = 1;
                x.p1 = 10;
                x.p2 = 1;
                break;
            case IMPARTIRE:
                idx = 3;
                x.p1 = 8;
                x.p2 = 4;
                break;
        }

        S = S + Operatori[(int)idx](x.p1, x.p2);
    }
    
    //S=337
    printf("S = %d\n", S);

    return 0;
}
*/