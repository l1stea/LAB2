#include "groupUniver.h"
#include "configs.h"
#include <iostream>

using namespace std;

GroupUniver::GroupUniver()
{
	cout << "GroupUniver ����������� �� ��������� ������, ������ �� ����������" << endl;
}

GroupUniver::GroupUniver(int sizeArray) : Group(sizeArray)
{
	cout << "GroupUniver ����������� ������, ������ �� ����������" << endl;
	//while (sizeArray < 1)
	//{
	//	cout << "������ ������ ������ ������ 1, ������� �����" << endl;
	//	cin >> sizeArray;
	//}
	//SetSize(sizeArray);
	//NewExam();
}

GroupUniver::~GroupUniver()
{
	cout << "GroupUniver ���������� ������, ������ �� ���������" << endl;
}

int GroupUniver::GetId()
{
	return id;
}

void GroupUniver::SetId(int id)
{
	this->id = id;
}
