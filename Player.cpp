//
// Created by abusa on 11/24/2021.
//

#include "Player.h"
int Player::getPlayerID() const
{
    return playerID;
}
int Player::getGroupID() const
{
    return groupID;
}
int Player::getLevel() const
{
    return level;
}
void Player::setPlayerID(int playerID) const
{
    this.playerID=playerID;
}
void Player::setGroupID(int groupID) const
{
    this.groupID=groupID;
}
void Player::setLevel(int level) const
{
    this.level=level;
}

void Player::levelIncrease(int levelIncrease) const
{
    this.level+=levelIncrease;
}