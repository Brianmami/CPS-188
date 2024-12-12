/*
1. you should create a list variable that can store the numbers created
2. the numbers given by the user should be compared to the numbers in the list created previously
3. if the number is less than the one already there, then it is placed to the left of it
4. if the number is more than the one already there, then it is placed to the right of it
5. once the program can go through the whole list without having to compare two numbers again,
the list is complete
6. the final list variable is the output given to the user

check:
- if numbers are all the same, the  equal to function will take place 
and automatically place the number to the right since it does not matter what side it is placed on
- if the numbers are already sorted then the program will still run, however wont have to make any changes 
since they are already in order

example:
user_input_list: [23, 12, 23, 11, 13]
new_list: []

Insert 24 into sorted_list: [23]
Insert 11 into sorted_list: [12, 23]
Insert 23 into sorted_list: [12, 23, 23]
Insert 04 into sorted_list: [11, 12, 23, 23] 
Insert 13 into sorted_list: [11, 12, 13, 23, 23] 
Sorted List: [11, 12, 13, 23, 23]  */