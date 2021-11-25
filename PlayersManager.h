//
// Created by Admin on 11/25/2021.
//

#ifndef WET1111_PLAYERSMANAGER_H
#define WET1111_PLAYERSMANAGER_H

#include "AvlTree.h"
#include "Player.h"
#include "GroupPlayer.h"
#include "library1.h"

class PlayersManager {
    AvlTree<Player> *playersTree;
    AvlTree<AvlTree<GroupPlayer>> *groupsTree;
    PlayersManager();
    StatusType AddGroup( int GroupID);


StatusType AddPlayer(void *DS, int PlayerID, int GroupID, int Level);//adam

StatusType RemovePlayer(void *DS, int PlayerID)
{

}

StatusType ReplaceGroup(void *DS, int GroupID, int ReplacementID);//adam

StatusType IncreaseLevel(void *DS, int PlayerID, int LevelIncrease);

StatusType GetHighestLevel(void *DS, int GroupID, int *PlayerID);//adam

StatusType GetAllPlayersByLevel(void *DS, int GroupID, int **Players, int *numOfPlayers);

StatusType GetGroupsHighestLevel(void *DS, int numOfGroups, int **Players);//adam

void Quit(void** DS);


#endif //WET1111_PLAYERSMANAGER_H
};