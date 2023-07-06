#include "groupUniver.h"
#include "configs.h"


GroupUniver::GroupUniver(int sizeArray) : Group(sizeArray)
{
	SetSize(sizeArray);
	NewExam();
}

int GroupUniver::GetId()
{
	return id;
}

void GroupUniver::SetId(int id)
{
	this->id = id;
}
