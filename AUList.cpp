#include <iostream>
#include <stdexcept>
#include <string>
#include "AUList.h"


AUList::AUList() : length(0) {}

bool AUList::IsFull() const { return (length == MAXSIZE); }

int AUList::GetLength() const { return length; }

void AUList::MakeEmpty() { length = 0; }

void AUList::PutItem(SB_Record item)
{   // since indexing starts at 0, array[length] appends new last to last spot
	ListItems[length] = item;
	length++;
}

void AUList::ResetList() { currentPos = -1; }

bool AUList::HasNextItem() { return currentPos < (length - 1); }

SB_Record AUList::GetNextItem()
{
	currentPos++;
	return ListItems[currentPos];
}

void AUList::PrintList()
{
	std::cout << "Most Recent to Least recent:" << std::endl << std::endl;
	for (size_t loc = 0; loc < length; loc++)
	{
		SB_Record curItem = ListItems[loc];
		std::cout << "Record #" << loc << " : " << std::endl
			<< "     Super Bowl: " << curItem.SB_Title << std::endl

			<< "     Winner: " << curItem.SB_Winner
			<< ", Points = " << curItem.winnerPts << std::endl

			<< "     Loser: " << curItem.SB_Loser
			<< ", Points = " << curItem.loserPts << std::endl;
	}
}


StackType<string> AUList::CreateStack(int stack_type) {
	int length = 54;
	StackType<string> stack_(length);
	if (stack_type == 1)
	{
		for (size_t loc = 0; loc < length; loc++) {
			SB_Record curItem = ListItems[loc];
			stack_.Push(curItem.SB_Winner);
		}
	}
	else if (stack_type == 2)
	{
		for (size_t loc = 0; loc < length; loc++) {
			SB_Record curItem = ListItems[loc];
			stack_.Push(curItem.SB_Loser);
		}
	}
	else
	{
		for (size_t loc = 0; loc < length; loc++) {
			SB_Record curItem = ListItems[loc];
			stack_.Push(curItem.MVP);
		}
	}

	return stack_;
}
