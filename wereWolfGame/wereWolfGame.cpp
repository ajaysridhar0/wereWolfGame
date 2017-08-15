#include <string>
#include <iostream>
#include <array>
#include <random>
using namespace std;

int main() {
	string player;
	cout << "This game is called werewolf " << endl;
	cout << "1 out of the 15 names displayed (except you) is a werewolf " << endl;
	cout << "Every night the werewolf kills one person" << endl;
	cout << "During the day you can put two people on trial to see who is the werewolf" << endl;
	cout << "20% of the time the werewolf will look calm and the rest of the time the werewolf looks nervous when on trial" << endl;
	cout << "80 of the time a non werewolf will look calm and the rest of the time they look nervous when on trial" << endl;
	cout << "Will you catch the werewolf, or die?" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "what do you call yourself (one word): ";
	cin >> player;
	string names[15] = { "ALi", "LEo", "AjAy", "ChAmp", "RUdy", "NiSHA", "ZElDa", "BOb", "LEbrOn", "MEena", "CArsOn", "JoE", "SrIDHAr", "WalTeR", player };
	string wolf;
	string feeling;
	string nameSuspect1;
	string nameSuspect2;
	int killNum = 0;
	bool plsWork = false;
	int score = 0;
	int suspect = 0;
	int count = 0;
	int pickKill;
	int pNum;
	int kill = 0;
	int round = 0;
	int random2 = 0;
	int suspect2 = 0;
	int input3;
	int playerLeft[15];
	int playerID[15];
	bool trialOn = false;
	string trial(string names, string wolf);
	int reviveAll(int playerLeft[15], string names[15], string wolf);
	int printSurv(int round, int playerLeft[15], int playerID[15], int random, string names[15], string feeling, string wolf);
	int pickTrial(string wolf, int &killNum, int &count, int suspect, int playerID[15], int playerLeft[15], string names[15]);




	int random = 0;
	random_device rd;

	random = rd() % 14 + 0;
	wolf = names[random];
	playerLeft[15] = reviveAll(playerLeft, names, wolf);

	while (true) {
		while (true) {
			for (int i = 0; i < 15; i++) {
				cout << ' ' << endl;
			}
			round++;
			playerID[15] = printSurv(round, playerLeft, playerID, random2, names, feeling, wolf);

			plsWork = false;
			while (!plsWork) {
				kill = rd() % 15 + 0;
				if (playerLeft[kill] == 1) {
					playerLeft[kill] = 0;
					break;
				}
			}
			break;
		}
		trialOn = false;
		while (!trialOn) {
			
			suspect = pickTrial(wolf, killNum, count, suspect, playerID, playerLeft, names);

			suspect2 = pickTrial(wolf, killNum, count, suspect2, playerID, playerLeft, names);

			for (int i = 0; i < 16; i++) {
				if (i == suspect) {
					for (int k = 0; k < 16; k++) {
						if (playerID[k] == suspect) {
							cout << " " << endl;
							nameSuspect1 = names[k];
						}

					}
				}
			}

			for (int i = 0; i < 16; i++) {
				if (i == suspect2) {
					for (int k = 0; k < 16; k++) {
						if (playerID[k] == suspect2) {
							cout << " " << endl;
							nameSuspect2 = names[k];
						}

					}
				}
			}
			
			while (!trialOn) {
				cout << endl;
				cout << "1) " << nameSuspect1 << endl;
				cout << "2) " << nameSuspect2 << endl;
				cout << "Who do you want to kill (pick number): " << endl;
				cin >> pickKill;
				if (pickKill == 1 || pickKill == 2) {
					if (pickKill == 1) {
						cout << nameSuspect1 << " was killed" << endl;
						//break;
						//trialOn = true;
						for (int i = -1; i < 16; i++) {
							if (nameSuspect1 == names[i] && playerLeft[i] != 2) {
								playerLeft[i] = 0;
							}
							if (nameSuspect1 == names[i] && playerLeft[i] == 2) {
								cout << "YOU WIN!" << endl;
								cout << nameSuspect1 << " was the werewolf!" << endl;
								for (int i = 0; i < 15; i++) {
									if (playerLeft[i] == 1) {
										score++;
									}
								}
								cout << "Score: " << score << endl;
								cout << "You will be living in a town with " << score << " people and 0 werewolfs" << endl;
								return 0;
							}
							trialOn = true;

						}

						break;
					}
					else {
						cout << nameSuspect2 << " was killed" << endl;
						for (int i = -1; i < 16; i++) {
							if (nameSuspect2 == names[i] && playerLeft[i] != 2) {
								playerLeft[i] = 0;
							}
							if (nameSuspect2 == names[i] && playerLeft[i] == 2) {
								cout << "YOU WIN!" << endl;
								cout << nameSuspect2 << " was the werewolf!" << endl;
								for (int i = 0; i < 15; i++) {
									if (playerLeft[i] == 1) {
										score++;
									}
								}
								cout << "Score: " << score << endl;
								cout << "You will be living in a town with " << score << " people and 0 werewolfs" << endl;
								return 1;
							}
							trialOn = true;
						}
					}
				}
				if (pickKill != 1 || pickKill != 2) {
					cout << " " << endl;
					cout << "input invalid, please choose (1/2)" << endl;
				}
				

			}
			trialOn = true;
		}
	
		if (playerLeft[14] == 0) {
			cout << "you died" << endl;
			cout << "GAME OVER for " << player << " (x_x)!!!!!" << endl;
			return 0;
		}
	}
}

