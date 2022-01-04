#include "IEntity.h"
#include "Box.h"
#include "Wall.h"
#include "Player.h"
#include <string>
#include "ILevel.h"
#include "BasicLevel.h"

#include "BasicModel.h"


using namespace std;


int main(int argc, char** argv)
{
    BasicModel model = BasicModel();
	model.NewLevel();

	string game = "";
	while (game.compare("gg") != 0) {
		
		cout << "\n \n \n \n";
		if (model.hasWon()) {
			cout << "you won Yay type gg to quit";
		}
		else {
			cout << model.toString();
		}
		getline(cin, game);
		if (game.compare("w") == 0) {
			model.move(0, -1);
		}
		if (game.compare("s") == 0) {
			model.move(0,1);
		}
		if (game.compare("a") == 0) {
			model.move(-1,0);
		}
		if (game.compare("d") == 0) {
			model.move(1,0);
		}
	}

    return 0;
}


