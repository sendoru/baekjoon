#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

void compressCoordinate(std::vector<int>& coordinate)
{
	std::vector<int> sortedCoordinate = std::vector<int>(coordinate);

	std::sort(sortedCoordinate.begin(), sortedCoordinate.end(), std::less<int>());
	
	std::map<int, int> coordinateMap;

	coordinateMap.insert(std::pair<int, int>(sortedCoordinate[0], 0));

	for (int i = 1; i < sortedCoordinate.size(); i++)
		coordinateMap.insert(std::pair<int, int>(sortedCoordinate[i], coordinateMap[sortedCoordinate[i - 1]]+ 1));

	for (int i = 0; i < coordinate.size(); i++)
		coordinate[i] = coordinateMap[coordinate[i]];
}

int main(void)
{
	int N;
	std::vector<int> coordinate;
	int intInput;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> intInput;
		coordinate.push_back(intInput);
	}

	compressCoordinate(coordinate);

	for (int i = 0; i < N; i++)
	{
		std::cout << coordinate[i] << " ";
	}
	return 0;
}