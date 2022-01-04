#include "Player.h"
#include <iostream>
using namespace std;

 // basic constructor destructor
	Player::Player() {
	}

	Player::~Player() {
	}
    // return false because a player can be moved on by a player
    bool Player::moveFromActive(const IEntity * ac) const {
        cout << "Two players should not be overlapped" << endl;
        return false;
    }
    // return  a player can be moved on by a player if the other player does not exist
    bool Player::moveTo(const IEntity * e) const {
        if (e == NULL) {
            return true;
        } else {
            return e->moveFromActive(this);
        }
    }
    // return false because a player can be moved on by a player
    bool Player::moveFromNonActive(const IEntity * nc) const {
        cout << "A player can not be pushed" << endl;
        return false;
    }
    // returns player enum enitity type
	EntityType Player::getType() const {
		return player;
	}
