#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char tempstr[80];
    FILE *fp = fopen("page.txt", "r");
    if(fp==NULL)
        printf("itsnull\n");
        
    fgets(tempstr, 80, fp);
    fgets(tempstr, 80, fp);
    fgets(tempstr, 80, fp);
    fgets(tempstr, 80, fp);

    printf("%s %d", tempstr, strlen(tempstr));

    fclose(fp);

    return 0;
}