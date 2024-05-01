#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Page{
    char * lines[10];
    int count;
    struct Page * PrevPage;
    struct Page * NextPage;
}Page;

void append_line_5each(Page *sample, char* str);
void append_line(Page *sample, char* str);
void insert_line(Page * sample, int idx, char* s);
void remove_line(Page * sample, int idx);
void print(Page * page);
void putinFile(FILE * fp, Page * page);


int main(int argc, char *argv[]){

    Page * first_page = (Page *)calloc(1, sizeof(Page));
    first_page->count=0;

    //기존 파일 읽는 단계
    char tempstr[80];
    FILE *fp = fopen(argv[2], "r");

    while(1){
        char * it = fgets(tempstr, 80, fp);

        if(it==NULL)
            break;
        else{
            char * temp = (char * )calloc(80, sizeof(char));
            strcpy(temp, tempstr);
            if(temp[strlen(temp)-1]=='\n')
                temp[strlen(temp)-1] = '\0';
            append_line_5each(first_page, temp); //이 부분을 append_line으로 바꾸면 가산점 항목을 구현 안했을때 기준으로 프로그램 작동
        }
    }

    fclose(fp);


    //명령어 수행 단계
    fp = fopen(argv[2], "w");
    
    if(strcmp(argv[3], "-a")==0){//append
        //argv에서 인자를 얻어 append 함수를 실행하는 코드를 작성하세요.
        append_line(first_page, argv[4]);
    }

    if(strcmp(argv[3], "-i")==0){//insert
        //argv에서 인자를 얻어 insert 함수를 실행하는 코드를 작성하세요.
        insert_line(first_page, atoi(argv[4]), argv[5]);
    }

    if(strcmp(argv[3], "-r")==0){//remove
        //argv에서 인자를 얻어 remove 함수를 실행하는 코드를 작성하세요.
        remove_line(first_page, atoi(argv[4]));
    }


    //수행 후, 기존파일에 덮어 쓰는 단계
    print(first_page);
    putinFile(fp, first_page);
    fclose(fp);

    return 0;
}

void append_line_5each(Page *sample, char* str){
    //append_line과 비슷, 페이지에 5개가 찼을때 새 페이지 생성
    int n = sample->count;
    if(sample->NextPage!=NULL){ 
        append_line_5each(sample->NextPage, str);
        return;
    }

    if(n == 5){ //5일때 다음페이지 생성          
        Page * newone = (Page *)calloc(1, sizeof(Page));
        newone->count = 1;
        newone->lines[0] = str; 

        newone->PrevPage = sample;  
        sample->NextPage = newone;  

        return;
    }
    sample->lines[sample->count++] = str;
}

void append_line(Page *sample, char* str){
    int n = sample->count;

    //다음페이지가 있는 경우, 그 페이지에 append
    if(sample->NextPage!=NULL){ 
        append_line(sample->NextPage, str);
        return;
    }

    //다음페이지가 없는 경우
    if(n == 10){ //현재 페이지가 꽉 차 있을때 새 페이지 생성            
        Page * newone = (Page *)calloc(1, sizeof(Page));
        //새로운페이지에 str 넣기, 새 페이지 count = 1;
        newone->count = 1;
        newone->lines[0] = str; 

        //새로운페이지와 기존페이지 연결(이중연결리스트 구조)
        newone->PrevPage = sample;  
        sample->NextPage = newone;  

        return;
    }
    sample->lines[sample->count++] = str; //현재페이지에 빈자리가 있는경우 삽입, count 증가
}

void insert_line(Page * sample, int idx, char* str){
    int n = sample->count;

    //페이지 삽입이 가능한지 판단하는 부분, 현재 페이지 카운트와 입력받은 인덱스 비교
    //다음페이지가 있을 경우, 인덱스에서 현재 count를 빼고 그 페이지에 insert 재귀실행
    //다음페이지가 없을 경우, invalid input
    if(idx>n || idx<1){
        if(sample->NextPage==NULL) 
            printf("\ninvalid input!!!\n\n");
        else
            insert_line(sample->NextPage, idx-n, str);
        return;
    }
    

    //페이지 삽입 부분
    if(n == 10){ //현재페이지가 꽉차있을때, 
        //새페이지 생성 및 현재페이지에 마지막 줄 넘기기
        Page * newone = (Page *)calloc(1, sizeof(Page));
        newone->lines[0] = sample->lines[9];
        newone->count = 1;

        //새페이지에 원래페이지의 다음페이지 연결(이중연결리스트)
        if(sample->NextPage!=NULL){ 
            sample->NextPage->PrevPage = newone;
            newone->NextPage=sample->NextPage;
        }

        //현재페이지에 새페이지 연결
        newone->PrevPage = sample;
        sample->NextPage = newone;
    }

    //한줄씩 넘기기 및 인덱스에 입력받은 문자열 넣기, 페이지가 넘어가는 경우는 위에서 검토완료
    for(int i=9; i>=idx; i--){
        sample->lines[i] = sample->lines[i-1];
    }
    sample->lines[idx-1] = str;

    //count증가, 혹시나 count가 11이 되지 않도록 예외처리
    if(n<10)
        sample->count++;
}

void remove_line(Page * sample, int idx){
    int n = sample->count;

    //현재페이지에서 삭제가 가능한지 판단하는 부분, 현재 페이지 카운트와 입력받은 인덱스 비교
    //다음페이지가 있을 경우, 인덱스에서 현재 count를 빼고 그 페이지에 remove 재귀실행
    //다음페이지가 없을 경우, invalid input
    if(idx>n || idx<1){
        if(sample->NextPage==NULL) 
            printf("\ninvalid input!!!\n\n");
        else
            remove_line(sample->NextPage, idx-n);
        return;
    }

    //삭제 진행 부분
    for(int i = idx-1; i<n; i++){
        sample->lines[i] = sample->lines[i+1];
    }
    sample->lines[n-1] = "";
    sample->count--;
}

void print(Page * page){
    printf("items { ");
    for(int i=0; i<page->count; i++)
        printf("\n\t%s", page->lines[i]);
    printf("\n} count : %d \n", page->count);
    

    if(page->NextPage!=NULL){
        printf("----->\n");
        print(page->NextPage);
    }else{
        printf("\n\n");
        return;
    }
}

void putinFile(FILE * fp, Page * page){
    char temp[80] = {0};

    for(int i=0; i<page->count; i++){
        char * temp = (char * )calloc(80, sizeof(char));
        strcpy(temp, page->lines[i]);

        if(temp[strlen(temp)]=='\0' ){
            if(i==page->count-1 && page->NextPage==NULL){
                fputs(temp, fp);
                return;
            }
            temp[strlen(temp)] = '\n';
        }

        fputs(temp, fp);
    }

    putinFile(fp, page->NextPage);
}
