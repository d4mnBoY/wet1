//
// Created by abusa on 11/24/2021.
//
#include "library1.h"
#include "PlayersManager.h"
#include "Player.h"
#include "GroupPlayer.h"



void* Init() {

}
StatusType AddGroup(void *DS, int GroupID){



}
StatusType AddPlayer(void *DS, int PlayerID, int GroupID, int Level)
{

}
StatusType RemovePlayer(void *DS, int PlayerID)
{

}

StatusType ReplaceGroup(void *DS, int GroupID, int ReplacementID)
{

}
StatusType IncreaseLevel(void *DS, int PlayerID, int LevelIncrease)
{

}

StatusType GetHighestLevel(void *DS, int GroupID, int *PlayerID)
{

}
StatusType GetAllPlayersByLevel(void *DS, int GroupID, int **Players, int *numOfPlayers)
{

}
StatusType GetGroupsHighestLevel(void *DS, int numOfGroups, int **Players)
{


}

void Quit(void** DS)//adam
{

}
