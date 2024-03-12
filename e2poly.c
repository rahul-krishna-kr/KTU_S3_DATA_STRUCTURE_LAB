#include<stdio.h>
#include<stdlib.h>

struct poly{
	int coeff;
	int expo;
}p1[10],p2[10],p3[10];

void sort(struct poly p[10], int n){
	struct poly temp;
	
	for(int j=0;j<n-j-1;j++){
		
		if(p[j].expo <p[j+1].expo){
			temp = p[j];
			p[j] = p[j+1];
			p[j+1] = temp;
		}}}
		
		
		
		
int readpoly(struct poly p[10]){
	int i=0,t1;
	printf("\n\nEnter total number of terms in the polynomial %d:",i+1);
	scanf("%d", &t1);
	printf("\nEnter COEFFICIENT and respective EXPONENT :");
	for(i=0;i<t1;i++){
		printf("\nEnter Coefficient(%d) :",i+1);
		scanf("%d", &p[i].coeff);
		printf("\nEnter Exponent(%d) :",i+1);
		scanf("%d", &p[i].expo);
		}
	for(int i=0;i<=t1;i++){
		for(int j=0;j<=t1;j++){
			int temp1=0,temp2=0;
			if(p[i].expo < p[i+1].expo){
				temp1 = p[i].expo;
				p[i].expo = p[i+1].expo;
				p[i+1].expo = temp1;
				temp2 = p[i].coeff;
				p[i].coeff = p[i+1].coeff;
				p[i+1].coeff = temp2;
			}}}return(t1);}
			
			
			
			
			
	
void displaypoly(struct poly p[10], int term){
	int k;
	/*sort(p,term);*/
	for(k = 0; k <= (term-1);k++){
		if(p[k].coeff != 0){
			printf("%dX^%d", p[k].coeff, p[k].expo);
		}
		while(k < term-1){
			printf(" + ");
			break;
			}
	}
	/*if(p[term-1].coeff != 0){
			printf(" %dX^%d ", p[term-1].coeff, p[term-1].expo);
		}*/
}






int addpoly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10]){
	int i,j,k;
	i = j = k = 0;
	while(i<t1 && j<t2){
		if(p1[i].expo > p2[j].expo){
			p3[k].coeff = p1[i].coeff;
			p3[k].expo = p1[i].expo;
			i++; k++;
		
		}
		
		else if(p1[i].expo < p2[j].expo){
			p3[k].coeff = p2[j].coeff;
			p3[k].expo = p2[j].expo;
			j++; k++;
		}
		
		else {
			p3[k].coeff = p1[i].coeff + p2[j].coeff;
			p3[k].expo = p1[i].expo;
			i++; j++; k++;
		}
	}
	while(i<t1){
		p3[k].coeff = p1[i].coeff;
		p3[k].expo = p1[i].expo;
		i++; k++;
	}
	while(j<t2){
		p3[k].coeff = p2[j].coeff;
		p3[k].expo = p2[j].expo;
		j++; k++;
	}
	return(k);
}






int main() {
	int t1,t2,t3;
	int choice;
	while(1){
		printf("\n1.Input polynomials\n2.Display Polynomials\n3.Add Polynomials\n4.Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:  
  				t1 = readpoly(p1);
				sort(p1,t1);
			         t2 = readpoly(p2);
			         sort(p2,t2);
			         break;
			case 2: 	printf("\nFirst Polymonial\n");
				displaypoly(p1,t1);
				printf("\nSecond Polynomial\n");
				displaypoly(p2,t2);
				break;
			case 3:  t3 = addpoly(p1,p2,t1,t2,p3);
				printf("\n\nDisplaying resulting polynomial after Addition...\n");
				displaypoly(p3,t3);
				printf("\n");
				break;
			case 4: 
				exit(0);
				break;
			}
	}
	return 0;
}





