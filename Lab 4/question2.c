#include <stdio.h>

int main(){
    FILE *data;
    data = fopen ("L4_data.txt", "r"); //open text file

    int employee_number, shifts; 
    float wage;

    printf("Employee ID   Total Hours    Total Pay \n");
    printf("___________   ___________   ___________\n");
   
    while (!feof(data))//while it is not at the end of file 
    {   
        int sum_hours = 0;
        float gross_pay = 0;

        fscanf (data, "%d %d %f", &employee_number, &shifts, &wage); //collecting first three information
        printf ("%-5d\t\t", employee_number);

        for (int a = 0; a < shifts; ++a) //collecting hours worked
        {
            int individual_hours;
            fscanf(data, "%d", &individual_hours); 
            sum_hours += individual_hours; //adding each hour digit to the previous and putting it in one variable
        }

        printf("%-10.d", sum_hours);

        
        if (sum_hours <= 15)
            gross_pay = sum_hours * wage;
        else if (sum_hours <= 25)
            gross_pay = sum_hours * wage * 1.05;
        else 
            gross_pay = sum_hours * wage * 1.10;

        printf ("%.2lf\n", gross_pay);
    }
    
    fclose (data);
    return(0);
}