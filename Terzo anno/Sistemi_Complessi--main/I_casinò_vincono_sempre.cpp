     #include <stdlib.h>     
#include <time.h> 
#include <iostream>
#include<cmath>
#include<random>
#include<chrono>
class TIMER {
public:
	TIMER() {
		m_StartTimePoint = std::chrono::high_resolution_clock::now();

	}
	~TIMER() {
		Stop();
	}
	void Stop() {
		auto endTimePoint = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
		auto duration = stop - start;
		double ms = duration * 0.001;
		std::cout << duration << " us\n";
		std::cout << ms << " ms\n";


	}
private:
	std::chrono::time_point< std::chrono::high_resolution_clock> m_StartTimePoint;
};
int constexpr N = 4000;
int constexpr S = 200;
int main()
{
	srand(time(NULL));
	int counter = 0;
	int num = 0;
	int n = 0;
	int cb_money = N;
	int cs_money = S;
	{
		TIMER time;
	while (cs_money != 0 && cb_money != 0) {
		num = std::rand() % 2;
		if (num == 1) {
			cs_money++;
			cb_money--;
			counter++;
		}
		else {
			cb_money++;
			cs_money--;

		}

		n++;
	}
	}
	std::cout << "soldi banca : " << cb_money << "\n";
	std::cout << "Soldi giocatore: " << cs_money << "\n";
}
