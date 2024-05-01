#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct barcode {
    char code[8];
    int converted;
};

int main() {

    int n;
    scanf("%d", &n);

    struct barcode arr[n];
    int temp;

    for(int i=0; i<n; i++){
        arr[i].converted = 0;
        scanf("%s", arr[i].code);
        for(int j=6; j>=0; j--){
            if(arr[i].code[j]==49){
                arr[i].converted+=(int)pow(2,6-j);
            }
        }
    }

    scanf("%d", &temp);

    printf("%d", arr[temp-1].converted);

     
    return 0;
}

/*
7줄의 막대모양으로 숫자를 표시하는 바코드가 있다. 컴퓨터는 바코드를 인식하면 검은 줄은 1로,
흰 줄(표시가 안 된 줄)은 0으로 인식해 7bit 2진수와 같은 방식으로 10진수로 변환한다.
예를 들어 1000011은 64+2+1 = 67이다.
바코드 하나에 대한 처리를 하는 구조체를 이용해 다음에서 설명하는 프로그램을 작성하도록 한다.
구조체에는 바코드의 정보를 의미하는 7bit 2진수 문자열과 바코드를 해석한 10진수값을 멤버변수로
가지고 있어야 한다.
프로그램은 n개(1<=n<=20)의 바코드 정보를 입력받는다. 그 후에 i번째 바코드를 의미하는 정수 i
(1<=i<=n)을 입력받는다. 그러면 프로그램은 i번째 바코드의 10진수 멤버변수값을 출력한다.

Input Format

첫번째 줄에서는 입력받을 바코드의 개수를 나타내는 정수 n(1<=n<=20)을 입력 받는다.
두번째 줄부터 n개의 바코드 형식이 입력된다. 바코드 값이 입력된 후에는 몇 번째 바코드의
정보를 출력할 것인지를 의미하는 i(1<=i<=n)이 입력된다. 첫번째 바코드의 정보의 출력을 요구할 경우
1이 입력된다.

Constraints

구조체를 사용하여 문제를 풀어주세요.

Output Format

출력은 i번째 바코드의 10진수 값을 출력한다. 출력 후에는 개행처리 해준다.


Sample Input 0

2
1000011
1110100
1

Sample Output 0

67
*/