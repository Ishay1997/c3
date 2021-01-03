
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define arraySize 2
#define MAX 15
#define LINE 256
#define NumberOfLINES 250
#define WORD 30
#define arraySize 2

// int getline(char s[])
// {
// 	int i=0;
// 	while(s[i]!='\n'&&i<LINE)//return the line size
// 	{
// 		i++;
// 	}
// 	return i;
// }
int getword(char w[])
{
	int i=0;
	while(w[i]!='\n'&&w[i]!='\t'&&w[i]!=' '&&i<WORD)//return the word size
	{
		i++;
	}
	return i;
}
int substring( char * str1, char * str2){//this method return if str2 substring in str1
    char *pointerToStr1=str1;
    char *pointerToStr2=str2;
    if(getword(str1)>=getword(str2))
    {
        while(pointerToStr1<str1+getword(str1)){
            if(*pointerToStr1==*pointerToStr2)
            {
                pointerToStr2++;
                if(pointerToStr2==str2+getword(str2))
                {
                   return 1; 
                }
            }
            else
            {
                pointerToStr2=str2;
            }
            pointerToStr1++;
        }
    }
    return 0;
}


int similar (char *s, char *t, int n){

        while(n>=0){
            if(*t==' '||*t=='\n'||*t=='\t')
            return 1;

            else if(*s!=*t){
                n--;
                s++;
            }
            else{
                s++;
                t++;
            }
        }
    
    return 0;
}


int main(){
    int i=0,flag=1;
    int num_lines=0;
    char *find_word;
    char matrix[NumberOfLINES][LINE];
    while(fgets(matrix[num_lines],LINE,stdin))
    {
        num_lines++;
    }

    char word[WORD];
    char* ptr=matrix;

    while(i<num_lines)//run over all the lines
    {
        ptr=matrix[i];//update the pointer to the fist in the line.
        while(*ptr!='\n'&&flag==1)//run until the end of file or if he find a substring.
        {
            if(substring(ptr,find_word))//check if there is substring.
         {
             printf("%s\n",matrix[i]);//print this line.
            flag=0;
         }
         else
         {
            ptr=ptr+getword(ptr);//update the pointer
         }
        }
    flag=1;
    i++;
    }

     ///////////////////////////////
    //print similar words
    while(i<num_lines)//run over all the lines
    {
        
        ptr=matrix[i];//update the pointer to the fist in the line.
        while(*ptr!='\n')//run until the end of line or if he find a substring.
        {
            while(*ptr==' '||*ptr=='\t')//if there is tab or ' ' in the middel of the line jump to the end of this.
             {
                    ptr=ptr+1;
             }

            if(similar(ptr,find_word,1))//check if there are similar.
         {
            int l= getword(ptr);
            while(l!=0)//print the word
            {
                 printf("%c",ptr);
                 ptr+=1;
                 l--;
            }
            printf("\n");

         }
         else
         {
            ptr=ptr+getword(ptr);//update the pointer
         }
        }
    i++;
    }
    
}



/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define arraySize 2
#define MAX 15
#define LINE 256
#define NumberOfLINES 250
#define WORD 30
#define arraySize 2

int getline(char s[])
{
	int i=0;
	while(s[i]!='\n'&&i<LINE)//return the line size
	{
		i++;
	}
	return i;
}
int getword(char w[])
{
	int i=0;
	while(w[i]!='\n'&&w[i]!='\t'&&w[i]!=' '&&i<WORD)//return the word size
	{
		i++;
	}
	return i;
}
int substring( char * str1, char * str2){//this method return if str2 substring in str1
    char *pointerToStr1=str1;
    char *pointerToStr2=str2;
    if(getword(str1)>=getword(str2))
    {
        while(pointerToStr1<str1+getword(str1)){
            if(*pointerToStr1==*pointerToStr2)
            {
                pointerToStr2++;
                if(pointerToStr2==str2+getword(str2))
                {
                   return 1; 
                }
            }
            else
            {
                pointerToStr2=str2;
            }
            pointerToStr1++;
        }
    }
    return 0;
}


int similar (char *s, char *t, int n){

    if(getword(s)-n==getword(t)){
        while(n>=0){
            if(*t==' '||*t=='\n'||*t=='\t')
            return 1;

            else if(*s!=*t){
                n--;
                s++;
            }
            else{
                s++;
                t++;
            }
        }
    }
    return 0;
}


