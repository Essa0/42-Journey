*This project has been created as part of the 42 curriculum by iabiesat*

## Description:
in this project we implement full program that sorts list of number using the minimum number of operation

## Instructions:
The goal is to learn more about linked-list and sort algorithms, 42 provides checker program that help us to know how many operation the program will do to sort the numbers list.

To run the program you should to do the following steps:
- Open terminal
- clone the repo:
open the 42 intra and go to the project **push_swap** to get the repo
```bash
git clone git@vogsphere.42amman.com:vogsphere/intra-uuid-957829f8-f0f2-450d-a0fd-58313d8285c6-7086426-iabiesat push_swap
cd push_swap
make
```
in this step we create the executable file ./push_swap
```bash
./push_swap 43 55 334 34 34 53 3 23
```
> **Note**: program will check the input for errors such as duplicate or invalid number and display Error message if the input is invalid, make sure your input contains just numbers
```bash
make fclean
```
> **Note**: this command will clean for all obj file and the executable 

## Resources  

How radix_sort algorithm work:
 - search for max number to know the number of digit to determine the number of digits.
 - for the number with fewer digit will treated as if they have leading zeros
 - the sort process start from the lowest significant digit to highest significant digit 
 - each of sort step, the numbers will be distributed into buckets ranging (0 - 9) based on the current digit
 - after sort by digit, will create new list by collect the number from the bucket in ascending order (0-9) 
 - repeat these steps until the list becomes sorted

 in the following recourses i provide **visualgo** that will help to understand how radix sort work

1. push_swap subject pdf
2. geeksforgeeks:
    - geeksforgeeks.org/c/structures-c/
    - geeksforgeeks.org/c/linked-list-in-c/
3. visualgo:
    - visualgo.net/en/sorting
4. youtube:
    - youtube.com/watch?v=uJvnJMX1vqI (The most helpful and clear tutorial i have ever seen before, mostly you will understand many thing about memory, pointers, linked-list....etc).
    - youtube.com/watch?v=CmHcb5xdPb0 (Radix Sort).
5. stack overflow 
    helpful to solve most of problem that i faced

in our project we will use radix sort in different way, 
the sorting divide into two parts
- **simple sort**: used for small input sizes (3-5 number) we do this part without using radix sort algorithm just focus on hardcode logic to get the minimum number of operation. 
- **big sort**: this part focused on large input size, we cant applied directly the classic radix sort because the project subject only allow to use two stack (A & B) and limited set of operation such as swap, push, rotate and reverse rotate, we make initial indexing step to overcome these obstacles, each element is assigned an index based on how many numbers are smaller than it. this step allows the algorithm to work with smaller values and fewer bits.
the different in our radix sort after indexing, the algorithm will check each bit from the least significant to the most significant,

## About using AI:
AI tool such as (chatgpt, claude and copilot) to create general roadmap on how to start and what should to learn and to organize the program, also it was helpful with bug that i faced during build the program