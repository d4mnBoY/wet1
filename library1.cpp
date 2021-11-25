//
// Created by abusa on 11/24/2021.
//
#include "library1.h"
void *Init(); //adam

StatusType AddGroup(void *DS, int GroupID)
{

}

StatusType AddPlayer(void *DS, int PlayerID, int GroupID, int Level);//adam

StatusType RemovePlayer(void *DS, int PlayerID);

StatusType ReplaceGroup(void *DS, int GroupID, int ReplacementID);//adam

StatusType IncreaseLevel(void *DS, int PlayerID, int LevelIncrease);

StatusType GetHighestLevel(void *DS, int GroupID, int *PlayerID);//adam

StatusType GetAllPlayersByLevel(void *DS, int GroupID, int **Players, int *numOfPlayers);

StatusType GetGroupsHighestLevel(void *DS, int numOfGroups, int **Players);//adam

void Quit(void** DS);
