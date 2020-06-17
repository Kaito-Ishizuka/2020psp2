#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int n);
extern double var_online(double val,double ave,double ave_square,int n);
int main(void)
{
    double ave;
    double n;
    double u;
    double var;
    double ave_square;
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE * fp;

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
sscanf(buf, "%lf",&val);
var = var_online(val,ave,ave_square,n);
ave = ave_online(val,ave,n);
ave_square = ave_online(val*val,ave_square,n);
n++;
}

u = var * (n-1) / (n-2);

printf("sample mean:%.21fln",ave);
printf("sample variance:%.21fln" ,var);
printf("population mean (estimated):%.21f/n",ave);
printf("population variance (estimated):%.21f/n",u);

if(fclose(fp) == EOF)
{
fputs("file close error/n",stderr);
exit(EXIT_FAILURE);
}

return 0;
}

double ave_online(double val,double ave,int n)
{
double f;
f = ave * (n - 1) /n + val / n;
return f;
}
double var_online(double val,double ave,double ave_square,int n)
{
double g;
g = ave_square * (n - 1) /n + val * val / n - ave_online(val,ave,n) * ave_online(val,ave,n);
return g;
}
