#include<stdio.h>
struct person
{
   int name;
   int age;
   char string[10];
};
int main() {
    struct person s;
     struct person *p;
    s.name=25;
    s.age=23;
  
    printf("name = %d\n", s.name);
    printf(" age is = %d\n", s.age);
     p->age=25;
     p->name=23;
     printf("name = %d\n", p->name);
    printf(" age is = %d\n", p->age);
}
