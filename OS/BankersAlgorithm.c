#include<stdio.h>

int main(){
    int processes = 5;
    int resources = 3;
    int need[5][3], executed[processes], safe_sequence[processes];
    int index = 0;
    int available[] = {3,3,2};

    int allocation[5][3] = {
        0, 1, 0,
        2, 0, 0,
        3, 0, 2,
        2, 1, 1,
        0, 0, 2
    };

    int max[5][3] = {
        7, 5, 3,
        3, 2, 2,
        9, 0, 2,
        2, 2, 2,
        4, 3, 3
    };

    printf("Enter no of processes : %d\n" , processes);
    printf("Enter no of resources : %d\n", resources);

    printf("Enter allocation matrix : \n");
    for (int i = 0; i < processes; i++)
    {
        printf("\nP[%d] : ", i);
        for (int j = 0; j < resources; j++)
        {
            printf("%d ", allocation[i][j]);
        }
        
    }


    printf("Enter max matrix : \n");
    for (int i = 0; i < processes; i++)
    {
        printf("\nP[%d] : ", i);
        for (int j = 0; j < resources; j++)
        {
            printf("%d ", max[i][j]);
        }
    }

    printf("\nEnter available resources : ");
    for (int i = 0; i < resources; i++)
    {
        printf("%d ", available[i]);
    }
    

    // calculate need matrix

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nNeed matrix : ");
     for (int i = 0; i < processes; i++)
    {
        printf("\nP[%d] : ", i);
        for (int j = 0; j < resources; j++)
        {
            printf("%d ", need[i][j]);
        }
    }

    // safety algorithm

    // set all executed to 0
    for (int i = 0; i < processes; i++)
    {
        executed[i] = 0;
    }

    // check for 5 items not optimized but working approach

    for (int k = 0; k < 5; k++)
    {
            // check for all processes that need <= available
        for (int i = 0; i < processes; i++)
        {
            // check that process is executed or not 
            if (executed[i] == 0)
            {
                int flag = 0;

                // check need <= available
                for (int j = 0; j < resources; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    executed[i] = 1;
                    safe_sequence[index++] = i;

                    // update available
                    for (int y = 0; y < resources; y++)
                    {
                        available[y] += allocation[i][y];
                    }
                    
                }
                
                
            }
            
        }       
    }

    int flag = 1;


    // check all processes are exectuted or not
    for (int i = 0; i < processes; i++)
    {
        if (executed[i] == 0)
        {
            flag = 0;
            printf("\n---------------------------\n");
            printf("The following system is not safe");
            printf("\n---------------------------\n");
            break;
        }
        
    }

    if (flag == 1)
    {
        printf("\n-------------Safe sequenece------------\n");
        for (int i = 0; i < processes-1; i++)
        {
            printf("P%d ->", safe_sequence[i]);
        }
        printf("P%d", safe_sequence[processes-1]);
        }
    return 0;
}
