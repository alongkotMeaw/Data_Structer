#include <stdio.h>
#include <string.h>

struct Song
{
    char Name[25];
    float Length;
};
struct Song ZeroOut();
void main()
{

    struct Song Title1 = {"Kill this love", 2.50}, Title2;

    Title2 = ZeroOut(&Title1);
    // เเสดงค่า
    printf("1: %s, %.2f\n", Title1.Name, Title1.Length);
    printf("2: %s, %.2f\n", Title2.Name, Title2.Length);
}
struct Song ZeroOut(struct Song *x)
{
    struct Song y = {"I will survive", 3.20};
    strcpy(x->Name, " ");
    x->Length = 0;
    return y;
}
