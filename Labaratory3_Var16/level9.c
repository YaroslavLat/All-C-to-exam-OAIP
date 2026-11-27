#include <stdio.h>
#include <windows.h>

void level9() {
   int n = 0;
   
    int is_entered_correct = 0;
    do {
        printf("Enter person ot 2 do 30: ");
        if (scanf_s("%d", &n) != 1) 
        {
            while (getchar() != '\n');
            continue;
        }
        if (n >= 2 && n <= 30) {
            is_entered_correct = 1;
        }
        else {
            printf("Error!\n");
            is_entered_correct = 0;
        }
    } while (is_entered_correct != 1);

    int max_hosts = -1;
    int num_leader = 1;
   int loop_count = 0; 
   int control_n = (n * (n - 1)) / 2;

    for (int k = 1; k <= n; k++) {
        int current_hosts = 0;
        int remaining_matches = control_n;

        for (int i = 1; i <= n; i++) {
            int force_break = 0;
            for (int j = i + 1; j <= n; j++)
            {
                loop_count++;
                remaining_matches--;


                //ecli cht - to i boss
                if ((i + j) % 2 == 0)
                {
                    if (i == k)
                    {
                        current_hosts++;
                    }
                }
                else {
                    if (j == k)
                    {
                        current_hosts++;
                    }
                }


                if (current_hosts + remaining_matches < max_hosts) {
                    force_break = 1;
                    break;
                }
            }
            if (force_break == 1)
            {
                break;
            }
        }

        if (current_hosts > max_hosts) {
            max_hosts = current_hosts;
            num_leader = k;
        }
    }

    


    printf("\n------- Results -------\n");
    printf("Number of leader: %d\n", num_leader);
    printf("Counts wins of leader: %d\n", max_hosts);
    printf("Control checksum (analytical): %d\n", control_n);
    printf("Inner loop iterations (fact): %d\n", loop_count);

    system("pause");
   
}
