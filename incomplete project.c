#include<stdio.h>
#include<stdlib.h>

struct student { // creating the student struct
    char id[10];
    char name[10];
    char Fname[10];
    float bacAvg;
};


struct project { // creating the project struct
    char theme[10];
    struct student student1;
    struct student student2;
    int dif;
};

int num, S=-1, P=-1;

struct student tabS[S]; // an array to store the students
struct project tabP[P]; // an array to store the projects

// initializeing the functions
void creatProject(); // a function to create a project
void creatStudent(); // a function to create a student
void addStudents();  // a function to add students to a project
void displayStudents(); // a function to display students in decending order by their bac average
void displayProjects(); // a function to display projects in ascending order by their difficulty
void themeSearch();    // a function to search for projects by theme

void main(){

   while(1){
    printf("1: creatProject \n"); // displaying all the options to the user
    printf("2: creatStudent \n");
    printf("3: addStudents  \n");
    printf("4: displayStudents \n");
    printf("5: displayProjects \n");
    printf("6: themeSearch \n");
    printf("7: exit \n");
    printf(">> ");
    scanf("%i", &num); // reading the user's input

    switch(num){
        case 1: creatProject(); break; //calling the coresponding function
        case 2: creatStudent(); break;
        case 3: addStudents(); break;
        case 4: displayStudents(); break;
        case 5: displayProjects(); break;
        case 6: themeSearch(); break;
        case 7: exit(0);break; // the exit function terminates the program by exiting the loop
        default: printf("invalid input\n");scanf("%*s");break; // default message in case of an invalid input

    }
   }
}
void creatProject(){ // a function to create a project 

// your code goes here 
}
void creatStudent(){ // a function to create a student
    
 // your code goes here
}
void addStudents(){ // a function to add students to a project

  // your code goes here
}
void displayStudents(){// a function to display students in decending order by their bac average
    
    struct student sTab[5];
    struct student temp;
    int i=0,j=0;

    while(i<=S){ // this loop copies the students into another array
       sTab[i]=tabS[i];
       i++;
    }
    i=0;
    temp=tabS[0];
  while (i<=S) // this part of the code sortes the new array using a selection sort algorithm
  {
    j=i+1;
    while(j<=S){
        if(sTab[j].bacAvg>sTab[i].bacAvg){ // this if statement checks if there is a student with a bigger average than the max
           temp=sTab[i]; // this is a simple permutation 
           sTab[i]=sTab[j];
           sTab[j]=temp;
        }
        j++;
    }
    i++; 
  }
  i=0;
  while(i<=S){ // this loop displays the sorted array
         printf("%i. %s %s: %2f\n",i+1 ,sTab[i].Fname,sTab[i].name,sTab[i].bacAvg);
         i++;
    }
}

void displayProjects(){ // a function to display projects in ascending order by their difficulty

    struct project sTab[5];
    struct project temp;
    int i=0,j=0;

    while(i<=P){ // this loop copies the projects into another array
       sTab[i]=tabP[i];
       i++;
    }
    i=0;
    temp=tabP[0];
  while (i<=P) // this part of the code sortes the new array using a selection sort algorithm
  { 
    j=i+1;
    while(j<=P){
        if(sTab[j].dif<sTab[i].dif){ // this if statement checks if there is a project with a lower difficulty  than the min
           temp=sTab[i]; // this is a simple permutation
           sTab[i]=sTab[j];
           sTab[j]=temp;
        }
        j++;
    }
    i++; 
  }
  i=0;
  while(i<=P){  // this loop displays the sorted array
        printf("%i. %s: %i\n",i+1 ,tabP[i].theme,tabP[i].dif);
         i++;
    }
}
void themeSearch(){ // a function to search for projects by theme

    char theme1[10];
    int i=0, j=0,empty=1,cmpr;

    printf("enter the project's theme: "); // asking the user to enter the theme
    scanf("%s",&theme1); // reading the theme entered by the user
     printf("search results for %s: \n", theme1); 
     while(i<=P){ // this loop checks every elment in the project array
        cmpr = strcmp(theme1,tabP[i].theme); // using the strcmp(); function to compare the theme of the project and the theme entered by the user
        if(cmpr == 0){ // if the strcmp(); returns 0 then the themes are equal
        j++;
        printf("%i. %s: %i\n",j,tabP[i].theme,tabP[i].dif); //displaying the project 
        printf("student1:%s %s\n",tabP[i].student1.Fname,tabP[i].student1.name);
        printf("student2:%s %s\n",tabP[i].student2.Fname,tabP[i].student2.name);
        empty=0; 
         }
      i++;
    }
   if(empty){ // message displayed if the search returns nothing

    printf("no matching results were found\n");
   }
}