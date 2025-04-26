// Viết chương trình cài đặt bài toán tháp Hanoi, số lần di chuyển được tính bởi công hức C(n) = 2C(n-1) + 1 hay C(n) =2^n -1 (lần).
#include <iostream>
#include <stdio.h>
char A = 'A', B = 'B', C = 'C';
int n, dem = 0;
void Move(int n, char A, char B, char C)
{

    if (n == 1)
    {
        printf("chuyen: %c sang %c\n", A, C);
        dem++;
    }

    else
    {
        Move(n - 1, A, C, B);
        Move(1, A, B, C);
        Move(n - 1, B, A, C);
    }

}
////////
////////

/////////

//////////
///////
///////
//
/
/
/
    /


    //
int main(int argc, char **argv)
{
    
    printf("n = ");
    scanf("%d", &n);
    Move(n, A, B, C);
    printf("\nSo lan chuyen: %d", dem);
    return 0;
}
