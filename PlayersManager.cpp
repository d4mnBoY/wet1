//
// Created by Admin on 11/25/2021.
//

#include "PlayersManager.h"
PlayersManager* PlayersManager::PlayersManager()
{
    playersTree= new AvlTree<Player>();
    groupsTree=new AvlTree<GroupPlayer>();
}

{

}
StatusType PlayersManager::AddGroup( int GroupID)
{
    if (this==NULL ||GroupID<=0)
        return INVALID_INPUT;
    if(groupsTree.get(GroupID))
        return FAILURE;
    groupsTree=insert(groupsTree,GroupID);
    return SUCCESS;
}


StatusType PlayersManager::AddPlayer( int PlayerID, int GroupID, int Level);//adam

StatusType PlayersManager::RemovePlayer( int PlayerID)
{
    if (this==NULL ||PlayerID<=0)
        return INVALID_INPUT;
    if(!playersTree.get(PlayerID))
        return FAILURE;
    playersTree=removeNode(playersTree,GroupID);
    return SUCCESS;
}

StatusType PlayersManager::ReplaceGroup( int GroupID, int ReplacementID);//adam

StatusType PlayersManager::IncreaseLevel( int PlayerID, int LevelIncrease)
{
    if (this==NULL ||PlayerID<=0||LevelIncrease<=0)
        return INVALID_INPUT;
    Player player=playersTree.get(PlayerID);
    if(!player)
        return FAILURE;
    player.levelIncrease(LevelIncrease);
    return SUCCESS;
}

StatusType PlayersManager::GetHighestLevel( int GroupID, int *PlayerID);//adam

StatusType PlayersManager::GetAllPlayersByLevel(int GroupID, int **Players, int *numOfPlayers)
{
    if (this==NULL ||Players== nullptr||numOfPlayers== nullptr||GroupID==0)
        return INVALID_INPUT;
    if(GroupID>0)
    {
        groupsTree gt = groupsTree->get(GroupID);
        if (!gt)
        {
            return FAILURE;
        }
        AvlTree<Player> playerByLevelTree=new AvlTree<Player>();
        if(!playerByLevelTree)
        {
            return ALLOCATION_ERROR;
        }
        playerByLevelTree=addPlayerByLevelTree(playerByLevelTree,gt);
    }
    else
    {

    }
    return SUCCESS;

}
AvlTree<Player> * addPlayerByLevelTree(AvlTree<Player> * tree,AvlTree<Player> group)
{

}

StatusType PlayersManager::GetGroupsHighestLevel( int numOfGroups, int **Players);//adam

void PlayersManager::Quit(void** DS);
