#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>
#include"OperatorConsole.h"
using namespace std;


int main() {

	OperatorConsole console1;
	int input;
	int planeID;
	int interval;
	double x,y,z;
	double dx,dy,dz;

		cout<<"Please enter the appropriate integer for the desired function: "
				"\n1: Request additional information about an airplane\n"
				"2: Set an airplane's speed and position\n"
				"3: Set the radar system' calculation interval\n"
				"Choice: ";
		cin>>input;

		switch(input){

		case 1:
			cout<<"Requesting additional information about and airplane\n"
			"Please enter the airplane id: "<<endl;
			cin>>planeID;

			Msg2CommSys msg;
			msg.hdr.type = 0x00;
			msg.hdr.subtype = 0x01;
			msg.type = OperatorRequestAirplaneData;
			msg.id = planeID;
			console1.sendMessage2CommSys(msg);
			break;

		case 2:
			cout<<"Changing airplane speed and position\n"
			"Please enter the airplane id: ";
			cin>>planeID;
			cout<<"Position coordinates:\n"
					"x: ";
			cin>>x;
			cout<<"y: ";
			cin>>y;
			cout<<"z: ";
			cin>>z;
			cout<<"\nSpeed parameters:\n"
					"dx: ";
			cin>>dx;
			cout<<"dy: ";
			cin>>dy;
			cout<<"dz: ";
			cin>>dz;

			Msg2CommSys msg2;
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
			console1.sendMessage2CommSys(msg2);
			break;
/*
		case 3:
			cout<<"Changing calculation interval n:"
			"\nPlease enter the new calculation interval n = ";
			cin>>interval;

			Msg2ComputerSys msg3;
			msg3.hdr.type = 0x00;
			msg3.hdr.subtype= 0x01;
			msg3.type = OperatorSetCalculationInterval;
			msg3.calculationInterval = interval;
			console1.sendMessage2ComputerSys(msg3);
			break;
*/
		default:
			cout<<"No input";
			break;
		}

	return 0;
}
