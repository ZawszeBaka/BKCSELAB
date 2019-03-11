/*
Viết hàm tính toán giữa năm số nguyên a, b, c, d và e.



Các option dùng để trả về kết quả:


1 : phần tử có giá trị nhỏ nhất


2 : phần tử có giá trị lớn nhất


3 : phần tử nằm chính giữa nếu các số được sắp theo thứ tự tăng dần


4 : phần tử gần giá trị K nhất (K được nhập vào)


5 : phần tử xa giá trị K nhất (K được nhập vào)




Input: gồm 3 thông số:


1-5 : năm số nguyên a đến e


6 : mô tả option như nêu trên


7: giá K nếu chọn option là 4 hoặc 5


*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

int getElement(int a, int b, int c, int d, int e,
               int option, int K = 0) {
    int sz=5;
    int arr[5]={a,b,c,d,e};
    int sorted_arr[5];
    int mask[5];
    for(int i=0; i<sz; i++){
      mask[i]=0;
    }

    int min=arr[0];
    int indMin=0;
    for(int iter=0; iter<sz; iter++){
      for(int i=0; i<sz; i++){
          if(mask[i]==0){
            min=arr[i];
            indMin=i;
            break;
          }
      }
      for(int i=0; i<sz; i++){
        // find min
        if(arr[i]<min && mask[i]==0){
          min = arr[i];
          indMin=i;
        }
      }
      mask[indMin]=1;
      sorted_arr[iter]=min;
    }

    // print for test
    printf("\n[INFO] Sorted Array: ");
    for(int i=0; i<sz; i++){
        printf(" %d ", sorted_arr[i]);
    }
    int ind;
    int nearest_val, furthest_val;

    switch(option){
      case 1: return sorted_arr[0];
      case 2: return sorted_arr[4];
      case 3: return sorted_arr[2];
      case 4:
        nearest_val=abs(arr[0]-K);
        ind=0;
        for(int i=0; i<sz; i++){
            if(abs(arr[i]-K)<nearest_val){
                nearest_val = abs(arr[i]-K);
                ind=i;
            }
        }
        return arr[ind];
      case 5:
        furthest_val=abs(arr[0]-K);
        ind=0;
        for(int i=0; i<sz; i++){
            if(abs(arr[i]-K)>furthest_val){
                furthest_val = abs(arr[i]-K);
                ind=i;
            }
        }
        return arr[ind];
      default: return -1;
    }
}
int main(int narg, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1], ifstream::in);

	int a, b, c, d, e;
	int option;
	int K;
	string line;

	for (int count = 0; ifs.good() && count < 7; count++) {
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
				c = stoi(line);
				break;
			case 3:
				d = stoi(line);
				break;
			case 4:
				e = stoi(line);
				break;
			case 5:
				option = stoi(line);
				break;
			case 6:
				K = stoi(line);
				break;
			default:
				break;
		}
	}
	ifs.close();

	cout << getElement(a, b, c, d, e, option, K);

	return 0;
}
