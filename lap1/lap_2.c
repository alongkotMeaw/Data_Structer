#include <stdio.h>
#include <string.h>
// ประกาศสตัก
struct Song
{
    char Name[25];
    float Length;
};
// ประกาศฟังชัน Zeroout
struct Song ZeroOut(struct Song);

void main()
{
    // ประกาศเเละกำหนดค่าตัวเเปรชนิด song
    struct Song Title1 = {"Kill this love", 2.50}, Title2;
    // เรียกฟังชัน zero out
    Title2 = ZeroOut(Title1);
    // เเสดงค่า
    printf("1: %s, %.2f\n", Title1.Name, Title1.Length);
    printf("2: %s, %.2f\n", Title2.Name, Title2.Length);
}
struct Song ZeroOut(struct Song x)
{
    struct Song y = {"I will survive", 3.20};
    strcpy(x.Name, " ");
    x.Length = 0;
    return y;
}
/*
     ชนิดพารามิตเตอรในฟังชัน zeroout คือ song
     ชนิดของข้อมูลที่คินค่าคือ song
*/
/*
   เพราะเป็นส่งค่าไปในฟังชันไม่ได้เป็นการส่งตำเเหน่งที่ค่าอยู่ของค่าไปป
*/