int pickTrial(string wolf, int &killNum, int &count, int suspect, int playerID[15], int playerLeft[15], string names[15]) {
	string feeling;
	string trial(string name, string wolf);
	bool pick =  false;
	int k = 0;


	while (!pick) {
		
		cout << " " << endl;
		if (count % 2 == 0) {
			cout << "who do you want to go on trial (insert the corresponding number): " << endl;
		}
		else {
			cout << "who else do you want to go on trial (insert the corresponding number): " << endl;
		}
		cin >> suspect;
		cout << " " << endl;

		if (suspect > (15 - killNum)) {
			cout << "input out of range, please try again" << endl;
		}
		else {
			if (isalpha(suspect) != true && suspect != 0) {
				for (int i = 0; i < 15; i++) {
					if (i == suspect) {
						for (k = 0; k < 15; k++) {
							if (playerID[k] == suspect) {
								cout << " " << endl;
								cout << names[k] << endl;
								feeling = trial(names[k], wolf);
								cout << names[k] << feeling << endl;
								count++;
								return suspect;
								killNum -= 2;
		        				pick = true;
								break;

								}

							}
						}
					}
				}


			}
	

		
		
	}

	
}

int printSurv(int round, int playerLeft[15], int playerID[15], int random, string names[15], string feeling, string wolf) {
	int killCount = 0;
	cout << " " << endl;
	cout << " " << endl;
	cout << "Welcome to day " << round << endl;
	cout << " " << endl;
	cout << "players alive: " << endl;
	int pNum = 0;

	for (int i = 0; i < 16; i++) {
		if (playerLeft[i] == 1 || playerLeft[i] == 2) {
			pNum++;
			cout << pNum << ") " << names[i] << endl;
			playerID[i] = pNum;
		}
	}

	cout << " " << endl;
	cout << "players dead: " << endl;
	for (int i = 0; i < 15; i++) {
		if (playerLeft[i] == 0) {
			cout << names[i] << ": (x_x)" << endl;
			playerID[i] = 0;
			killCount++;
		}
	}
	if (killCount == 0) {
		cout << "none" << endl;
	}
	return playerID[15];
}

int reviveAll(int playerLeft[15], string names[15], string wolf)
{
	for (int i = 0; i < 15; i++) {
		playerLeft[i] = 1;

		if (names[i] == wolf) {
			playerLeft[i] = 2;
		}

	}

	return playerLeft[15];
}
string trial(string names, string wolf) {
	string feeling;
	int random = 0;
	random_device random2;
	random = random2() % 10 + 1;

	if (names == wolf) {
		if (random == 1 || random == 3) {
			feeling = " looks calm";
		}
		else
		{
			feeling = " looks nervous";
		}
	}
	else {
		if (random % 2 != 0 && random < 6) {
			feeling = " looks nervous";
		}
		else {
			feeling = " looks calm";
		}
	}
	return feeling;

}