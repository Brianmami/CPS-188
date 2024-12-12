#include <stdio.h>
#include <string.h>

typedef struct{ 
    int comp1;
    int comp2;
    int comp3;
    int comp4;
    char name[15];
} add_t;

int lonet (add_t a1, add_t a2){  
    if (a1.comp1 == a2.comp1){
        return 1;
    } else {
        return 0;
    }
}

int main (){

    int numadd = 0;
    add_t storeadd [300];
    int comp1, comp2, comp3, comp4;
    char name[15];

    FILE *myfile = fopen ("L8_ip.txt", "r");

    for (int i = 0; i < 300; i++){
        fscanf (myfile, "%d.%d.%d.%d %s", &comp1, &comp2, &comp3, &comp4, name);
    
        if (comp1 != comp2 != comp3 != comp4 != 0 && strcmp(name, "sentinel") != 0){
            storeadd[i].comp1 = comp1;
            storeadd[i].comp2 = comp2; 
            storeadd[i].comp3 = comp3;
            storeadd[i].comp4 = comp4;
            strcpy (storeadd[i].name, name);

        numadd ++;
    } else {
        break;
         }
    }
    fclose (myfile);

    printf ("the addresses that are on the same network: \n ");
    for (int i = 0; i < numadd; i++){
        for (int j = i + 1; j< numadd; j++){
            int checkadd = lonet(storeadd[i], storeadd[j]); 

            if (checkadd == 1){
                printf ("the servers %s and %s from the file are on the same local network\n", storeadd[i].name, storeadd[j].name);
            }
        }
    }
    printf("\nthe servers from the the file printed below: \n");
    for (int i = 0; i < numadd; i++){
        printf ("%s: %d.%d.%d.%d \n", storeadd[i].name, storeadd[i].comp1, storeadd[i].comp2, storeadd[i].comp3, storeadd[i].comp4);
    }
}

