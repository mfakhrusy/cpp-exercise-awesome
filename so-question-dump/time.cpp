#include <iostream>
#include <time.h>
using namespace std;

void square(int x){
int z;
z = x + x;
}

void add(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10,int a11,int a12,int a13,int a14,int a15,int a16,int a17,int a18,int a19,int a20){
    int z;
    z = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + 
    a14 + a15 + a16 + a17 + a18 + a19 + a20;
}

int main (){
clock_t t1;
t1=clock();

for(int i=0; i <100;i++){
    square(2);
    t1=clock()-t1;
    cout<<"time taken by fucntion with single parameter:"<<(double)t1/CLOCKS_PER_SEC<<"seconds"<<endl;
}
for(int i=0;i <100;i++){
    add(2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2);
    t1=clock()-t1;
    cout<<"time taken by fucntion with 20 parameter:"<<(double)t1/CLOCKS_PER_SEC<<"seconds"<<endl;
}

return 0;
}

