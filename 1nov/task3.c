# include <stdio.h>

int main(){
    float CSC201;
    float CSC205;
    float STA205;
    float total;
    float average;
    float percentage;

    printf ("Enter score for CSC 201: ");
    scanf("%f", &CSC201);
    printf ("Enter score for CSC 205: ");
    scanf("%f", &CSC205);
    printf ("Enter score for STA 205: ");
    scanf("%f", &STA205);

    total = CSC201 + CSC205 + STA205;
    average = total/3;
    percentage = (total/300)*100;

    printf("\n Total : %.2f ", total);
    printf("\n Average: %.2f", average);
    printf("\n Percentage: %.2f", percentage);

    return 0;
}    