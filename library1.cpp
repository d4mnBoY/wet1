//
// Created by abusa on 11/24/2021.
//
#include "library1.h"
#include "PlayersManager.h"
#include "Player.h"
#include "GroupPlayer.h"



void* Init() {
    PlayersManager *DS = new PlayersManager();
    return (void*)DS;
}
StatusType AddGroup(void *DS, int GroupID){


    return ((PlayersManager*)DS)-> AddGroup (GroupID);
}
StatusType AddPlayer(void *DS, int PlayerID, int GroupID, int Level)
{
    return ((PlayersManager*)DS)-> AddPlayer (PlayerID,GroupID,Level);
}
StatusType RemovePlayer(void *DS, int PlayerID)
{
    return ((PlayersManager*)DS)-> RemovePlayer (PlayerID);
}

StatusType ReplaceGroup(void *DS, int GroupID, int ReplacementID)
{
    return ((PlayersManager*)DS)-> ReplaceGroup (GroupID,ReplacementID);
}
StatusType IncreaseLevel(void *DS, int PlayerID, int LevelIncrease)
{
    return ((PlayersManager*)DS)-> IncreaseLevel (PlayerID,LevelIncrease);
}

StatusType GetHighestLevel(void *DS, int GroupID, int *PlayerID)
{
    return ((PlayersManager*)DS)-> GetHighestLevel (GroupID,PlayerID);
}
StatusType GetAllPlayersByLevel(void *DS, int GroupID, int **Players, int *numOfPlayers)
{
    return ((PlayersManager*)DS)-> GetAllPlayersByLevel(GroupID,Players,numOfPlayers);
}
StatusType GetGroupsHighestLevel(void *DS, int numOfGroups, int **Players)
{
    return ((PlayersManager*)DS)-> GetGroupsHighestLevel(numOfGroups,Players);

}

void Quit(void** DS)
{
    return ((PlayersManager*)DS)-> Quit();//??
}
