/*
 * OperatorConsole.cpp
 *
 *  Created on: Dec. 1, 2022
 *      Author: Bili
 */

#include "OperatorConsole.h"
using namespace std;

OperatorConsole::OperatorConsole(){

}

//Function to send commands from Operator Console to the Communication System
bool OperatorConsole::sendMessage2CommSys(Msg2CommSys msg){

	int server_coid; //server connection ID.

	if ((server_coid = name_open("CommSysChannel", 0)) == -1) {
		printf("Error: channel was not created");

		return false;
	}

	/* Do whatever work you wanted with server connection */

	printf("Client sending %d \n", msg.id);
	if (MsgSend(server_coid, &msg, sizeof(msg), NULL, 0) == -1) {

		printf("Error: Message was not sent");
		return false;

	}
	else {
		printf("The message was sent successfully!");
	}

	/* Close the connection */
	name_close(server_coid);
	return true;
}



//Function to send commands from Operator Console to the Computer System
bool OperatorConsole::sendMessage2ComputerSys(Msg2ComputerSys msg){

	int server_coid; //server connection ID.

	if ((server_coid = name_open("CompSysChannel", 0)) == -1) {
		printf("Error: channel was not created");

		return false;
	}

	// Do whatever work you wanted with server connection

	printf("Client sending %d \n", msg.id);
	if (MsgSend(server_coid, &msg, sizeof(msg), NULL, 0) == -1) {

		printf("Error: Message was not sent");
		return false;

	}
	else {
		printf("The message was sent successfully!");
	}

	//Close the connection
	name_close(server_coid);
	return true;
}



