#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int mid ;
void swap (int *a ,int *b) {
	int temp ;
	temp = *a ;
	*a=*b;
	*b= temp;
	
} 
void print (int array[] ,int size){
	int i=0;
	for (i=0;i<size;i++)
		printf("%d \n",array[i]);
}
int sort_mid ( int array[],int first,int last){
	int i=first;
	int j=last;
	mid=array[first] ;	
	while (i<j) {
		do{
			i++ ;
			
		}while (array[i]<=mid) ;
		do{
			j--;
			
		}while (array[j]>mid  );
		
		if (i<j){
			swap(&array[i],&array[j]);
		}
			
	}
	swap(&array[first],&array[j]);
	return j;

}
void quick_sort(int array[],int first ,int last ){
	int i=first;
	int u;
	u=sort_mid (array,first,last);
	//print(array, last);
	//printf("\n \n \n");
	if(i<last){
			quick_sort (array,i,u);
			quick_sort (array,u+1,last);
	}
		
}	

void insertion_sort(int array[],int size){
	int i;
	int key ;
	int j;
	for (i=1;i<size;i++){
		key=array[i] ;
		j=i-1;
		while(j>=0 && array[j] >key){
			array[j+1]=array[j];
			j-- ;
		}
		array[j+1]=key;
	}
	printf("the array is sorted using insertion sort in %u seconds \n" ,clock());
}
		
int main(){
	int size=100000;
	int x;
	int first=0;
	int number [size];
	for (x=0;x<100000;x++)
		number [x]=rand() % 50  + 1 ;
	quick_sort (number,first,size);
	printf("the array is sorted using quick sort in %u seconds \n" ,clock());
	//print (number ,size) ;
	printf("\n \n \n") ;

	insertion_sort(number,size) ;
	//print (number ,size) ;
	
	return 0;
}
		

