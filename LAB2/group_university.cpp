// ReSharper disable CommentTypo
#include "group_university.h"
#include <iostream>

using namespace std;

group_university::group_university()
{
	cout << "������ ����������� �� ��������� group_university, ������ �� ����������" << endl;
}

group_university::group_university(int size_array) : group(size_array)
{
	cout << "������ ����������� group_university, ������ �� ����������" << endl;
}

group_university::~group_university()
{
	cout << "������ ���������� group_university, ������ �� ���������" << endl;
}

int group_university::get_id()
{
	return id_;
}

void group_university::set_id(int id)
{
	this->id_ = id;
}
