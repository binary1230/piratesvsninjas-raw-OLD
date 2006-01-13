#ifndef OBJ_CONTROLLER_H
#define OBJ_CONTROLLER_H

#include <allegro.h>
#include <vector>
using namespace std;

class GameState;
class Sprite;

#include "object.h"
#include "xmlParser.h"

struct Button {
	bool active;
	Sprite* sprite;
};

class ControllerObject : public Object {
	protected:
		Sprite* controller_sprite;
		vector<struct Button> buttons;

		bool only_show_during_demo;
		
	public:
		bool Init(GameState*);
		void Shutdown();

		void Update();
		void Draw();

		ControllerObject();
		~ControllerObject();

		static Object* New(GameState* gameState, XMLNode &xDef, XMLNode &xObj);
};

#endif // OBJ_CONTROLLER_H
