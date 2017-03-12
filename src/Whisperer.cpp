#include "stdafx.h"
#include <string>
#include <sstream>
#include <algorithm>
#include "Network\Server.h"
#include "boost\thread.hpp"

using namespace std;

int main()
{
	try
	{
		std::cout << "Initializing io_service..." << std::endl;
		boost::asio::io_service io_service;
		std::cout << "Starting server..." << std::endl;
		Server server(io_service, 8888);
		std::cout << "Server started!" << std::endl;

		// Run the blocking io_service method run()
		boost::thread ioThread(
			boost::bind(&boost::asio::io_service::run, &io_service));

		// Game logic and matchmaking logic goes here

		/* 
		1. Create players from the connected clients
		2. Fill their decks with a string from the client
		3. Create a new game object with the vector of created players
		4. Start the game
		*/



		/*
		std::string data;
		while (data != "exit")
		{
			std::getline(std::cin, data);
			server.WriteToAll(data);
		}
		*/

		ioThread.join();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return 0;
}
