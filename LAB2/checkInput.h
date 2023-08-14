#pragma once
#include <string>
using namespace std;

static class CheckInput
{
private:
    static bool GetCheckDate(int day, int month, int year);
public:
    static int GetDate();
    static int GetGrade();
    static int GetIndex(int sizeArray);
    static int GetIntBetween(char* words, int min, int max);
};