// ReSharper disable CommentTypo
#pragma once
#include "group.h"

class group_university: public group
{
private:
	int id_ = 0;
public:
	group_university();
	// Конструктор класса GroupUniver и добавление новых функций
	explicit group_university(int size_array);
	~group_university();
	int get_id();
	void set_id(int id);
};
