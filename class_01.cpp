#include <iostream>
#include <cstring>

using namespace std;

class Car{

	enum{
		MODEL_NM_LEN = 40,
		MAX_PRICE = 10000
	};

	private:
		char modelNm[MODEL_NM_LEN];
		int price;

	public:
		
		void setModelNm(const char* iModelNm){
			strcpy(modelNm, iModelNm);
		}
		char* getModelNm(){
			return modelNm;
		}
		void setPrice(int iPrice){
			price = iPrice;
		}
		int getPrice(){
			return price;
		}
};


int main(){

	char str[100];
	int num;

	Car car;
	cout << "Your Car Name : ";
	cin >> str;
	car.setModelNm(str);

	cout << "Car Price : ";
	cin >> num;
	car.setPrice(num);

	cout << "Car Name : " << car.getModelNm() << endl;
	cout << "Car Price : " << car.getPrice() << endl;


	return 0;
}
