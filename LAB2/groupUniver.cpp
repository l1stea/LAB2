#include "groupUniver.h"
#include "configs.h"


GroupUniver::GroupUniver(int sizeArray) : Group(sizeArray)
{
	this->id = GetId();
	this->sizeArray = sizeArray;
	this->exam = new Exam[sizeArray]; // new - динамическое выделение памяти
}

int GroupUniver::GetId()
{
	return id;
}

void GroupUniver::SetId(int id)
{
	this->id = id;
}
