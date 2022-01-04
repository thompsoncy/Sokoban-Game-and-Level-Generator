#include "Box.h"
#include <iostream>

using namespace std;

	// basic constructor destructor
	Box::Box() {
	}
    
	Box::~Box() {
	}

	// return true because a box cannot be moved by a player 
    bool Box::moveFromActive(const IEntity * ac) const {
        return true;
	}

	// return false because a box cannot be moved by itself  
    bool Box::moveTo(const IEntity * e) const {
		return false;
	}
	// return true because a box cannot be moved by another box
    bool Box::moveFromNonActive(const IEntity * nc) const {
		return false;
	}
	// returns the fact this is a box
	EntityType Box::getType() const {
		return box;
	}
