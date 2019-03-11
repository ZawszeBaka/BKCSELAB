#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

void printHelloWorld(int option) {
  switch (option) {
    case 1: printf("hello world");break;
    case 3: printf("HELLO WORLD");break;
    case 2: printf("Hello World");break;
    default: break;
  }
}

int main(int narg, char **argv)
{
ifstream ifs;
ifs.open(argv[1], ifstream::in);

int option;
string line;

for (int count = 0; ifs.good() && count < 2; count++) {
  getline(ifs, line);
  switch (count)
  {
    case 0:
      option = stoi(line);
    default:
      break;
  }
}
  printHelloWorld (option);

ifs.close();
return 0;
}
