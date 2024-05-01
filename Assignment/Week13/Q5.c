#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct dict
{
    char key[11];
    char value[11];
} Dict;


int main() {

    int n;
    int check=0;
    char temp[12] = {0};

    Dict dictionary[21];

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", dictionary[i].key);
        scanf("%s", dictionary[i].value);
    }


    while(1){
        scanf("%s", temp);

        if(strcmp(temp, "exit")==0)
            break;

        for(int i=0; i<n; i++){
            if(strcmp(dictionary[i].key, temp)==0){
                printf("%s\n", dictionary[i].value);
                check=1;
                break;
            }
        }
        
        if(check==0)
            printf("No match key in dictionary\n");
        else
            check=0;
    }
     
    return 0;
}

/*
딕셔너리(dictionary)는 key와 value로 자료를 저장하는 자료구조입니다. 리스트와 달리 인덱스 대신 사용자가 설정한 key를 입력 받고, 이에 맞는 value 값을 반환합니다.

ex) {"id" : "202300000", "name" : "홍길동", "age" : "20"}

위 예시에서 key = "name"일 때, value는 "홍길동"이 됩니다. "name" 을 입력받으면 "홍길동"을 반환하고, "age"를 입력받으면 "20"을 반환합니다.
구조체 배열을 이용해 딕셔너리 자료구조를 구현하세요.

typedef struct dict
{
    char* key;
    char* value;
} dict;

dict dictionary[10];
1부터 20 사이의 정수로 딕셔너리 크기를 입력 받습니다. 딕셔너리 크기에 맞는 key, value를 입력받습니다. 딕셔너리 입력은 key와 value를 번갈아가며 입력받으며 각각의 key, value는 줄바꿈으로 구분됩니다.

딕셔너리 입력이 끝나면 key를 입력 받습니다. key가 한번 입력될 때 마다 그에 맞는 value를 출력합니다. key가 딕셔너리에 존재하지 않는다면, "No match key in dictionary" 문구를 출력합니다. key 값으로 exit를 입력받을 때 까지 key 입력과 value 출력을 반복하고, exit가 입력되면 프로그램을 종료합니다.

Input Format

1부터 20 사이의 정수로 딕셔너리 크기를 입력 받습니다. 딕셔너리 크기에 맞는 key, value를 입력받습니다. 딕셔너리 입력은 key와 value를 번갈아가며 입력받으며 각각의 key, value는 줄바꿈으로 구분됩니다.

딕셔너리 입력이 끝나면 value 출력을 원하는 key 값을 입력받습니다. key 값으로 exit를 입력받을 때 까지 key 입력과 value 출력을 반복합니다.

Constraints

입력에 띄어쓰기는 없습니다. 각 문자열의 길이는 최대 10자입니다. 각 입력, 출력은 줄바꿈으로 구분됩니다.

Output Format

입력받은 key에 따라 딕셔너리에 존재하는 value 값을 출력합니다. key가 딕셔너리에 존재하지 않는다면 "No match key in dictionary" 문구를 출력합니다.


Sample Input 0

3
id
202300000
name
gildong
age
20
age
id
name
height
exit

Sample Output 0

20
202300000
gildong
No match key in dictionary
*/