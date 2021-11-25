//
// Created by Admin on 11/25/2021.
//

#include "PlayersManager.h"
PlayersManager::PlayersManager()
{
    PlayersTree= new AvlTree<Player>();
    GroupsTree=new AvlTree<GroupPlayer>();
}

{

}
StatusType PlayersManager::AddGroup( int GroupID)
{
    if (this==NULL ||GroupID<=0) return INVALID_INPUT;

}


StatusType PlayersManager::AddPlayer(void *DS, int PlayerID, int GroupID, int Level);//adam

StatusType PlayersManager::RemovePlayer(void *DS, int PlayerID)
{

}

StatusType PlayersManager::ReplaceGroup(void *DS, int GroupID, int ReplacementID);//adam

StatusType PlayersManager::IncreaseLevel(void *DS, int PlayerID, int LevelIncrease);

StatusType PlayersManager::GetHighestLevel(void *DS, int GroupID, int *PlayerID);//adam

StatusType PlayersManager::GetAllPlayersByLevel(void *DS, int GroupID, int **Players, int *numOfPlayers);

StatusType PlayersManager::GetGroupsHighestLevel(void *DS, int numOfGroups, int **Players);//adam

void PlayersManager::Quit(void** DS);
