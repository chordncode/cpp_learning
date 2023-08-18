#include <iostream>
#include <random>

using namespace std;

int getRndNum();
int* getLottoNum();

int main(void){

	int* lottoNum(getLottoNum());

	cout << "Your Lucky Number is ";
	for(int i(0); i < 6; i++){
		if(i > 0) cout << " ";
		cout << lottoNum[i];
	}
	cout << endl;

	return 0;

}

int getRndNum(){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 45);
	return dis(gen);
}

int* getLottoNum(){

	static int lottoNum[6];

	int i(0);
	while(i < 6){
		int rndNum = getRndNum();

		for(int j(0); j < i; j++){
			if(lottoNum[j] == rndNum){
				rndNum = -1;
				break;
			}
		}

		if(rndNum != -1){
			lottoNum[i] = rndNum;
			i++;
		}
	}	

	return lottoNum;
}
