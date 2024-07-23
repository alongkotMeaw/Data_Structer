#include <stdio.h>
typedef struct
{
    char Name[25];
    float Length;
} Song;

int main()
{
    Song Title[3] = {{"Sugar", 2.50}, {"Happy", 3.0}, {"lala", 2.0}};

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", Title[i].Name);
        printf("%f\n", Title[i].Length);
    }

    return 0;
}
// 3 Title1 Title2 Title3
