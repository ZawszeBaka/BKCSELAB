/*

Viết chương trình hỗ trợ tính toán hình học.

Cho 3 cạnh của một tam giác có chiều dài lần lượt là A, B và C.

Hãy kiểm tra xem tam giác này có phải là tam giác cân (trả về 1), tam giác vuông (trả về 2), tam giác vuông cân (trả về 3), hay là tam giác đều (trả về 4).

Ngược lại, trả về 0.

Input: gồm 3 thông số:

1 : mô tả các thông số A, B, C cần thiết

*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

#define EPSILON 1e-6

int checkTriangle(double a, double b, double c) {

  bool isRightTriangle=false; // a triangle in which one angle is a right angle (that is, a 90-degree angle)
  bool isIsoscelesTriangle=false; // a triangle that has exactly 2 sides of equal length

  if(a==b && b==c){
      return 4;
  }

  if(a==b || b==c || a==c)  isIsoscelesTriangle=true;
  if((a*a+b*b)==(c*c) || (a*a+c*c)==(b*b) || (b*b+c*c)==(a*a)) isRightTriangle=true;
  if(isIsoscelesTriangle && isRightTriangle) return 3;
  else if(isIsoscelesTriangle) return 1;
  else if(isRightTriangle) return 2;

  return 0;
}

int main(int narg, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1], ifstream::in);

	double a, b, c;
	string line;

	for (int count = 0; ifs.good() && count < 3; count++) {
		getline(ifs, line);
		switch (count)
		{
			case 0:
				a = stod(line);
				break;
			case 1:
				b = stod(line);
				break;
			case 2:
				c = stod(line);
				break;
			default:
				break;
		}
	}
	ifs.close();

	cout << checkTriangle(a, b, c);

	return 0;
}
