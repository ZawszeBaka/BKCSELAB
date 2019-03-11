/*
Viết hàm chuyển đổi giữa các đơn vị đo nhiệt độ khác nhau.

Các option:
- Option 1:
1 : Yêu cầu chuyển đổi từ nhiệt độ Fahreneit sang Selsius
2 : Yêu cầu chuyển đổi từ nhiệt độ Selsius sang Fahreneit
- Option 2:
0 : Không yêu cầu làm tròn.
1 : Yêu cầu làm tròn đến 2 chữ số thập phân.

Input: gồm 3 thông số:
1 : Giá trị nhiệt độ
2&3 : để mô tả các option 1 và 2 như nêu trên

Mở rộng: tham khảo các loại nhiệt độ khác trên Wiki
https://vi.wikipedia.org/wiki/%C4%90%E1%BB%99_(nhi%E1%BB%87t_%C4%91%E1%BB%99)


*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

float convertTemperature(float temperature, int option, int isRound) {

    if(option==1){
        // F -> C
        temperature = (temperature-32)* 5.0/9.0;
    }else{
        // C -> F
        temperature = temperature * 9.0 / 5.0 + 32;
    }

    if(isRound==1) return roundf(temperature * 100.0)/(100.0);
    else return temperature;

}
main(int narg, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1], ifstream::in);

	float temperature;
	int option;
	int round;
	string line;

	for (int count = 0; ifs.good() && count < 3; count++) {
		getline(ifs, line);
		switch (count)
		{
			case 0:
				temperature = stof(line);
				break;
			case 1:
				option = stoi(line);
				break;
			case 2:
				round = stoi(line);
				break;
			default:
				break;
		}
	}

	ifs.close();

	cout << temperature << " " << ((option == 1) ? "F" : "C") << " -> ";
	cout << convertTemperature(temperature, option, round) << ((option == 2) ? " F" : " C");

	return 0;
}
