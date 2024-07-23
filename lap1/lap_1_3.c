#include <stdio.h>
typedef struct
{
    char Name[25];
    float Length;
} Song;
int main()
{
    Song Title1 = {"Sugar", 2.50}, Title2 = {"Happy", 3.0}, Title3;
    Title3 = Title1;
    Title1 = Title2;
    Title2 = Title3;
    printf("1: Title - %s, Length - %.2f\n", Title1.Name, Title1.Length);
    printf("2: Title - %s, Length - %.2f\n", Title2.Name, Title2.Length);
    return 0;
}
// 3 Title1 Title2 Title3
