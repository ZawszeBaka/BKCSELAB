/*
Viết chương trình hỗ trợ tính toán hình học



Các option dùng để trả về kết quả:


1 : tính chu vi của tam giác có chiều dài các cạnh là A, B và C;


2 : tính chu vi của hình chữ nhật có chiều dài là A và chiều rộng là B;


3 : tính chu vi của hình vuông có chiều dài cạnh là A;


4 : tính chu vi của đường tròn có bán kính là A;


5 : tính diện tích của tam giác có chiều dài các cạnh là A, B và C;


6 : tính diện tích của hình chữ nhật có chiều dài là A và chiều rộng là B;


7 : tính diện tích của hình vuông có chiều dài cạnh là A;


8 : tính diện tích của đường tròn có bán kính là A.



Input: gồm tối đa 4 thông số:


1 : mô tả option như nêu trên


2-4 : các thông số A, B, C cần thiết (phụ thuộc vào option được chọn)


*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

#define PI 3.1415
double calculateGeometry(int option, double A, double B = 0, double C = 0) {
    int d;
    switch(option){
      case 1: return (A+B+C);
      case 2: return (A+B)*2;
      case 3: return (A*4);
      case 4: return (2*PI*A);
      case 5:
        d = (A+B+C);
        return sqrt(d/2*(d/2-A)*(d/2-B)*(d/2-C));
      case 6: return (A*B);
      case 7: return (A*A);
      case 8: return (PI*A*A);
    }
}

int main(int narg, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1], ifstream::in);

	double A, B, C;
	int option;
	string line;

	for (int count = 0; ifs.good() && count < 4; count++) {
		getline(ifs, line);
		switch (count)
		{
			case 0:
				option = stoi(line);
				break;
			case 1:
				A = stod(line);
				break;
			case 2:
				B = stod(line);
				break;
			case 3:
				C = stod(line);
				break;
			default:
				break;
		}
	}
	ifs.close();

	cout << std::fixed << std::setprecision(4);

	switch (option)
	{
		case 1:
			cout << calculateGeometry(option, A, B, C);
			break;
		case 2:
			cout << calculateGeometry(option, A, B);
			break;
		case 3:
			cout << calculateGeometry(option, A);
			break;
		case 4:
			cout << calculateGeometry(option, A);
			break;
		case 5:
			cout << calculateGeometry(option, A, B, C);
			break;
		case 6:
			cout << calculateGeometry(option, A, B);
			break;
		case 7:
			cout << calculateGeometry(option, A);
			break;
		case 8:
			cout << calculateGeometry(option, A);
			break;
		default:
			break;
	}
	return 0;
}
