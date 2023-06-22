#pragma once
#include <string>
using namespace std;

static class CheckInput
{
public:
    static int Date();
    static int Grade();
    static bool CheckDate(int day, int month, int year);
};