#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Page{
    char * lines[10];
    int count;
    struct Page * PrevPage;
    struct Page * NextPage;
}Page;

void append_line(Page *sample, char* str);
void insert_line(Page * sample, int idx, char* s);
void remove_line(Page * sample, int idx);
void print(Page * page);
void putinFile(FILE * fp, Page * page);


int main(int argc, char *argv[]){
    Page * first_page = (Page *)calloc(1, sizeof(Page));
    first_page->count=0;

    append_line(first_page, "1p");
    append_line(first_page, "2p");
    append_line(first_page, "3p");

    print(first_page);

}

void append_line(Page *sample, char* str){
    int n = sample->count;
    if(n == 10){
        if(sample->NextPage!=NULL){
            append_line(sample->NextPage, str);
            return;
        }else{
            Page * newone = (Page *)calloc(1, sizeof(Page));
            newone->count = 1;
            newone->lines[0] = str;

            newone->PrevPage = sample;
            sample->NextPage = newone;

            return;
        }
    }
    sample->lines[sample->count++] = str;
}

void insert_line(Page * sample, int idx, char* s){
    int n = sample->count;
    if(idx>n){
        insert_line(sample->NextPage, idx-n, s);
        return;
    }

    if(n >= 10){
        Page * newone = (Page *)calloc(1, sizeof(Page));
        newone->lines[0] = sample->lines[9];
        newone->count = 1;

        if(sample->NextPage!=NULL){
            sample->NextPage->PrevPage = newone;
            newone->NextPage=sample->NextPage;
        }
        newone->PrevPage = sample;
        sample->NextPage = newone;
    }

    for(int i=9; i>=idx; i--){
        sample->lines[i] = sample->lines[i-1];
    }
    sample->lines[idx-1] = s;

    if(n<10)
        sample->count++;
}

void remove_line(Page * sample, int idx){
    int n = sample->count;
    if(idx>n){
        remove_line(sample->NextPage, idx-n);
        return;
    }

    if(n==0){
        printf("error\n");
        return;
    } 

    for(int i = idx-1; i<n; i++){
        sample->lines[i] = sample->lines[i+1];
    }
    sample->lines[n-1] = "";
    sample->count--;
}

void print(Page * page){
    printf("items : ");
    for(int i=0; i<page->count; i++)
        printf("%s ", page->lines[i]);
    printf("\ncount : %d \n", page->count);
    

    if(page->NextPage!=NULL){
        printf("->\n");
        print(page->NextPage);
    }else{
        printf("\n\n");
        return;
    }
}

void putinFile(FILE * fp, Page * page){

    for(int i=0; i<page->count; i++){
        fputs(page->lines[i], fp);
    }

    if(page->NextPage==NULL)
        return;
    else
        putinFile(fp, page->NextPage);
}
