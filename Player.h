//
// Created by abusa on 11/24/2021.
//

#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H
#include "AvlTree.h"
#include "GroupPlayer.h"
class Player{

    int PlayerID;
    int GroupID;
    int Level;
    AvlTree<GroupPlayer>* location;



};


#endif //HW2_PLAYER_H
