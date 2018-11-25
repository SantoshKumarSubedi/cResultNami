#include<stdio.h>

void subjects();
void percentage(float*);


 int main(){
   printf("%s\n","Enter the name of students");
   //char *nam[20];
   //scanf("%s\n",&nam );
   subjects();
 }

void subjects(){
	float mark[6];
	printf("Enter the mark in different subject.\n");
	printf("Computer Network");
	scanf("%f",&mark[0]);
	printf("\nOperating System");
	scanf("%f",&mark[1]);
	printf("\nModern Network");
	scanf("%f",&mark[2]);
	printf("\n Web Development");
	scanf("%f",&mark[3]);
	printf("\n database");
	scanf("%f",&mark[4]);
	printf("\ngroup project");
	scanf("%f",&mark[5]);
	percentage(mark);
}

void percentage(float *mark){
	float total=0;
	for(int i=0;i<=5;i++){
		total = total+mark[i];
	}
	float per = total/600*100;
	printf("percentage : %f",per);
}
