/*****************************************************************************/
/*
Sistema con memoria finita.

Noto uno stato n non ho previsioni sullo stato n + 1 se non di 
massima incertezza rispetto alla futura posizione occupata.
Ho due casi:
1) equi probabilità rispetto alle future direzioni
2) probabilità differente in una direzione, si crea un flusso di probabilità.
Nel secondo caso andare in una direzione del tempo è privilegiata rispetto ad un altra.
Nella sequenza sarà più volte presente un certo ordine della sequenza rispetto ad un altro. 
Questo è la causa di un sistema irreversibile in fisica.
All' equilibrio è prediletta una certa freccia del tempo.*/
/***********************************************************************************************/

#include <iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<random>
#include<numeric>
#include<string>
constexpr char A='A';
constexpr char B = 'B';
constexpr char C = 'C';
constexpr int time_ = 1000000;
constexpr double equal_prob = 0.5;
constexpr double not_equal_prob = 1. / 3;
int main()
{
	//senza flusso di probabilità
	srand(time(NULL));
	std::vector<double> prob{equal_prob};
	std::vector<char> memory = {A};
	std::vector<char> memory2 = { A };
	int upperLimitToGenerate = 1 / equal_prob;
	int random = 0;
	std::vector<char> state = {C,A,B,C,A};
	for (int i = 0; i < time_; ++i) {
		for (int j = 1; j <= 3; ++j) {
			random = rand() % upperLimitToGenerate;
			if (random == 1) {
				memory.push_back(state[j + 1]);
			}
			if (random == 0) {
				memory.push_back(state[j - 1]);
			}
		}
	}
		std::cout << "NEL CASO DI EGUALE PROBABILITA' :" << "\n";
		int numA= std::count(memory.begin(), memory.end(), A);
		int numB = std::count(memory.begin(), memory.end(), B);
		int numC = std::count(memory.begin(), memory.end(), C);
		std::cout << "PROBABILITA' DI A= " << static_cast<double>(numA) / memory.size() << "\n";
		std::cout << "PROBABILITA' DI B= " << static_cast<double>(numB) / memory.size() << "\n";
		std::cout << "PROBABILITA' DI C= " << static_cast<double>(numC) / memory.size() << "\n";
		//*****************************************************************************************/
		//Ora il caso di un flusso di probailità
		//****************************************************************************************/
		upperLimitToGenerate = 1 / not_equal_prob;
		for (int i = 0; i < time_; ++i) {
			for (int j = 1; j <= 3; ++j) {
				random = rand() % upperLimitToGenerate;
				if (random >= 1) {
					memory2.push_back(state[j + 1]);
				}
				if (random == 0) {
					memory2.push_back(state[j - 1]);
				}
			}
		}
		std::cout << "NEL CASO DI DIVERSA PROBABILITA' :" << "\n";
		numA = std::count(memory2.begin(), memory2.end(), A);
		numB = std::count(memory2.begin(), memory2.end(), B);
		numC = std::count(memory2.begin(), memory2.end(), C);
	//completa il programma inserendo la possibilità di calcolare quante volte compare la sequenza ABC
		std::cout << "PROBABILITA' DI A= " << static_cast<double>(numA) / memory2.size() << "\n";
		std::cout << "PROBABILITA' DI B= " << static_cast<double>(numB) / memory2.size() << "\n";
		std::cout << "PROBABILITA' DI C= " << static_cast<double>(numC) / memory2.size() << "\n";

		/*Risultato del modello: 
		Anche se ho definito un flusso di probabilità la probabilità finale di ottenere un elemento è sempre 1/3,
		ciò che cambia è l'ordine. Si è definita una freccia del tempo.
		Sel secondo caso il sistema è irreversibile, nel primo no*/
