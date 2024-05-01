#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct op{
	char oper;
	int  appearance;
};

int main() {

    int n;

    scanf("%d", &n);

    struct op arr[n];

    for(int i=0; i<n ; i++){
        scanf("%c ", &arr[i].oper);
        if(arr[i].oper==42)      // *
            arr[i].appearance=1;
        else if(arr[i].oper==47) // /
            arr[i].appearance=2;
        else if(arr[i].oper==43) // + 
            arr[i].appearance=3;
        else                     // - 
            arr[i].appearance=4;
    }
    
    
    for(int l = 4; l>0; l--){
        for(int j=0; j<n; j++){
            if(arr[j].appearance==l)
                printf("%c ", arr[j].oper);
        }
    }
     
    return 0;
}

/*
n개의 사칙연산자 문자를 입력받아 연산자 우선순위가 높은 순서부터 출력하는 프로그램을 작성하세요. 이 문제에서는, 문자들의 우선순위가 높은 순서대로 * / + - 라고 규정합니다.

문제를 풀 때에는 연산자의 종류와 연산자의 출연횟수를 하나의 구조체로 작성하여 이용하도록 합니다.

구조체 설계 뼈대

struct op{
	char oper;
	int  appearance;
}
Input Format

입력 첫 줄에는 정수 n(1<=n<=10)이 입력되고 그 다음 줄에는 n개의 산술연산자 문자(*, /, +, -)가 입력됩니다. 각 문자들은 한 개의 스페이스로 구분되어 있습니다.

Constraints

구조체를 꼭 사용하세요.

Output Format

입력된 산술연산자들을 위에서 설명한 우선순위가 높은 순서부터 차례대로 출력하세요. 각 연산자 문자들은 한 개의 스페이스로 구분되어야 하며, 맨 마지막 문자 뒤에는 스페이스 문자 대신 개행문자를 출력해야 합니다.


Sample Input 0

5
+ - / * +

Sample Output 0

* / + + -
*/