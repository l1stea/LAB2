// ReSharper disable CommentTypo
#include "group_university.h"
#include <iostream>

using namespace std;

group_university::group_university()
{
	cout << "Вызван консртуктор по умолчанию group_university, память не выделяется" << endl;
}

group_university::group_university(int size_array) : group(size_array)
{
	cout << "Вызван конструктор group_university, память не выделяется" << endl;
}

group_university::~group_university()
{
	cout << "Вызван деструктор group_university, память не очищается" << endl;
}

int group_university::get_id()
{
	return id_;
}

void group_university::set_id(int id)
{
	this->id_ = id;
}
