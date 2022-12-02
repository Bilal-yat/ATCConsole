/*
 * OperatorConsole.h
 *
 *  Created on: Dec. 1, 2022
 *      Author: Bili
 */

#ifndef SRC_OPERATORCONSOLE_H_
#define SRC_OPERATORCONSOLE_H_

#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>
#include <pthread.h>


// Message structs used by components of the ATC

/* We specify the header as being at least a pulse */
/* All of your messages should start with this header */
/* This struct contains a type/subtype field as the first 4 bytes.
 * The type and subtype field can be used to identify the message that is being received.
/ * This allows you to identify data which isn't destined for your server. */

typedef struct _pulse msg_header_t;

//Types of messages sent from the Operator Console to the Communication System
typedef enum {OperatorSetAirplaneSpeed, OperatorRequestAirplaneData} Msg2CommSysType;

//Type of message sent from the Operator Console to the Computer System
typedef enum {OperatorSetCalculationInterval} Msg2ComputerSysType;


// Format of the message sent to Communication System
typedef struct  {
	msg_header_t hdr;
	Msg2CommSysType type;
	int id;
	double x, y, z;
	double dx, dy, dz;
} Msg2CommSys;


// Format of the message sent to Computer System
typedef struct  {
	msg_header_t hdr;
	Msg2CommSysType type;
	int calculationInterval;
} Msg2ComputerSys;

class OperatorConsole{
public:
	OperatorConsole();

	//Function to send commands from Operator Console to the Communication System
	bool sendMessage2CommSys(Msg2CommSys msg);

	//Function to send commands from Operator Console to the Computer System
	bool sendMessage2ComputerSys(Msg2ComputerSys msg);
};



#endif /* SRC_OPERATORCONSOLE_H_ */
