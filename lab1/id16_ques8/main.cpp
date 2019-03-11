/*
Viết chương trình hỗ trợ tính cước taxi.



Biết rằng phí dịch vu taxi theo 4 trường hợp dưới đây của chiều dài đường đi d :


– d <= 1 km : giá phải trả là 15 000 VND/km,


– 1 km < d <= 10 km : giá phải trả là 8 000 VND/km,


– 10 km < d <= 30 km : giá phải trả là 6 000 VND/km,


– d > 30 km : giá phải trả là 4 000 VND/km.



Input: gồm 1 thông số mô tả chiều dài đường đi d
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

float calculateTaxiFare(float distance) {
      if(distance<=1) return 15000;
      else if(1<=distance && distance<=10) return 8000;
      else if(10<distance && distance<=30) return 6000;
      else return 4000;
}

int main(int narg, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1], ifstream::in);

	float distance;
	string line;

	for (int count = 0; ifs.good() && count < 1; count++) {
		getline(ifs, line);
		switch (count)
		{
			case 0:
				distance = stof(line);
				break;
			default:
				break;
		}
	}
	ifs.close();

	cout << std::fixed << std::setprecision(0) << calculateTaxiFare(distance);

	return 0;
}
