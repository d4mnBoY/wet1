//
// Created by abusa on 11/24/2021.
//

#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H
#include "AvlTree.h"
#include "GroupPlayer.h"
class Player{

    int playerID;
    int groupID;
    int level;
    AvlTree<GroupPlayer>* location;

    int getPlayerID() const;
    int getGroupID() const;
    int getLevel() const;
    void setPlayerID(int playerID) const;
    void setGroupID(int groupID) const;
    void setLevel(int level) const;

};


#endif //HW2_PLAYER_H
