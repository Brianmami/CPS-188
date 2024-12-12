#define MAX 10 

double diag (double numbers[MAX][MAX]){
    double sum = 0;
    int j = 0;

    for (int i = 0; i < MAX; i++){
        j = i; 
        sum += numbers [i][j];
    }
    return sum;
}

double all (double numbers [MAX][MAX]){
    double sum = 0;

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            sum += numbers [i][j];
        }
    }
    return sum;
}

double right (double numbers [MAX][MAX]){
    double avg = 0;
    for (int i = 0; i < MAX; i++){
        avg += numbers[i][MAX - 1];
    }
    avg /= MAX;
    return avg;
}

double corners(double numbers [MAX][MAX]){
    double sum;

    sum = numbers[0][0] + numbers[0][MAX-1] + numbers [MAX - 1][0] + numbers [MAX - 1][MAX - 1];
    return sum;
}

double lanti (double numbers [MAX][MAX]){
    double largest = 0;
    int col = MAX - 1;

    for (int row = 0; row < MAX; row++){
        if (numbers[row][col] > largest){
            largest = numbers[row][col];
        }
        col--;
    }
    return largest;
}