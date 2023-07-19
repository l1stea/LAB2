#pragma once
#include <string>
using namespace std;

static class CheckInput
{
private:
    static bool CheckDate(int day, int month, int year);
public:
    static int Date();
    static int Grade();
};