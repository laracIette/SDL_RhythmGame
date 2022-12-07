# RythmGame


## TODO:
	Check
	Slider :
		if Hoovered, show it,
		maybe Hide text ?
		Or lower alpha

	Menu FPS = Gameplay FPS
	but caps at 60 or 120.

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
	int  : time, endTime
	char : type, direction

	type;direction;time;...



## Hit Time / Accuracy :

	50ms   /  1  : Perfect

	150ms  / 1/3 : Great

	300ms  / 1/6 : Meh

	300ms+ /  0  : Miss


	Coin and Chainsaw Hit Time : Great



## Score :

	Perfect  : +300 score

	Great    : +100 score

	Meh      : +50 score

	Coin     : +25 score

	Mash hit : +10 score



## Rendering Priority :

	Goes from 0 : Highest priority, to 9 : Lowest priority


### Settings :


#### 0 :

#### 1 :

#### 2 :

#### 3 :

	Settings Setting Options Text

#### 4 :

	Settings Setting Options Box

#### 5 :

	Settings Setting Text
	Settings Setting Check Box

#### 6 :

	Settings Setting Slider Bar

#### 7 :

	Settings Setting Box
	Settings Category Text

#### 8 :

	Settings Category Box

#### 9 :

	Settings Window



### StartScreen :


#### 0 :

#### 1 :

#### 2 :

#### 3 :

#### 4 :

#### 5 :

#### 6 :

#### 7 :

	StartScreen Quit Window

#### 8 :

	StartScreen Buttons

#### 9 :

	StartScreen Background



### MapSelection :


#### 0 :

#### 1 :

#### 2 :

#### 3 :

#### 4 :

#### 5 :

#### 6 :

#### 7 :

#### 8 :

	MapSelection SongTile

#### 9 :

	MapSelection Background



### Gameplay :


#### 0 :

#### 1 :

#### 2 :

#### 3 :

#### 4 :
	Gameplay Pause

#### 5 :

	Gameplay UI

#### 6 :

	Gameplay Dim
	Gameplay Player

#### 7 :

	Gameplay HitObjects

#### 8 :

	Gameplay Background

#### 9 :

