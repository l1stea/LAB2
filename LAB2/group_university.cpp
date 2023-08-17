// ReSharper disable CommentTypo
#include "group_university.h"
#include <iostream>

using namespace std;

group_university::group_university()
{
	cout << "GroupUniver конструктор по умолчанию вызван, память не выделяется" << endl;
}

group_university::group_university(const int size_array) : group(size_array)
{
	cout << "GroupUniver конструктор вызван, память не выделяется" << endl;
	//while (sizeArray < 1)
	//{
	//	cout << "Введен размер группы меньше 1, введите снова" << endl;
	//	cin >> sizeArray;
	//}
	//SetSize(sizeArray);
	//NewExam();
}

group_university::~group_university()
{
	cout << "GroupUniver деструктор вызван, память не очищается" << endl;
}

int group_university::get_id() const
{
	return id_;
}

void group_university::set_id(const int id)
{
	this->id_ = id;
}
