#include <stdio.h>
#include <math.h>

// create the function to calulate the maximum heart rate 
// if it is a male 
double male (double age){
    
    double mhr;
    
    mhr = 203.7 / (1 + exp (0.033 * (age - 104.3))); 

    return (mhr);
}

// create the function to calulate the maximum heart rate 
// if it is a female  
double female (double age){

    double mhr;

    mhr = 190.2 / (1 + exp(0.0453 * (age - 107.5))); 
    
    return (mhr);
}



//begin the main function
int main(){

//set variables accordingly 
    char gender;
    double mhrvalue;
    double userage;

//collect the age 
    printf ("input your age: ");
    scanf ("%lf", &userage);

//collect the gender 
    printf ("are you a male or female (M for male and F for female): ");
    scanf (" %c", &gender);

//create the if statements to use the appropriate function 
// for a male or female 

    if (gender == 'F' || gender == 'f'){
      
        mhrvalue = female(userage);
    }

    else 
        if (gender == 'M' || gender == 'm'){

        mhrvalue = male(userage);
    }

    
// collect the resting heart rate 
    double resting_hr;

    printf ("Input your resting heart rate: ");
    scanf ("%lf", &resting_hr);

//set the variables for the fitness level
    char fitnesslevel;
    double inten;

//collect the fitness level and use it to find which 
//if statement to use depending on the level
    printf ("Input your fitness level here (L for low, M for medium, H for high): ");
    scanf (" %c", &fitnesslevel);

    if (fitnesslevel == 'L' || fitnesslevel == 'l'){

        inten = 0.55;
    } else if (fitnesslevel == 'M' || fitnesslevel == 'm'){

        inten = 0.65;
    } else if (fitnesslevel == 'H' || fitnesslevel == 'h'){

        inten = 0.8;
    }
    
//calculate the final training heart rate 
    double trainingheartrate = round((mhrvalue - resting_hr) * inten + resting_hr);

//print the training heart rate 
    printf ("your training heart rate is %.0lf \n", trainingheartrate);

    return (0);
}

