

#include <iostream>
#include<windows.h>
#include <cmath>
#include <stdlib.h >//?
using namespace std;
#define PI 3.1415926 //?
#define K ((2*PI)/360) //?
#define N 25//?
void main() //?
{
system("color BD");
cout <<endl <<endl <<endl;
int x,y,i;
for(x=0;x<=405;x=x+8)
{
y=float(N*sin(x*K-N))+N;
for(i=0;i<y;i++)
cout <<" ";
cout <<"* " <<endl;
Sleep(1000);
}
}
