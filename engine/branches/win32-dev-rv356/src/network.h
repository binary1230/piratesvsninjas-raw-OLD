#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>
#include "allegro_wrapper.h"
#include <stdlib.h>

#include "gameBase.h"
#include "StdString.h"

class ezSockets;
class GameState;

class GameNetwork : GameBase {
	protected:
		bool is_server;
		ezSockets* socket;
		int port;
		const char* host;

		int SendHandShake();
		int WaitForHandShake();
		int CommonInit(int _port, CString _host);

	public:
		int InitClient(GameState* _game_state, int _port, CString _host);
		int InitServer(GameState* _game_state, int _port);

		void Shutdown();

		~GameNetwork();
		GameNetwork();
};

#endif // NETWORK_H
