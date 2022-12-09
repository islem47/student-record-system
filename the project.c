#include<stdio.h>
#include<stdlib.h>

struct student {
    char id[10];
    char name[10];
    char Fname[10];
    float bacAvg;
};


struct project {
    char theme[10];
    struct student student1;
    struct student student2;
    int dif;
};

int num, S=-1, P=-1;

struct student tabS[S];
struct project tabP[P];

void creatProject();
void creatStudent();
void addStudents();
void displayStudents();
void displayProjects();
void themeSearch();

void main(){

   while(1){
    printf("1: creatProject \n");
    printf("2: creatStudent \n");
    printf("3: addStudents  \n");
    printf("4: displayStudents \n");
    printf("5: displayProjects \n");
    printf("6: themeSearch \n");
    printf("7: exit \n");
    printf(">> ");
    scanf("%i", &num);

    switch(num){
        case 1: creatProject(); break;
        case 2: creatStudent(); break;
        case 3: addStudents(); break;
        case 4: displayStudents(); break;
        case 5: displayProjects(); break;
        case 6: themeSearch(); break;
        case 7: exit(0);break;
        default: printf("invalid input\n");scanf("%*s");break;

    }
   }
}
void creatProject(){
    
    P++; 

    printf("enter the project's theme: ");
    scanf("%s", &tabP[P].theme);

    printf("enter the project's difficulty: ");
    scanf("%i", &tabP[P].dif);
    printf("project created sucesfully\n");
}
void creatStudent(){
    
    S++;

    printf("enter the student's id: ");
    scanf("%s", &tabS[S].id);

    printf("enter the student's name: ");
    scanf("%s", &tabS[S].name);

    printf("enter the student's family name: ");
    scanf("%s", &tabS[S].Fname);

    printf("enter the student's BAC average: ");
    scanf("%f", &tabS[S].bacAvg);
    printf("student created sucesfully\n");
}
void addStudents(){

    int p,s1,s2,i=0;
    
    printf("choose a project\n");
    while(i<=P){
         printf("%i. %s\n",i+1 ,tabP[i].theme);
         i++;
    }
    printf(">> ");
    scanf("%i",&p);

    i=0;
    printf("choose two students\n");
    while(i<=S){
         printf("%i. %s %s\n",i+1 ,tabS[i].Fname,tabS[i].name);
         i++;
    }
    printf(">> ");
    scanf("%i %i",&s1,&s2);

    tabP[p-1].student1=tabS[s1-1];
    tabP[p-1].student2=tabS[s2-1];
}
void displayStudents(){
    
    struct student sTab[5];
    struct student temp;
    int i=0,j=0;

    while(i<=S){
       sTab[i]=tabS[i];
       i++;
    }
    i=0;
    temp=tabS[0];
  while (i<=S)
  {
    j=i+1;
    while(j<=S){
        if(sTab[j].bacAvg>sTab[i].bacAvg){
           temp=sTab[i];
           sTab[i]=sTab[j];
           sTab[j]=temp;
        }
        j++;
    }
    i++; 
  }
  i=0;
  while(i<=S){
         printf("%i. %s %s: %2f\n",i+1 ,sTab[i].Fname,sTab[i].name,sTab[i].bacAvg);
         i++;
    }
}

void displayProjects(){

    struct project sTab[5];
    struct project temp;
    int i=0,j=0;

    while(i<=P){
       sTab[i]=tabP[i];
       i++;
    }
    i=0;
    temp=tabP[0];
  while (i<=P)
  {
    j=i+1;
    while(j<=P){
        if(sTab[j].dif<sTab[i].dif){
           temp=sTab[i];
           sTab[i]=sTab[j];
           sTab[j]=temp;
        }
        j++;
    }
    i++; 
  }
  i=0;
  while(i<=P){
        printf("%i. %s: %i\n",i+1 ,sTab[i].theme,sTab[i].dif);
         i++;
    }
}
void themeSearch(){

    char theme1[10];
    int i=0, j=0,empty=1,cmpr;

    printf("enter the project's theme: ");
    scanf("%s",&theme1);
     printf("search results for %s: \n", theme1);
     while(i<=P){
        cmpr = strcmp(theme1,tabP[i].theme);
        if(cmpr == 0){
        j++;
        printf("%i. %s: %i\n",j,tabP[i].theme,tabP[i].dif);
        printf("student1:%s %s\n",tabP[i].student1.Fname,tabP[i].student1.name);
        printf("student2:%s %s\n",tabP[i].student2.Fname,tabP[i].student2.name);
        empty=0;
         }
      i++;
    }
   if(empty){

    printf("no matching results were found\n");
   }
}