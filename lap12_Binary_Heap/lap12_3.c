#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void heapify(int ch_num[], char ch_n[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && ch_num[left] < ch_num[largest])
    {
        largest = left;
    }

    if (right < n && ch_num[right] < ch_num[largest])
    {
        largest = right;
    }

    if (largest != i)
    {

        int temp_num = ch_num[i];
        ch_num[i] = ch_num[largest];
        ch_num[largest] = temp_num;

        char temp_char = ch_n[i];
        ch_n[i] = ch_n[largest];
        ch_n[largest] = temp_char;

        heapify(ch_num, ch_n, n, largest);
    }
}

void buildheap(int ch_num[], char ch_n[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ch_num, ch_n, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {

        int temp_num = ch_num[0];
        ch_num[0] = ch_num[i];
        ch_num[i] = temp_num;

        char temp_char = ch_n[0];
        ch_n[0] = ch_n[i];
        ch_n[i] = temp_char;

        heapify(ch_num, ch_n, i, 0);
    }
}

int main()
{
    char ch_n[26] = "abcdefghijklmnopqrstuvwxyz";
    int ch_num[26] = {0};
    char input[100];

    scanf("%s", input);
    for (int round = 0; round < strlen(input); round++)
    {
        for (int Round_in = 0; Round_in < 26; Round_in++)
        {
            if (ch_n[Round_in] == input[round])
            {
                ch_num[Round_in]++;
            }
        }
    }

    buildheap(ch_num, ch_n, 26);

    for (int i = 0; i < 26; i++)
    {
        if (ch_num[i] > 0)
        {
            for (int i_print = 0; i_print < ch_num[i]; i_print++)
            {
                printf("%c", ch_n[i]);
            }
        }
    }

    return 0;
}
