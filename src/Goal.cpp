#include "Goal.h"
#include <iostream>
using namespace std;

	// basic constructor destructor
	Goal::Goal() {
	}
    
	Goal::~Goal() {
	}
	// return true because a goal can be moved on by a player
    bool Goal::moveFromActive(const IEntity * ac) const {
        return true;
	}
	// return true if given entity exists 
    bool Goal::moveTo(const IEntity * e) const {
        return (e == NULL);
	}
	// return true because a goal can be moved on by a box
    bool Goal::moveFromNonActive(const IEntity * nc) const {
		return true;
	}
	// return goal enum
	EntityType Goal::getType() const {
		return goal;
	}
