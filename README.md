# RythmGame

## HitObject properties :

	Type (char):

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
	int : time, endTime
	char : type, direction

	type;direction;time;...

## Hit Time / Accuracy :

	50Milliseconds   /  1  : Perfect

	150Milliseconds  / 1/3 : Great

	300Milliseconds  / 1/6 : Meh

	300Milliseconds+ /  0  : Miss


	Coin and Chainsaw Hit Time : Great

## Score :

	Perfect  : +300 score

	Great    : +100 score

	Meh      : +50 score

	Coin     : +25 score

	Mash hit : +10 score