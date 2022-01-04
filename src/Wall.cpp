#include "Wall.h"
#include <iostream>
using namespace std;

    // basic constructor destructor
	Wall::Wall() {
	}

	Wall::~Wall() {
	}

    // return false because a wall cannot be moved by a player 
    bool Wall::moveFromActive(const IEntity * ac) const {
        return false;
    }
    // return false because a wall cannot be move
    bool Wall::moveTo(const IEntity * e) const {
        cout << "A wall can not move" << endl;
        return false;
    }
    // return false because a wall cannot be moved by a non-player 
    bool Wall::moveFromNonActive(const IEntity * nc) const {
        return false;
    }
    // return enum type
	EntityType Wall::getType() const {
		return wall;
	}

