// ReSharper disable CommentTypo
#pragma once
#include "group.h"

class group_university: public group
{
	int id_ = 0;
public:
	group_university();
	// ����������� ������ GroupUniver � ���������� ����� �������
	explicit group_university(int size_array);
	~group_university();
	int get_id() const;
	void set_id(int id);
};
