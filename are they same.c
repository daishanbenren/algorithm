#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//question:
/*Given two arrays a and b write a function comp(a, b) (compSame(a, b) in Clojure)
that checks whether the two arrays have the "same" elements, with the same
multiplicities. "Same" means, here, that the elements in b are the elements
in a squared, regardless of the order.
*/


//这道题可以考虑先排序，再比较，方便很多
bool comp(int* a, int* b, int sizeArray) {
     int i=0,j=0;
     int *p=malloc(sizeof(int)*sizeArray);
     memset(p,0,sizeof(int)*sizeArray);
     for(i=0;i<sizeArray;i++){
         int squared=a[i]*a[i];

         for(j=0;j<sizeArray;j++){
            if(squared==b[j]&&p[j]!=1){
                p[j]=1;
                break;
             }
         }
     }

     for(i=0;i<sizeArray;i++)
         if(p[i]!=1)
             return false;
     return true;
}
