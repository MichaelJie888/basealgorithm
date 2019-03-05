#include <string.h>
#include <vector>
using namespace std;
const int maxn=2000;
int ug[maxn],c[maxn];

int add(int num1,int num2){
    int sum,carry;
    do{
        sum=num1^num2;
        carry=(num1&num2)<<1;
        num1=sum;
        num2=carry;
    }while(num2!=0);

    return num1;
}

int main(){
    printf("%d",add(27,27));
    return 0;

}