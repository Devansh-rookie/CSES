// // // #include<stdio.h>
// // // #include<math.h>
// // // #include<string.h>


// // #include<stdio.h>
// // #include<stdlib.h>

// // int main()
// // {
// // 	int *p,i;
// // 	p = (int*)calloc(1,sizeof(int));// starting of Dynamic Array
// // 	for(i=0;i<3;i++)
// // 	{
// // 		p[i]= i;
// // 		p = realloc(p,(i+1)*sizeof(int));
		
// // 	}
// // 	for(i=0;i<3;i++)
// // 	{
// // 		//printf("%d\n",*(p+i));
// // 		printf("%d\n",p[i]);
// // 	}
// //     return 0;
// // }

// #include<stdio.h>
// // #include<malloc.h>
// #include<stdlib.h>
// int main(){
//     int arr[3]={1,2,3};
//     int i;
//     int *p= (int*)calloc(1,sizeof(int));
//     for(i=0 ; i<5 ; i++){
//         p=realloc(p, (i+1)*sizeof(int));
//         *(p+i)=i+1;
        
//     }
//     for(i=0 ; i<5 ; i++){
//         printf("%d ",*(p+i));
//     }
//    free(p);// frees the entire block of code.
//     for(i=0 ; i<5 ; i++){
//         printf("%d ",*(p+i));
//     }
    
//     return 0;
// }
# include<stdio.h>
int main(){
	char str[50];
	printf("enter a string");
	gets(str);
	// scanf("%s",str);
	int count=0;
	int i=0;
	while(str[i]!='\0'){
		count++;
		i++;
	}
	printf("the length of the string is %d",count);
	return 0;
}