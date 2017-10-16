#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float outCalculate(float* w, int x, int y);

int main(){
	srand(time(NULL));

	const int INST_NUM = 4;
	float learnRate = 0.4;
	int iter = 0;
	float localError, globalError;
	int x[INST_NUM];
	int y[INST_NUM];
	int out[INST_NUM];
	float* w = new float(3);
	int MAX = 400;


	for (int i = 0; i < 3; i++)
	{
		w[i] = (rand() % 10) / 10.0;
	}

	x[0] = 0; y[0] = 0;
	x[1] = 0; y[1] = 1;
	x[2] = 1; y[2] = 0;
	x[3] = 1; y[3] = 1;

	out[0] = 0;
    out[1] = 0;
	out[2] = 0;
	out[3] = 1;

	

	do{
		iter++;
		globalError = 0;
		for (int i = 0; i < INST_NUM; i++){
			float output = outCalculate(w, x[i], y[i]);

			localError = out[i] - output;
			w[0] += localError * learnRate * x[i];
			w[1] += localError * learnRate * y[i];
			w[2] += learnRate * localError;
			globalError += (localError*localError);
		}


		
	} while (globalError != 0 && iter < MAX);

	//cout << w[0] << endl << w[1] << endl << w[2] << endl;
	cout << endl << "Tempo nauczania: " << learnRate << endl;
	cout << "Zestaw danych: " << endl;
	cout << "x1 = 0, y1 = 0" << endl;
	cout << "x2 = 0, y2 = 1" << endl;
	cout << "x3 = 1, y3 = 0" << endl;
	cout << "x4 = 1, y4 = 1" << endl;
	cout << "out1 = 0" << endl;
	cout << "out2 = 0" << endl;
	cout << "out3 = 0" << endl;
	cout << "out4 = 1" << endl << endl;
	cout << "Wykonane iteracje: " << iter << endl;
	cout << "Koncowe rownanie: " << w[0] << "*x + " << w[1] << "*y + " << w[2] << " = 0" << endl << endl;

	system("PAUSE");
}

float outCalculate(float* w, int x, int y){
	float treshold = 0.0;
	float sum = (x*w[0] + y*w[1] + w[2]);
	return (sum >= treshold) ? 1 : 0;
}