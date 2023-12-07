#pragma once
#define MAXSIZE 60

#include <string>
#include "StackType.h"
using namespace std;

struct SB_Record {
	string SB_Title;
	string SB_Winner;
	int winnerPts;

	string SB_Loser;
	int loserPts;

	string MVP;
};

class AUList
{
public:
	AUList();

	void MakeEmpty();
	bool IsFull() const;
	int GetLength() const;
	void PutItem(SB_Record);
	void ResetList();
	SB_Record GetNextItem();
	bool HasNextItem();
	void PrintList();
	StackType<string> CreateStack(int stack_type);

private:
	int length;
	SB_Record ListItems[MAXSIZE];
	int currentPos;
};
