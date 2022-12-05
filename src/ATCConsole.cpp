#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>
#include"OperatorConsole.h"
using namespace std;


int main() {

	//Instantiating an operator console object
	OperatorConsole console1;

	//Declaring input variables to be taken from the user
	int input; //Initial choice of the 3 available functions
	int planeID; //Airplane id
	int interval; //Calculation interval
	double x,y,z; //Airplane position coordinates
	double dx,dy,dz; //Airplane speed parameters

	//Prompting the operator to select the desired function

		cout<<"Please enter the appropriate integer for the desired function: "
				"\n1: Request additional information about an airplane\n"
				"2: Set an airplane's speed and position\n"
				"3: Set the radar system' calculation interval\n"
				"Choice: ";
	//Collecting the operator's choice
		cin>>input;

	//Parsing through the input
		switch(input){

		//Requesting additional information about an airplane
		case 1:
			cout<<"Requesting additional information about and airplane\n"
			//User is required to enter the plane id
			"Please enter the airplane id: "<<endl;
			cin>>planeID;

			//Creating a new message to the communication system
			Msg2CommSys msg;
			//Declaring attributes of the message
			msg.hdr.type = 0x00;
			msg.hdr.subtype = 0x01;
			msg.type = OperatorRequestAirplaneData;
			msg.id = planeID;
			/*Calling the sendMessage2CommSys function to forward
			 the message to the communication system and waiting for a reply*/
			console1.sendMessage2CommSys(msg);
			break;

		//Change an airplane's position and speed
		case 2:
			cout<<"Changing airplane speed and position\n"
			"Please enter the airplane id: ";
			//Collecting the user input id
			cin>>planeID;
			//Collecting the plane's new coordinates
			cout<<"Position coordinates:\n"
					"x: ";
			cin>>x;
			cout<<"y: ";
			cin>>y;
			cout<<"z: ";
			cin>>z;
			//Collecting the plane's new speed parameters
			cout<<"\nSpeed parameters:\n"
					"dx: ";
			cin>>dx;
			cout<<"dy: ";
			cin>>dy;
			cout<<"dz: ";
			cin>>dz;
			//Creating a new message to the communication system
			Msg2CommSys msg2;
			//Declaring attributes of the message
			msg2.hdr.type = 0x00;
			msg2.hdr.subtype= 0x01;
			msg2.type = OperatorSetAirplaneSpeed;
			msg2.id = planeID;
			msg2.x = x;
			msg2.y = y;
			msg2.z = z;
			msg2.dx = dx;
			msg2.dy = dy;
			msg2.dz = dz;
			/*Calling the sendMessage2CommSys function to forward
			the message to the communication system and waiting for a reply*/
			console1.sendMessage2CommSys(msg2);
			break;

		//Changing the computer system' calculation time interval
		case 3:
			//Collecting the new desired interval from the user
			cout<<"Changing calculation interval n:"
			"\nPlease enter the new calculation interval n = ";
			cin>>interval;

			//Creating a new message to the computer system
			Msg2ComputerSys msg3;
			//Declaring attributes of the message
			msg3.hdr.type = 0x00;
			msg3.hdr.subtype= 0x01;
			msg3.type = OperatorSetCalculationInterval;
			msg3.calculationInterval = interval;
			/*Calling the sendMessage2ComputerSys function to forward
			the message to the communication system and waiting for a reply*/
			console1.sendMessage2ComputerSys(msg3);
			break;

		default:
			cout<<"No input";
			break;
		}

	return 0;
}
