//// ReSharper disable CommentTypo
//// ReSharper disable CppClangTidyCertErr33C
//// ReSharper disable CppDeprecatedEntity
//#include "checkInput.h"
//#include <iostream>
//#include "configs.h"
//using namespace std;
//#pragma warning(disable : 4996)
//
//
//int check_input::get_int_between(char* words, int min, int max)
//{
//    int n;
//    if (max < min)
//    {
//        int swap = max;
//        max = min;
//        min = swap;
//    }
//    for (;;) {
//	    cout << words << " (����� �� " << min << " �� " << max << "): " << flush;
//	    // ReSharper restore StringLiteralTypo
//	    if ((cin >> n).good() && min <= n && n <= max) return n;
//        if (n < 0) cout << "������ �� ����� ���� �������������\n";
//        if (n >= 0 && n < 2 && !cin.fail()) cout << "������ ������ ���� ������ ��� ����� 2!\n";
//        if (n > 5) cout << "������ ������ ���� ������ ��� ����� 5!\n";
//        if (cin.fail()) {
//            cin.clear();
//            cout << "�������� ����, ���������.\n";
//        }
//        else {
//            cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
//        }
//        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
//    }
//}
//
//bool check_input::check_string(string& input, int name_length)
//{
//    if (input.length() > name_length)
//    {
//        cout << "��������� ������ ������ �������� �����: " << name_length << endl;
//        return false;
//    }
//    return true;
//}
//
//int check_input::get_grade()
//{
//	configs cfg;
//	auto grade_word = new char[10];
//    strcpy(grade_word, "������");
//    return get_int_between(grade_word, cfg.min_grade, cfg.max_grade);
//}
//
//
//
//int check_input::get_size_array()
//{
//    cout << "\n������� ���������� ��������� ������:";
//    int size_array;
//    cin >> size_array;
//    while (!check_size_array(size_array))
//    {
//        if (size_array < 1 && !cin.fail()) cout << "������ ������ ������ ���� ������ 0!\n";
//        if (cin.fail()) {
//            cout << "�� ����� �� ����� ��� ������� ������� �����!\n";
//            cin.clear();
//            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
//        }
//        cout << "\n������� ���������� ��������� ������:";
//        cin >> size_array;
//    }
//    return size_array;
//}
//
//bool check_input::check_size_array(int size_array)
//{
//    if (size_array < 1)
//		return false;
//    return true;
//}
//
//
//
//
//int check_input::get_date()
//{
//    int day = 0;
//    int month = 0;
//    int year = 0;
//    cout << "������� ���� � ������� ����.�����.���: ";
//    do
//    {
//        cin >> day;
//        cin.ignore(1);
//        cin >> month;
//        cin.ignore(1);
//        cin >> year;
//        if (cin.fail()) {
//            cin.clear();
//            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
//        }
//
//    } while (!check_date(day, month, year));
//    time_t raw_time;
//    time(&raw_time);
//    // ReSharper disable once CppDeprecatedEntity
//    tm* time_info = localtime(&raw_time);  // NOLINT(concurrency-mt-unsafe)
//    time_info->tm_year = year - 1900;
//    time_info->tm_mon = month - 1;
//    time_info->tm_mday = day;
//    return  mktime(time_info);  // NOLINT(bugprone-narrowing-conversions, clang-diagnostic-shorten-64-to-32, cppcoreguidelines-narrowing-conversions)
//}
//
//
//bool check_input::check_date(int day, int month, int year)
//{
//	constexpr bool month31[12]{ true, false, true, false, true, false, true, true, false, true, false, true };
//    if (year < 1900 || year > 2037)
//    {
//        cout << "������������ ����" << endl;
//        return false;
//    }
//    if (month < 1 || month > 12)
//    {
//        cout << "����� ������ ���� �� 1 �� 12" << endl;
//        return false;
//    }
//    if (month == 2 && (day < 1 || day > 29))
//    {
//        cout << "������� ������ ���� �� 1 �� 29" << endl;
//        return false;
//    }
//    if (month == 2)
//    {
//        if (day >= 1 && day <= 29 && year % 4 == 0 || day >= 1 && day <= 28 && year % 4 != 0) return true;
//        cout << "������������ ���� � �������" << endl;
//        return false;
//    }
//
//    if (month31[month - 1] && day <= 31 && day >= 1) return true;
//    if (!month31[month - 1] && day <= 30 && day >= 1) return true;
//    cout << "������������ ����" << endl;
//    return false;
//}