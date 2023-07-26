#include "groupUniver.h"
#include "configs.h"
#include <iostream>

using namespace std;

GroupUniver::GroupUniver()
{
	cout << "GroupUniver конструктор по умолчанию вызван, память не выделяется" << endl;
}

GroupUniver::GroupUniver(int sizeArray) : Group(sizeArray)
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

GroupUniver::~GroupUniver()
{
	cout << "GroupUniver деструктор вызван, память не очищается" << endl;
}

int GroupUniver::GetId()
{
	return id;
}

void GroupUniver::SetId(int id)
{
	this->id = id;
}
