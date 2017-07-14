#include <iostream>
using namespace std;

#define D 3 // Numero input
#define K 1 // Numero  output
#define DIMENSIONE_SAMPLE 4
#define LEARNING_RATE 0.006
#define NUMERO_ITERAZIONI 100

int x[DIMENSIONE_SAMPLE][D] = {
	{ 2,1,4 },{ 6,1,12 },{ 5,1,10 },{ 3,1,6 }
}; // Sample in input

int r[DIMENSIONE_SAMPLE][K] = {
	4, 12, 10, 6
}; // Sample in uscita (risultati attesi)


void main() {
	double w[D][K] = { 0.02, 0.01, 0.06 }; // Pesi dei percettroni

	int it; // Iterazione attuale
	for (it = 0; it < NUMERO_ITERAZIONI; it++) {
		std::cout << it << " \t";

		int t; // Elemento del sample sotto esame
		int i; // Neurone sotto esame
		int j; // Input sotto esame

		for (t = 0; t < DIMENSIONE_SAMPLE; t++) {
			double o[K], //somma delle sinapsi che convergono su ogni percettrone
				y[K]; // output dei percettroni

			for (i = 0; i < K; i++) {
				o[i] = 0;
				for (j = 0; j < D; j++)
					o[i] = o[i] + w[j][i] * x[t][j];
			}

			for (i = 0; i < K; i++)
				y[i] = o[i]; // TODO: sigmoide

			for (i = 0; i < K; i++) {
				for (j = 0; j < D; j++)
					w[j][i] = w[j][i] + LEARNING_RATE*(r[t][i] - y[i])*x[t][j];
			}

			cout << w[j] << "   \t"; // Stampa il valore temporaneo di ogni neurone

		}
		cout << endl;
	}

	cout << w[0][0] * 8 + w[1][0] * 1 + w[2][0] * 16; // la prova dovrebbe dare 16
	cin >> it;
}
