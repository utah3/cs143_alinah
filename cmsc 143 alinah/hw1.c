#include <stdlib.h>
#include <stdio.h>
#include "hw1.h"

unsigned char coin_types(unsigned int cents){

int q = 0, d = 0, n = 0, p = 0, r = 0;
// q is num quarters and so on, r is remainder
  q = (cents / 25);
  r = (cents % 25);
  d = (r / 10);
  r = (r % 10);
  n = (r / 5);
  r = (r % 5);
  p = (r / 1);
return(q + d + n + p);
}

unsigned short weeks_in_term(unsigned short total_mins,
unsigned short max_mins_per_lecture,
unsigned char max_lectures_week){
    int w = 0;
    //this checks the max time a week and finds the number of full weeks
    w = (total_mins / (max_mins_per_lecture * max_lectures_week));
    if((total_mins % (max_mins_per_lecture * max_lectures_week)) != 0){
        return (w +1);
    }else{
        return w;
    }
    }

char month_ends_in(unsigned char month){
    switch(month){
        case 1:
        case 2:
        case 5:
        case 7:
          return 'y';
          break;
        case 3:
          return 'h';
          break;
        case 4:
          return '1';
          break;
        case 6:
          return 'e';
          break;
        case 8:
          return 't';
          break;
        case 9:
        case 10:
        case 11:
        case 12:
          return 'r';
          break;
        default:
          return '0'; /*invalid*/}
}

int define_num_seg(int n){
   switch (n)
   {
   case 0:
   case 6:
   case 9:
    return 6;
    break;
   case 1:
     return 2;
     break;
   case 2:
   case 3:
   case 5:
     return 5;
     break;
   case 4:
     return 4;
     break;
   case 7:
     return 3;
     break;
    case 8:
      return 7;
      break;
   default:
    return 0;
    break;
   }
}


int count_segments(unsigned int number){
    if(number == 0 || number > 9999999){
        return 0;
    }
      int finalnum = number % 10;
      int remainder = number / 10;

    return (define_num_seg(finalnum) + count_segments(remainder));
}

unsigned int lit_segments(unsigned int number){
    return count_segments(number);
}

int main() {
    int number;
/*testing coin function*/
  printf("%c\n", coin_types(30));
  printf("%c\n", coin_types(25));
  printf("%c\n", coin_types(100));
/*testing weeks interm*/
  printf("%hu\n", weeks_in_term(950, 30, 2));
  printf("%hu\n", weeks_in_term(41, 40, 1));
/*months test*/
  printf("%c\n", month_ends_in(1));
  printf("%c\n", month_ends_in(5));
/*count segments*/
  printf("%u\n", lit_segments(1234));
  printf("%u\n", lit_segments(0));
}