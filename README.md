# SDL_RythmGame

## HitObject properties :

	Type (unsigned char):

		1. Note :
			isUp
		2. Hold :
			isUp
			endTime
		3. Double :

		4. Mash :
			endTime
		5. Ghost :
			isUp
		6. Coin :
			isUp
		7. Hammer :
			isUp
		8. Chainsaw :
			isUp


	bool : isUp
	unsigned int : time, endTime
	unsigned char : type, direction

	type;direction;time;...

## Hit Time / Accuracy :

	50ms   /  1  : Perfect

	150ms  / 1/3 : Great

	300ms  / 1/6 : Meh

	300ms+ /  0  : Miss