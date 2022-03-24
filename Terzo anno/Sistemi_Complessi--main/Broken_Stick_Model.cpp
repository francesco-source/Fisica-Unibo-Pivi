
//concetto di un sistema con memoria infinita, dopo il taglio butto via la parte
//tagliata del bastoncino.

#include <iostream>
#include<vector>
#include<random>
#include<ctime>
#include<numeric>

constexpr int dimension = 20;
constexpr int time_ = 1000001;
int main()
{
	std::vector<int> memory;
	int cut = 0;
	int stick = dimension;
	srand(time(NULL));
	for (int i = 0; i < time_; ++i) {
		cut = rand() % dimension+1;
		memory.push_back(cut);
		
	}
	int sum = std::accumulate(memory.begin(), memory.end(), 0);
	std::cout << " In media il segmento è stato tagliato a : " << static_cast<double>(sum / memory.size()) << "\n";
	
}

