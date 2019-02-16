#ifndef _Input_H_
#define _Input_H_

#include <switch.h>

#define ACTION_1		KEY_SL
#define ACTION_2		KEY_SR
#define EXIT			(KEY_PLUS	| KEY_MINUS)
#define UP				(KEY_DRIGHT	| KEY_Y)
#define DOWN			(KEY_DLEFT	| KEY_A)
#define LEFT			(KEY_DUP	| KEY_B)
#define RIGHT			(KEY_DDOWN	| KEY_X)
#define SPECIAL_1		(KEY_L		| KEY_R)
#define SPECIAL_2		(KEY_ZL		| KEY_ZR)
class Input {
public:
	static u64 getInputDown(unsigned player) { 
		switch (player) {
		case 0:
			return hidKeysDown(CONTROLLER_PLAYER_1);
			break;
		case 1:
			return hidKeysDown(CONTROLLER_PLAYER_2);
			break;
		case 2:
			return hidKeysDown(CONTROLLER_PLAYER_3);
			break;
		default:
			return hidKeysDown(CONTROLLER_PLAYER_4);
			break;
		}
	};
};

#endif
