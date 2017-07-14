#include <iostream>
using namespace std;

#define D 3 // Numero input
#define K 1 // Numero  output
#define DIMENSIONE_SAMPLE 4
#define LEARNING_RATE 0.005
#define EPSILON 0.0025 // Soglia del delta dei pesi sotto la quale si è raggiunta la convergenza

int x[DIMENSIONE_SAMPLE][D] = {
	{ 2,1,4 },{ 6,1,12 },{ 5,1,10 },{ 3,1,6 }
}; // Sample in input

int r[DIMENSIONE_SAMPLE][K] = {
	4, 12, 10, 6
}; // Sample in uscita (risultati attesi)


void main() {
	long double w[D][K] = { 0.02, 0.01, 0.06 }; // Pesi dei percettroni
	int t; // Elemento del sample sotto esame
	int i; // Neurone sotto esame
	int j; // Input sotto esame

	//Stampa intestazione
	for (i = 0; i < K; i++)
		for (j = 0; j < D; j++)
			cout << "w[" << j << "][" << i << "]  \t";
	cout << "maxDelta  \t" << "16" << endl << endl;

	long double maxDelta;
	do {
		maxDelta = 0;

		for (t = 0; t < DIMENSIONE_SAMPLE; t++) {
			long double o[K]; //somma delle sinapsi che convergono su ogni percettrone
			long double y[K]; // output dei percettroni

			for (i = 0; i < K; i++) {
				o[i] = 0;
				for (j = 0; j < D; j++)
					o[i] = o[i] + w[j][i] * x[t][j];
			}

			for (i = 0; i < K; i++)
				y[i] = o[i]; // TODO: sigmoide

			for (i = 0; i < K; i++) {
				for (j = 0; j < D; j++) {
					long double delta = LEARNING_RATE*(r[t][i] - y[i])*x[t][j];
					w[j][i] += delta;
					maxDelta = delta > maxDelta ? delta : maxDelta; // maxDelta è il più grande fra se stesso e delta
				}
			}
		}

		// Stampa il valore temporaneo di ogni neurone, il delta massimo e il risultato con i pesi attuali
		for (i = 0; i < K; i++)
			for (j = 0; j < D; j++)
				cout << w[j][i] << "   \t";
		cout << maxDelta << "   \t" << w[0][0] * 8 + w[1][0] * 1 + w[2][0] * 16 << endl;
	} while (EPSILON < maxDelta);


	cin >> t;
}