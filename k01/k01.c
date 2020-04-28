#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave)
extern double var_online()

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);


    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

double ave_online(double val,double ave);
{
    int i;
    double c;
    
    for ( i = 1; i <= 14; i++)
    {c = (i-1)/i * ave + 1 / i * val;
        /* code */
    }
    return c;
}
double var_online(double val,double ave);
{
    int i;
    double d;

    for ( i = 1; i <= 14; i++)
    {
      d = i - 1 * ave_online(val * val,ave) + 1 / i * val - ave_online(val,ave) * ave_online(val,ave);  /* code */
    }
    return d;
}


    return 0;


}

