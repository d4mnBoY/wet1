//
// Created by abusa on 11/24/2021.
//

#ifndef HW2_GROUPPLAYER_H
#define HW2_GROUPPLAYER_H

class GroupPlayer{
    int playerID;
    int groupID;
    int level;
    int getPlayerID() const;
    int getGroupID() const;
    int getLevel() const;
    void setPlayerID(int playerID) const;
    void setGroupID(int groupID) const;
    void setLevel(int level) const;
};


#endif //HW2_GROUPPLAYER_H