int main(){
    int i=0,flag=1;
    int num_lines=0;
    char *find_word;
    char matrix[NumberOfLINES][LINE];
    while(fgets(matrix[num_lines],LINE,stdin))
    {
        num_lines++;
    }

    char word[WORD];
    char *ptr=matrix[0][0];

    while(i<num_lines)//run over all the lines
    {
        ptr=matrix[i][0];//update the pointer to the fist in the line.
        while(*ptr!='\n'&&flag==1)//run until the end of file or if he find a substring.
        {
            if(substring(ptr,find_word))//check if there is substring.
         {
             printf("%s\n",matrix[i]);//print this line.
            flag=0;
         }
         else
         {
            ptr=ptr+getword(ptr);//update the pointer
         }
        }
    flag=1;
    i++;
    }

     ///////////////////////////////
    //print similar words
    while(i<num_lines)//run over all the lines
    {
        ptr=matrix[i][0];//update the pointer to the fist in the line.
        while(*ptr!='\n')//run until the end of line or if he find a substring.
        {
            while(*ptr==' '||*ptr=='\t')//if there is tab or ' ' in the middel of the line jump to the end of this.
             {
                    ptr=ptr+1;
             }

            if(similar(ptr,find_word,1))//check if there are similar.
         {
            int l= getword(ptr);
            while(l!=0)//print the word
            {
                 printf("%c",ptr);
                 ptr+=1;
                 l--;
            }
            printf("\n");

         }
         else
         {
            ptr=ptr+getword(ptr);//update the pointer
         }
        }
    i++;
    }
    
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
void print_similar_words(char * pointerMartrix,char * str){
char *PointBeginWord,*PointEndWord;
   int c,sizeWord;
   FILE *fp=fopen("find_input.txt","rb");
   while((c=fgetc(fp))!=EOF){
       sizeWord=getword(fp);
       PointBeginWord=fp;
       PointEndWord=fp+sizeWord;
        while(fp!=PointEndWord){
        if(similar (fp, str, 1))
        {
            printLine(PointBeginWord,PointEndWord);//print the line
        }
            fp=fp+sizeWord+1;
        }
   }
}*/
/*
void print_lines(char *str){
   char *PointBeginLine,*PointEndLine;
   int c,sizeLine;
   FILE *fp=fopen("file","rb");
   while((c=fgetc(fp))!=EOF){
       sizeLine=getline(fp);
       PointBeginLine=fp;
       PointEndLine=fp+sizeLine;
        while(fp!=PointEndLine){
        if(similar (fp, str, 1))
        {
            printLine(PointBeginLine,PointEndLine);//print the line
        }
        else
        {
            fp=fp+getword(fp)+1;
        }
        }
   }
}
void printLine(char *PointBeginLine,char *PointEndLine){//get the begin of the line and end ,this method print all the line.
    char *i=PointBeginLine;
    for(;i<PointEndLine;i++){
        printf("%c",*i);
    }
}










int getline(char s[])
{//this method return the line size.
    int lineSize=0;
    while(*s!='\n')
    {
        lineSize++;
        s++;
    }
    return lineSize;
}
int getword(char w[])
{
    //this method return the word size.
    int wordSize=0;
    while((*w!=' ')&&(*w!='\t')&&(*w!='\n'))
    {
        wordSize++;
        w++;
    }
    return wordSize;
}


int substring( char * str1, char * str2){
    char *pointerToStr1=str1;
    char *pointerToStr2=str2;
    if(getword(str1)>=getword(str2))
    {
        printf("%d\n",pointerToStr1);
        printf("%d\n",str1);
       // prinf("%d/n",getword(str1));
        while(pointerToStr1<str1+getword(str1)){
            if(*pointerToStr1==*pointerToStr2)
            {
                pointerToStr2++;
                if(pointerToStr2==str2+getword(str2))
                {
                   return 1; 
                }
            }
            else
            {
                pointerToStr2=str2;
            }
            pointerToStr1++;
        }
    }
    return 0;
}

#define size 5
void shift_element(int* p,int i){
    for(;i>=0;i--){//shift the i elements from pointer p ,one place right.
        *(p+i)=*(p+i-1);
    }
}
void insertion_sort(int* arr,int len){
    int i,j,remember;
    int flag =1;
for(i=1;i<len;i++) {
    flag=1;
        for(j=0;j<i&&flag==1;j++){
            if(*(arr+i)<*(arr+j)){
                 remember=*(arr+i);
                shift_element((arr+j),i-j);
                *(arr+j)=remember;
                flag=0;
            }
        }
    }
}

int main(void){
    int arr[arraySize];
    int i;
     printf("please give me %d numbers \n",arraySize);//todo need to know how to stop getting nubers.
    for(i=0;i<arraySize;i++){
        scanf("%d",arr+i);
    }
insertion_sort(arr,arraySize);
 
for(i=0;i<arraySize-1;i++){//print the array after sort.
    printf("%d,",*(arr+i));
}
printf("%d\n",*(arr+i));
char arr1[]={'d','f','f',' ','e','\n'};
char array[]={'d','f','s','e','d','f','l',' ','d','f','f','\n'};
int x=getline(array);
printf("ff");
printf("%d\n",x);
x=getword(array);
printf("%d\n",x);
x=getword(arr1);
printf("%d\n",x);
x=substring( array, arr1);
printf("%d",x);
//x=similar (array, arr1, 4);
print("ishaylevy %d",x);
}*/
// int *p=(arr+3);

//       printf("%d ",*p );//why arr[loop]didnt work??  *(p+loop)  arr[loop]
//       p++;
//    }

//     int array[size];
//      printf("please enter 50 int numbers");
//     for (i=0;i<size;i++){//get from the user 50 numbers.
//        scanf("%d", (array+i));
//     }

//     insertion_sort(array,size);

//     p=array;  
//  for(i = 0; i < size-1; i++){
//       printf("%d ,",*p );
//       p++;
//    }
//    printf("%d ",*p );
// return 0;

//     int change=n;
//     char *PointerTos=s;
//     char *PointerTot=t;
//   int sSize=getword(s);
//   int tSize=getword(t);
//   int s_t=sSize-tSize;

//   if ((0<=s_t)&&(s_t<=n))//if the size between s and t is smaller then n.
//   {
//       while(PointerTos!='/n'&&PointerTot!='/n'&&change>=0)
//       {
//         if (PointerTos==PointerTot)
//         {
//             PointerTos++;
//             PointerTot++;
//         }
//         else
//         {
//             change--;
//             PointerTos++;
//         }
//       }
//       if(change>=0)//return 1 if the s and t are similer.
//       {
//          return 1;
//       }
//   }
// else
// return 0;
// }
//     printf("%d",z);
   
//     while(str1!='/n'&&pointerToStr2!='/n')
//     {
//         if(*(str1)==*(pointerToStr2)){
//             pointerToStr2++;
//         }
//         else
//         {
//             pointerToStr2=str2;
           
//         }
//             str1++;
//     }
//     if(pointerToStr2=='/n'){
//         return 1;
//     }

//     return 0;
// }
///////////////////////////////////////////////////
/*structure declaration*/
// struct node  
// { 
//     int data; 
//     struct node *left; 
//     struct node *right; 
//     struct node *father;
// }; 
  
// /* newNode() allocates a new node with the given data and NULL left and  
// right pointers. */
// struct node* newNode(int data) 
// { 
// // Allocate memory for new node  
// struct node* node = (struct node*)malloc(sizeof(struct node)); 
  
// // Assign data to this node 
// node->data = data; 
  
// // Initialize left and right children as NULL 
// node->father=NULL;
// node->left = NULL; 
// node->right = NULL; 
// return(node); 
// } 
  
  
// int main() 
// { 
// /*create root*/
// struct node *root = newNode(1);  
// /* following is the tree after above statement  
  
//         1 
//     / \ 
//     NULL NULL  
// */
  
//   struct node *rightroot;
//   struct node *leftroot;
// root->left     = newNode(2); 
// root->left->father     = root; 
// root->right     = newNode(3); 

// rightroot=root->right;
// leftroot=root->left;
// rightroot->right=newNode(5);
// leftroot->left=newNode(6);


// root->right->right=newNode(5);
// root->right->right->right=newNode(6);
// root->right->right->right->left=newNode(7);
// root->right     = newNode(12); 
/* 2 and 3 become left and right children of 1 
        1 
        / \ 
        2     3 
    / \ / \ 
    NULL NULL NULL NULL 
*/
  
  
//root->left->left = newNode(4); 
/* 4 becomes left child of 2 
        1 
    /     \ 
    2         3 
    / \     / \ 
4 NULL NULL NULL 
/ \ 
NULL NULL 
*/
// printf("%d",root->left->father->data);
//  // printtree(root);
// getchar(); 
// return 0; 
// } 
// void printtree(struct node *root){
//     if(root!=NULL){
//         printf("%d\n",root->data);
//     }
//     else 
//     {return ;}
//             printtree(root->right);
//             printtree(root->left);
//     }

 /*struct student
{
char name[30];
int roll;
float perc;
};
int main()
{
struct student *pstd;
/*Allocate memory dynamically*/


// pstd1431671584
//1431671584tf("Insufficient Memory, Exiting... \n");
// return 0;
// }
// /*read and print details*/
// printf("Enter name: ");
// gets(pstd->name);
// printf("Enter roll number: ");
// scanf("%d",&pstd->roll);
// printf("Enter percentage: ");
// scanf("%f",&pstd->perc);
// printf("\nEntered details are:\n");
// printf("Name: %s, Roll Number: %d, Percentage: %.2f\n",pstd->name,pstd->roll,pstd->perc);
// free(pstd);
// return 0;
// }

// void swap_first_last(char arr[])
// { 
//     int i,j,count;
//     int size[3];
//     for(i=0;i<3;i++){
//         count=0;
//         while(arr[j]){
//         {
//             count++;
//             j++;
//         }
//      size[i]=count;    
//     }
// }
// printf("djjjjjjjjjjjjjjjjjjjjd");
// j=0;
// char newarray[strlen(arr)];
//     for(i=size[2];i<strlen(arr);i++){
//         newarray[j]=arr[i];
//         j++;
//     }
//     for(i=size[1];i<size[2];i++){
//         newarray[j]=arr[i];
//         j++;
//     }
//     for(i=size[0];i<size[1];i++){
//         newarray[j]=arr[i];
//         j++;
//     }

//     for(i=0;i<strlen(newarray);i++){
//         printf("%c",newarray[i]);
//     }
// }


// void main(){
//     char num[]={'a','b','\0','c','d','\0','e','f','\0'};
//     swap_first_last(num);
// }

// int returnnum(char *str){
//     int num=0;
//     int sign=1;
//     if (*str=='-'){
//     sign=-1;
//     }
//     str++;
//     while(*str!='\0')
//     {
//         num=num*10+*str-'0';
//         str++;
//     }
// return sign*num;

// }
// int strcmp(char *str1, char *str2)
// {
// while (*str1 && *str2 && *str1 == *str2) {
//     str1++;
//     str2++;
// }
// return *str1 - *str2;
// }
/*
char upCase(char c){///todo check what happend here.
if(c>='a'&&c<='z'){
    c=c-'a'+'A';
    return c;
}
}
int isEqualStringN(char s1[], char s2[], int n) {
   // int s1len,s2len;
   printf("%d\n",strlen(s1));
   printf("%d\n",strlen(s2));
    if(strlen(s1)!=strlen(s2))
        return 0;
       int  s1len=strlen(s1);
        while(s1len!=0&&*s1==*s2){
            s1++;
            s2++;
        }
        if(*s1!='\0'||*s2!='\0')
        return 0;
        return 1;
}*/
    // printf("%d\n",strlen(s1));
    // printf("%d\n",strlen(s2));

    // int i=0;
    // while(s1[i]==s2[i])
    // {
    //     i++; 
    // }
    // if(i==sizeof(s1)&&i==sizeof(s2)){
    //     return 1;}
    //     else 
    //     return 0;

    // if(s1[i]=='\0'&&s2[i]=='\0')
    // {
    //     return 1;
    // }
    // return 0;

// for (int i=0; i<n; i++){
//     if (upCase(s1[i]) != upCase(s2[i])) 
//     {
//         return 0;
//     }-1
// int isEqualStringN(char s1[], char s2[], int n) {
//         while(*s1!='\0'&&*s2!='\0'){
//             s1++;
//             s2++;
//         }
//         if(*s1!=*s2)
//         return 0;
//         else
//         {
//             return 1;
//         }
//     } 


    
// char* strcat(char *dest, char *src){
//     char *str=dest+strlen(dest);
//     while(*src!='\0')
//     {
//         *str=*src;
//         str++;
//         src++;
//     }
//     *str='\0';
//     return dest;
// }
// int main(void){
// char *dest="ishay";
// char *src=" levy";
// char*p= strcat(dest,src);
// printf("%s",p);
// return 0;

// }









