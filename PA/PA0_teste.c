#include <stdio.h>

int main() {
    char filename[100] = "./testes.txt";
    char mode[2] = "r";
    FILE *fp;
    fp = fopen(filename, mode);
	int i = 0;
    int x = 0;
    int num = 0;
    while(!feof(fp)) { 
        fscanf(fp,"%d",&num);
	if(!EOF){
        x+=num;
	}
	i++;
	printf("%d\n", i);
    }
    printf("X = %d\n", x);
    fclose(fp);
    


return 0;
}
