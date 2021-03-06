#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX STUDENTS 10
struct student
{
    char fname[100]; char lname [100];
    int year;
    int age;
};
struct student class []=
{
    "Sean " , "Penn" ,2 ,21 , "Sean " , "Connery " ,4 ,25 , "Angelina " , "Jolie " ,3 ,22 , "Meryl " , "Streep " ,4 ,29 , "Robin " , "Williams " ,3 ,32 , "Bill " , "Gates " ,3 ,17 , "Jodie " , "Foster " ,4 ,25 , "John " , "Travolta " ,1 ,17 , "Isaac " , "Newton " ,2 ,19 , "Sarah " , "Palin " ,2 ,19 
};

//@function compare first name
//@desc compares first name of two records.

int compare_first_name ( const void *a , const void *b)
{
    struct student *sa = (struct student *)a;
    struct student *sb = (struct student *)b;
    return strcmp(sa->fname ,sb->fname);
}

//@function compare lname name
//@desc compares last name of two records .

int compare_last_name ( const void *a , const void *b)
{
    struct student *sa = (struct student *)a;
    struct student *sb = (struct student *)b;
    return strcmp(sa->lname , sb->lname );
}

//@function apply
//@desc applies
void apply( struct student *sarr , int nrec , void (*fp )( void* prec , void* arg ) , void* arg) 
{
    int i = 0;
    for ( i = 0; i < nrec ; i++)
    {
        //∗ callback ∗/
        fp(&sarr [i], arg);
    }
}

//@function printrec
//@desc prints student record

void printrec( void* prec , void* arg)
{
    struct student *pstud = (struct student *) prec;
    printf ( "%-20s %-20s %2d %2d\n" , pstud->fname , pstud->lname , pstud->year , pstud->age);
}
//@function isolder
//@desc prints student record
void isolder( void *prec , void *arg)
{
    int *age=(int *) arg;
    struct student *pstud = (struct student *) prec ;
    if (pstud->age < *age )
    return;
    //∗ do nothin ∗/
    else printf ( "%-20s %-20s %2d %2d\n" , pstud->fname , pstud->lname , pstud->year , pstud->age ); 
}
int main()
{
    int nstudents = sizeof (class)/ sizeof (struct student);
    int age;
    puts ( "Raw records:" );
    puts ( "-------------------------------" );
    apply ( class, nstudents, printrec, NULL);
    //∗ sort based on first name∗/
    puts ( "Sorted by first name:" );
    puts ( "-------------------------------" );
    qsort ( class , nstudents , sizeof ( struct student ) , compare_first_name ); 
    apply (class, nstudents , printrec ,NULL);
    //∗ s o r t based on l a s t name∗/
    puts ( " Sorted by last name:" ) ;
    puts ( " -------------------------------" );
    qsort (class , nstudents , sizeof ( struct student ) , compare_last_name );
    apply (class , nstudents , printrec ,NULL ) ;
    //∗ p r i n t p e o p l e o l d e r than 20 ∗/
    puts ( " People older than 20: " ) ;
    puts ( " -------------------------------" );
    age = 20;
    apply (class , nstudents , isolder ,&age);
    return 0;
}
