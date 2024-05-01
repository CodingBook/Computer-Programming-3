#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct student {
    char name[32];
    char address[32];
};

int main() {

    struct student arr[10];
    char exname[32] = {0};

    for(int i=0; i<10; i++){
        scanf("%s", arr[i].name);
        scanf("%s", arr[i].address);
    }

    scanf("%s", exname);

    for(int i=0; i<10; i++){
        if(strcmp(exname, arr[i].name)==0){
            printf("%s", arr[i].address);
            break;
        }
    }


    return 0;
}

/*
구조체를 이용해 학생의 이름과 사는 곳을 하나의 구조에 저장하고, 학생의 이름을 입력하면 해당 학생이 사는 지역을 출력하라.

Input Format

10명의 학생과 사는 지역명이 문자열로 입력된다. 문자열의 길이는 최대 30자이다.

학생1이름
학생1지역
학생2이름
학생2지역
...
학생n이름
학생n지역
과 같이 입력된다.
입력되는 학생들의 이름은 중복되는 것이 없다.
데이터가 모두 입력되면 데이터로 나온 학생의 이름 중 하나가 입력된다.

Output Format

출력은 입력된 학생이 사는 지역을 출력한다.


Sample Input 0

Edison
Geumam1-dong
Edward
Geuman1-dong
Elick
Seosin-dong
Alponso
Seosin-dong
Jeongum
Hyoja-dong
Soonjae
Joongang-dong
Haeri
Joongang-dong
Jaok
Hyoja-dong
JewerlyJeong
Joongang-dong
Saekyeong
Joongang-dong
Soonjae

Sample Output 0

Joongang-dong
*/