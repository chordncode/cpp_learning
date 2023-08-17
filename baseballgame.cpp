#include <iostream>
#include <random>

int* getGameNum();
int getRndNum();

int main(void){

	int* gameNum;
	gameNum = getGameNum();

	for(int i = 0; i < 3; i++){
		std::cout << gameNum[i];
	}
	std::cout << std::endl;

	return 0;

}

int* getGameNum(){

	static int gameNum[3];
	int i = 0;

	while(i < 3){
		int rndNum(getRndNum());

		for(int j = 0;  j < i; j++){
			if(gameNum[j] == rndNum){
				rndNum = -1;
				break;
			}
		}

		if(rndNum != -1){
			gameNum[i] = rndNum;
			i++;
		}

	}

	return gameNum;
}

int getRndNum(){
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dis(1, 9);

	return dis(gen);
}
