# include<stdio.h>
	typedef struct address{
		int houseno;
		int block;
		char city[50];
		char state[50];
	}add;
	int main(){
		add op[5];
		for(int i=0;i<5;i++){
			printf("enter the house number ");
			scanf("%d",&op[i].houseno);
			printf("enter the block");
			scanf("%d",&op[i].block);
			printf("enter the city ");
			scanf(" %[^\n]s",op[i].city);
			printf("enter the state");
			scanf(" %[^\n]s",op[i].state);
		}
        return 0;

	}