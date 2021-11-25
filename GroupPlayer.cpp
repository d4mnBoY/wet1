//
// Created by abusa on 11/24/2021.
//

#include "GroupPlayer.h"
int GroupPlayer::getPlayerID() const
{
    return playerID;
}
int GroupPlayer::getGroupID() const
{
    return groupID;
}
int GroupPlayer::getLevel() const
{
    return level;
}
void GroupPlayer::setPlayerID(int playerID) const
{
    this.playerID=playerID;
}
void GroupPlayer::setGroupID(int groupID) const
{
    this.groupID=groupID;
}
void GroupPlayer::setLevel(int level) const
{
    this.level=level;
}