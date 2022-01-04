#include "BasicModel.h"
#include "BasicLevel.h"
#include <memory>
#include <time.h>
// Basic constructor/ destructor
BasicModel::BasicModel() {
	
}
BasicModel::~BasicModel() {

}

// returns current level as a string
string BasicModel::toString() const {
	return level.get()->toString();
}
// checks if the player has won level side
bool BasicModel::hasWon() const {
	return level.get()->hasWon();
}
// moves the player in given direction
bool BasicModel::move(int xchange, int ychange) {
	return level.get()->move(xchange, ychange);
}
// creates a new random sukoban level
void BasicModel::NewLevel() {
	srand(NULL);
	level = std::shared_ptr<BasicLevel>(new BasicLevel());
	bool needbox = true;
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 25; y++) {

			if (x == 0 || x == 24 || y == 0 || y == 24) {
				level.get()->addEntity(x, y, wall);
			}
			else if (x == 1 && y == 1) {
				level.get()->addEntity(x, y, player);
			}
			else {

				int random = rand() % 100;
				cout << random << "\n";
				if (random < 2 && !(x == 1 || x == 23 || y == 1 || y == 23)) {
					if (needbox) {
						cout << "b \n";
						needbox = false;
						level.get()->addEntity(x, y, box);
					}
					else {
						cout << "g \n";
						needbox = true;
						level.get()->addEntity(x, y, goal);
					}
				}
				if (random > 95) {
					level.get()->addEntity(x, y, wall);
				}
			}
		}
	}
}