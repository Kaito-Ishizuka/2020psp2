#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ave_A 170.8
#define ave_B 169.7
#define var_A 5.43
#define var_B 5.5

extern double p_stdnorm(double z);

int main(void)
{
    double val,z_A,z_B;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L_A=1,L_B=1;

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
        z_A = (val - ave_A) / var_A;
        z_B = (val - ave_B) / var_B;
        L_A *= p_stdnorm(z_A);
        L_B *= p_stdnorm(z_B); 
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Likelihood for A: %f\n",L_A);
    printf("Likelihood for B: %f\n",L_B);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

