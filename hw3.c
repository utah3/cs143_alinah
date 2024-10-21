#include <stdlib.h>
#include <stdio.h>
#include "hw3.c"


/*helper for checking ofty*/
int chackofty(unsigned int a){	
  int is4 = 0;
  int is1 = 0;
  int is3 = 0;
  int dig = 0;
  
  while(a > 0){
     dig = a % 10;
     a /= 10;
     if(dig == 1){
       is1  = 1;}
     else if(dig == 4){
       is4 = 1;}
     else if(dig == 3){
       is3 = 1;}}
     return (is4 && is3 && is1);}
		      


int all_ofty(unsigned int a[], unsigned int alen){
  int b = 0;
  if (a == NULL || alen == 0) {
        return 0;}
  for (int i = 0; i < alen; i++){
    if(!checkofty(a[i])){
	return 0;}}
    return 1;}

int exists_ofty(unsigned int a[], unsigned int alen){
  if (a == NULL || alen == 0) {
        return 0;}  
  for (int i = 0; i < alen; i++){
      if(checkofty(a[i])){
	return 1;}}
      return 0;}

int first_ofty(unsigned int a[], unsigned int alen){
  int val = -1;
  if (a == NULL || alen == 0) {
        return -1;}
  for (int i = 0; i < alen; i++){
    if(checkofty(a[i])){
      val = i;
      break;}}
      return val;}

unsigned int number_ofty(unsigned int a[], unsigned int alen){
  int count = 0;
  for (int i = 0; i < alen; i++){
    if(checkofty(a[i])){
      count ++;}}
    return count;}

void progress(unsigned int a[], unsigned int alen){
  if(a == NULL || alen == 0){
    return;}
  for (int i = 0; i < alen; i++){
    if(a[i] == 141 || a[i] == 142 || a[i] == 143){
			a[i] = a[i] + 1;
    }else{
      a[i] = 0;}}}


unsigned int* running_ofty(unsigned int a[], unsigned int alen){
  int count = 0;
  unsigned int *final = (unsigned int*)malloc(alen * sizeof(unsigned int));
    if (final == NULL){
      return NULL;}	}
    for (int i = 0; i < alen; i++){
      if(checkofty(a[i])){
	count ++;}
	final[i] = count;}
    return final;}

void rotate_right(int a[], unsigned int alen){
  if(a == NULL || alen == 0){
    printf("error input is null.\n");
    return;}
  for (int i = 0; i < alen; i++){
    if(i == (alen - 1)){
      a[i] = a[0];}
	else{
	  a[i] = a[i - 1];}}}

int* trim_adj_dupes(int* a, unsigned int alen, unsigned int* reslen){
  int current_val;
  int j = 0;
  if(a == NULL || alen == 0){
    return NULL;
  *reslen = 0;}
  int *final = (int*)malloc(alen * sizeof(int));
  if (final == NULL){
        return NULL;
  *reslen = 0;}
  for (int i = 0; i < alen; i++){
	  if (i == 0){
	    final[j] = a[i];
	  j++;}
	  if(a[i] == a[i - 1]){
		 continue;
	  }else{
		final[j] = a[i];
		j++;}}
  *reslen = j;
  return final;}
/*
 nt* slicer(int* source, unsigned int sourcelen, unsigned int* indices,
            unsigned int indiceslen, unsigned int* reslen)
