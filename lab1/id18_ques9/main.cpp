/*
Viết chương trình hỗ trợ tính thuế thu nhập cá nhân.



Input: gồm các thông số sau:


1 : tổng thu nhập chịu thuế (TNCT)


2 : số người phụ thuộc



Cách tính:


1/ Thu nhập tính thuế (TNTT): Thu nhập tính thuế = Thu nhập chịu thuế - Các khoản được giảm trừ


2/ Các khoản giảm trừ:


Để giảm rắc rối trong cách tính thực tế, ta chỉ cần quan tâm giảm trừ gia cảnh như sau:


- Đối với người nộp thuế là 9 triệu đồng/ tháng.


- Đối với mỗi người phụ thuộc là 3,6 triệu đồng/ tháng.


3/ Tra theo bảng này:


Bậc     TNTT/ tháng                 Thuế suất


1       Đến 5 triệu đồng (trđ)          5%


2       Trên 5 trđ đến 10 trđ           10%


3       Trên 10 trđ đến 18 trđ          15%


4       Trên 18 trđ đến 32 trđ          20%


5       Trên 32 trđ đến 52 trđ          25%


6       Trên 52 trđ đến 80 trđ          30%


7       Trên 80 trđ                     35%



Ví dụ:


Một người có thu nhập chịu thuế TNCT = 25.920.000 đồng, số người phụ thuộc là 1, được tính như sau:


    TNTT = 20.920.000 - (9.000.000 + 3.600.000) = 13.320.000 đồng, phát sinh ở bậc 3.


- Thuế phải nộp ở bậc 1: 5.000.000 x 5% = 250.000 đồng.


- Thuế phải nộp ở bậc 2: (10.000.000 - 5.000.000) * 10% = 500.000 đồng.


- Thuế phải nộp ở bậc 3: (13.320.000 - 10.000.000) * 15% = 498.000 đồng.



Như vậy, tổng số thuế phải nộp hằng tháng là: 250.000 + 500.000 + 498.000 = 1.248.000 đồng.


Lưu ý: Thu nhập tính thuế mang giá trị nhỏ hơn bằng 0, người đóng thuế sẽ không phải chịu trách nhiệm đống thuế.


*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

int calculateFax(int taxableIncomes, int numberOfDependants) {
    taxableIncomes = taxableIncomes - (9000000+3600000*numberOfDependants);
    printf("\n[DEBUG] taxableIncomes = %d\n", taxableIncomes);

    if(taxableIncomes<=0) return 0;

    int lv_pt[7]={0, 5000000, 10000000, 18000000, 32000000, 52000000, 80000000};
    double t=5.0/100.0;
    int lv[6];
    for(int i=0; i<6; i++){
        lv[i] = ((double)lv_pt[i+1]-(double)lv_pt[i])*t*((double)i+1);
    }

    printf("[INFO] lv = ");
    for(int i=0; i<6; i++){
        printf(" %d ",lv[i]);
    }

    int myLv;
    if(taxableIncomes>0 && taxableIncomes<=5000000) myLv=0;
    else if(taxableIncomes>5000000 && taxableIncomes<= 10000000) myLv=1;
    else if(taxableIncomes>10000000 && taxableIncomes<= 18000000) myLv=2;
    else if(taxableIncomes>18000000 && taxableIncomes<= 32000000) myLv=3;
    else if(taxableIncomes>32000000 && taxableIncomes<= 52000000) myLv=4;
    else if(taxableIncomes>52000000 && taxableIncomes<= 80000000) myLv=5;
    else if(taxableIncomes>80000000) myLv=6;

    int sum=0;
    for(int i=0; i<myLv; i++){
        sum += lv[i];
    }
    sum+= ((taxableIncomes-lv_pt[myLv])*t*(myLv+1));

    printf("\n%d\n", sum);

    if(sum <= 0) return 0;
    else return sum;

}

int main(int narg, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1], ifstream::in);

	int taxableIncomes;
	int numberOfDependants;
	string line;

	for (int count = 0; ifs.good() && count < 2; count++) {
		getline(ifs, line);
		switch (count)
		{
			case 0:
				taxableIncomes = stoi(line);
				break;
			case 1:
				numberOfDependants = stoi(line);
				break;
			default:
				break;
		}
	}
	ifs.close();

	cout << calculateFax(taxableIncomes, numberOfDependants);

	return 0;
}
