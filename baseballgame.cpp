#include <iostream>
#include <random>

int* getGameNum();
int getRndNum();
int* splitInputNum(int input);

int getStrikeCount(int* gameNum, int* numArr);
int getBallCount(int* gameNum, int* numArr);

int main(void){

	int* gameNum;
	gameNum = getGameNum();

//	for(int i = 0; i < 3; i++){
//		std::cout << gameNum[i];
//	}
//	std::cout << std::endl;


	while(1){
		
		int input;

		std::cout << "Input 3 Numbers : ";
		std::cin >> input; 

		if(input > 999){
			std::cout << "Invalid Number" << std::endl;
			continue;
		}

		int* numArr = splitInputNum(input);

		int strike (getStrikeCount(gameNum, numArr));
		int ball (getBallCount(gameNum, numArr));

		if(strike == 3) break;

		std::cout << strike << "S" << ball << "B" << std::endl;	

	}

	std::cout << "You Win!" << std::endl;

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

int* splitInputNum(int input){

	static int numArr[3];

	numArr[0] = input / 100;
	numArr[1] = (input / 10) % 10;
	numArr[2] = input % 10; 

	return numArr;

}

int getStrikeCount(int* gameNum, int* numArr){

	int strike = 0;

	for(int i = 0; i < 3; i++){
		if(gameNum[i] == numArr[i]){
			strike++;
		}
	}
	
	return strike;
}

int getBallCount(int* gameNum, int* numArr){

	int ball = 0;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
			if(gameNum[i] == numArr[j]){
				ball++;
			}
		}
	}

	return ball;
}
