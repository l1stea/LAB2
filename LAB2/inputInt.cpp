#include "inputInt.h"
#include <iostream>
using namespace std;

int inputInt::InputInt(char* words, int min, int max)
{
    int N;
    if (max < min)
    {
        int swap = max;
        max = min;
        min = swap;
    }
    for (;;) {
        cout << words << " (целое от " << min << " до " << max << "): " << flush;
        if ((cin >> N).good() && (min <= N) && (N <= max)) return N;
        if (cin.fail()) {
            cin.clear();
            cout << "Неверный ввод, повторите.\n";
        }
        else {
            cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
        }
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}