//SoundEngine.h
#ifndef __SOUNDENGINE_H_INCLUDED //if x.h hasn't been included yet...
#define __SOUNDENGINE_H_INCLUDED //#define this so the compiler knows it has been included

class SoundEngine {

public:
	//State Variables


	//Constructor
	SoundEngine();
	//SoundEngine(char*);

	//Destructor
	//~SoundEngine();
	//~SoundEngine(char*);

	//Methods
	int initialize();
	int closeEngine();
	int playSound(char*);
	int playSoundFull(char*);
private:

};

#endif
