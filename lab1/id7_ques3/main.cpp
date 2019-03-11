/*
Viết chương trình hỗ trợ và xuất ra kết quả các phép tính toán kết hợp giữa hai số nguyên a và b.


Các option dùng để trả về kết quả:


1 : (a + b)


2 : (a - b)


3 : (a * b)


4 : (a / b)


5 : a^2 + b^2


Trong trường hợp phép chia (option 4), nếu b bằng 0 thì xuất ra theo định dạng "Do not divide <number_a> by zero!".


Ví dụ: a = 6, b = 0 thì xuất ra: "Do not divide 6 by zero!".


Input: gồm 3 thông số:


1-2 : hai số nguyên a và b


3 : mô tả option như nêu trên
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

void calculateAndPrintResult(int a, int b, int option) {
    // printf("\n[DEBUG] a = %d, b = %d, option = %d , Result = ", a,b,option);
    switch(option){
        case 1: printf("%d",(a+b));break;
        case 2: printf("%d",(a-b));break;
        case 3: printf("%d",(a*b));break;
        case 4:
          if(b==0){
              printf("Do not divide %d by zero!",b);
          }else{
              printf("%d",a/b);
          }
          break;
        case 5: printf("%d",a*a+b*b);break;
        default: break;
    }
}

int main(int narg, char **argv)
{
    ifstream ifs;
    ifs.open(argv[1], ifstream::in);

    int a;
    int b;
    int option;
    string line;

    while(ifs.good()){
      for (int count = 0; ifs.good() && count < 3; count++) {
        getline(ifs, line);
        switch (count)
        {
          case 0:
            a = stoi(line);
            break;
          case 1:
            b = stoi(line);
            break;
          case 2:
            option = stoi(line);
            break;
          default:
            break;
        }
      }
      calculateAndPrintResult(a, b, option);
    }

    ifs.close();

    return 0;
}
