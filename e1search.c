#include<stdio.h>
#include<stdlib.h>

void linear_search();
void binary_search();

void main(){
	int choice;
	while(1){	
	printf("\n*******************************\n");
	printf("\nInitiating element Search...");
	printf("loading....100 \n");
	printf("\n\tWhich algorithm to use?\n");
	printf("\t\t 1.Linear search\n\t\t2.Binary Search\n\t\t3.Exit\n");
	scanf("%d", &choice);
	switch(choice){
		case 1: 
			linear_search();
			break;
		case 2:
			binary_search();
			break;
		case 3:
			printf("Exited sucessfully...\n**********************************************\n");
			exit(0);
			break;
		}	
	}
}


void linear_search() {
	int i,n,x,a[100],al=0, b;
	
	printf("Enter number of elements in the array:");		
	scanf("%d", &n);
	
	printf("Enter the elements:");
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	printf("Enter the element to search");			
	scanf("%d",&x);
	for(i = 0;i<n;i++){
		if(a[i] == x){
			al=1;
			b = i;
			break;
		}
		else{
			al=0;
		}	
	}
	
	if(al == 1){
		printf("%d is present at location %d \n",x,b+1);
	}
	else{
		printf("Element not found\n");
	}
}
		
void binary_search() {
	int n, i, j, a[100],search, temp=0;
	printf("Enter the number of elements in the array:");		
	scanf("%d", &n);
	int high=n,low=0;
	int mid;
	printf("Enter the elements");				
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}
	for(i=0;i<n;i++){
		for(j=0; j<n;j++){
			if(a[j-1]>a[j]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("Enter the elements to search:");
	scanf("%d", &search);
	int flag = 0;
	
	while(low <= high){
		mid = (low+high)/2;
		if(search < a[mid]){
			high = mid-1;
		}
		else if(search == a[mid]){
			flag = 1;
			break;
		}
		else{
			low = mid+1;	
		}
			
	}
	
	if(flag == 1){
	
		printf("%d is present at  location %d\n",search,mid+1);
	}
	else {
		printf("Invalid\n");
	}
}




