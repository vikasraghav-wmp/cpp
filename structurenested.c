#include<stdio.h>
#include<stdlib.h>
struct home
{
   char address[20];
   int family_count;
};

struct college
{
   int friend_count;
   int class;
   char class_teacher[20];
};

struct student
{
   struct home *h;
   struct college *c;

};
struct student *st;

void input(struct student *st, int count);
void display(struct student *st, int count);

int main()
{
   int count;
   printf(" Range : ");
   scanf("%d", &count);
   st=(struct student*)malloc(count*sizeof(struct student));
   st->h=(struct home*)malloc(count*sizeof(struct home));
   st->c=(struct college*)malloc(count*sizeof(struct college));

   input(st,count);
   display(st,count);

   return 0;
}

void input(struct student *st, int count)
{
   for (int i = 0; i < count; i++)
   {
      printf("\n student %d home address : ", i+1);
      scanf("%s",st->h->address);

      printf("\n student %d home family count : ", i+1);
      scanf("%d", &st->h->family_count);

      printf("\n student %d college Class Teacher : ", i+1);
      scanf("%s", st->c->class_teacher);

      printf("\n student %d college friend count : ", i+1);
      scanf("%d", &st->c->friend_count);
      
      printf("\n Student %d college Class : ", i+1);
      scanf("%d", &st->c->class);
   }
}

void display(struct student *st, int count)
{
for (int i = 0; i < count; i++)
   {
      printf("\n student %d home address : %s ", i+1,st->h->address);

      printf("\n student %d home family count : %d ", i+1, st->h->family_count);

      printf("\n student %d college Class Teacher : %s ", i+1, st->c->class_teacher);

      printf("\n student %d college friend count : %d ", i+1, st->c->friend_count);
      
      printf("\n Student %d college Class : %d ", i+1, st->c->class);
   }
}