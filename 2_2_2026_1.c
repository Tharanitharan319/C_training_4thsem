#include <stdio.h>
#define size 5
int array[size];
int top = -1;
//push
void push(int value){
    if (top==size-1){
        printf("edam illa poda!\n");
    }else{
        top++;
        array[top]=value;
        printf("%d array ku busssy aayiduchu\n",value);
    }
}
int main() {
   push(1);push(3);push(5);push(7);push(62);
push(30);
    return 0;
}