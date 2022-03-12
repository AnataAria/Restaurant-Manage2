#include <stdio.h>

typedef struct student {
    char name[256];
    char class[256];
} student;

int main()
{
    student student1;
    student1.name = "Qui";
    printf("%s", student1.name);
    return 0;
}
