#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>
using namespace std;

typedef struct _pulse msg_header_t;

typedef enum {OperatorSetAirplaneSpeed, OperatorRequestAirplaneData} Msg2CommSysType;

// Format of the message send to Airplane Threads
typedef struct  {
	msg_header_t hdr;
	Msg2CommSysType type;
	int id;
	double x, y, z;
	double dx, dy, dz;
} Msg2CommSys;

bool sendMessage2CommSys(Msg2CommSys msg){
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

int main() {

	Msg2CommSys msg;
	/* We would have pre-defined data to stuff here */
	msg.hdr.type = 0x00;
	msg.hdr.subtype = 0x01;




	string input;
		cout<<"Enter airplane id: ";
		cin>>input;
		msg.type = OperatorRequestAirplaneData;
		msg.id = stoi(input);
		sendMessage2CommSys(msg);

	return 0;
}
