#include "BasicLevel.h"
#include <iostream>
#include <list>
#include "IEntity.h"
#include "Box.h"
#include "Player.h"
#include "Wall.h"
#include "Goal.h"
#include <sstream>
#include <map>

using namespace std;


// constructs the level by creating a list for every location on the board
// which can be used to house more than one entity
BasicLevel::BasicLevel() {
	goalcount = 0;
	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 25; x++) {
			level[x][y] = make_shared<list<shared_ptr<IEntity>>>();
		}
	}
}

// basic deconstructor assumes the game is over
BasicLevel::~BasicLevel() {

}

// assures that the basic features are valid
bool BasicLevel::isLevelValid() const {
	if (goalcount < 2 || goalcount > 5) {
		return false;
	}
	return true;
}

// converts level to a string with w for wall b for box p for player g for goal
// z for goal and box and y for player and goal
string BasicLevel::toString() const {
	stringstream str;
	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 25; x++) {
			if (level[x][y].get()->size() == 0) {
				str << 'e';
			}
			else if (level[x][y].get()->size() == 1) {
				switch (level[x][y].get()->front().get()->getType())
				{
				case (box): {
					str << 'b';
					break;
				}
				case (player): {
					str << 'p';
					break;
				}
				case (wall): {
					str << 'w';
					break;
				}
				case (goal): {
					str << 'g';
					break;
				}
				default:
					break;
				}
			}
		
			else {
				switch (level[x][y].get()->front().get()->getType())
				{
				case (box): {
					str << 'z';
					break;
				}
				case (player): {
					str << 'y';
					break;
				}
				default:
					break;
				}
			}
		}
		str << '\n';
	}
	return str.str();
}


// adds entity of given type to the list at given location 
void BasicLevel::addEntity(int x, int y, EntityType entitytype) {
	switch (entitytype)
	{
	case (box): {
		level[x][y].get()->push_back(make_shared<Box>());
		boxes.push_back(y * 25 + x);
		break;
	}
	case (player): {
		level[x][y].get()->push_back(make_shared<Player>());
		playerx = x;
		playery = y;
		break;
	}
	case (wall): {
		level[x][y].get()->push_back(make_shared<Wall>());
		cout << x << " " << y << "\n";
		break;
	}
	case (goal): {
		level[x][y].get()->push_back(make_shared<Goal>());
		goals.push_back( y *25 + x);
		goalcount++;
		break;
	}
	default:
		break;
	}
}

// checks if the boxes cover up all goals
bool BasicLevel::hasWon() const {
	for (int i = 0; i < goalcount; i++) {
		if (level[goals[i] % 25][goals[i] / 25].get()->size() != 2) {
			return false;
		}
		if (level[goals[i] % 25][goals[i] / 25].get()->front().get()->getType() != box)
		{
			return false;
		}
	}
	return true;
}

// attempts to move the player in a given direction returns true if succsessful
// and false otherwise
bool BasicLevel::move(int xchange, int ychange) {
	// is player moving to empty location
	if (level[xchange + playerx][ychange + playery].get()->empty()) {
		// move the player
		level[xchange + playerx][ychange + playery].get()->push_front(level[playerx][playery].get()->front());
		level[playerx][playery].get()->pop_front();
		playerx = xchange + playerx;
		playery = ychange + playery;
		return true;
	}
	// is player moving to a location that is a goal
	if (level[ playerx][ playery].get()->front().get()->moveTo(level[xchange + playerx][ychange + playery].get()->front().get()) && level[xchange + playerx][ychange + playery].get()->front().get()->getType() != box) {
		// move the player
		level[xchange + playerx][ychange + playery].get()->push_front(level[playerx][playery].get()->front());
		level[playerx][playery].get()->pop_front();
		playerx = xchange + playerx;
		playery = ychange + playery;
		return true;
	}
	// is player moving to a location with a box
	if (level[ playerx][playery].get()->front().get()->moveTo(level[xchange + playerx][ychange + playery].get()->front().get())) {
		// if the box can be pushed
		if (level[xchange + xchange + playerx][ychange + ychange + playery].get()->empty() || level[xchange + playerx][ychange + playery].get()->front().get()->moveTo(level[xchange + xchange + playerx][ychange + ychange + playery].get()->front().get())) {
			// move the box
			level[xchange + xchange + playerx][ychange + ychange + playery].get()->push_front(level[xchange + playerx][ychange + playery].get()->front());
			level[xchange + playerx][ychange + playery].get()->pop_front();
			// move the player
			level[xchange + playerx][ychange + playery].get()->push_front(level[playerx][playery].get()->front());
			level[playerx][playery].get()->pop_front();
			playerx = xchange + playerx;
			playery = ychange + playery;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
