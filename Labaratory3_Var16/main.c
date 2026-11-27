#include <stdio.h>
#include<windows.h>
int main()
{
    int n = 0;
    int is_entered_correct = 0;

   
    do
    {
        printf("Enter person ot 2 do 30: ");
       
        if (scanf_s("%d", &n) != 1)
        {
            
            while (getchar() != '\n');
            continue;
        }

        if (n >= 2 && n <= 30)
        {
            is_entered_correct = 1;
        }
        else
        {
            printf("Error!\n");
            is_entered_correct = 0;
        }
    } while (is_entered_correct != 1);

    int loop_count = 0;

   //zicl l7
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            loop_count++;
            if ((i + j) % 2 == 0)
            {
                printf("[%d,%d] Host - %d (chet)\n", i, j, i);
            }
            else
            {
                printf("[%d,%d] Host - %d (nechet)\n", i, j, j);
            }
        }
    }

    
    int control_n = (n * (n - 1)) / 2;


    int max_hosts = -1;
    int num_lider = 1;
    for (int k = 1; k <= n; k++)
    {
        
        int now_point = ((n - k) / 2) + (k / 2);
        if (now_point > max_hosts)
        {
            max_hosts = now_point;
            num_lider = k;
        }
    }

   //viviod
    printf("\n------- Results -------\n");
    printf("Number of leader: %d\n", num_lider);
    printf("Counts wins of leader: %d\n", max_hosts);
    printf("Control checksum (analytical): %d\n", control_n);
    printf("Inner loop iterations (fact): %d\n", loop_count);

    system("pause");



    return 0;
}
