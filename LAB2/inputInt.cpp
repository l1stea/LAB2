#include "inputInt.h"
#include <iostream>
using namespace std;

int inputInt::InputInt(const char* words, int min, int max)
{
    int N;
    for (;;) {
        cout << words << " (����� �� " << min << " �� " << max << "): " << flush;
        if ((cin >> N).good() && (min <= N) && (N <= max)) return N;
        if (cin.fail()) {
            cin.clear();
            cout << "�������� ����, ���������.\n";
        }
        else {
            cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
        }
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}