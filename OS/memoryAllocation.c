#include <stdio.h>

void printResult(int processes, int blocks, int processSize[], int allocation[], int blockSize[]){
    printf("Process\tSize\tBlock no\n");

    for (int i = 0; i < processes; i++)
    {
        printf("P%d\t%d\t", i + 1, processSize[i]);

        if (allocation[i] != -1)
        {
            printf("%d\n", allocation[i]+1);
        }
        else{
            printf("Not allocated\n");
        }
    }

    printf("Remaining Block sizes : \n");


    for (int i = 0; i < blocks; i++)
    {
        printf("%d\t%d\n", i + 1, blockSize[i]);
    }
    
}

void firstFit(int processes, int blocks, int processSize[], int blockSize[]){
    int allocation[processes]; // store to which block allocated

    for (int i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }
    

    for (int i = 0; i < processes; i++)
    {      // for each process start from first block always
        for (int j = 0; j < blocks; j++)
        { // if block size is greater then allocate it to process
            if (blockSize[j] >= processSize[i]){
                allocation[i] = j;

                blockSize[j] -= processSize[i];
                break; // imp to break when allocated
            }
        }        
    }
    printResult(processes, blocks, processSize, allocation, blockSize);
}


void nextFit(int processes, int blocks, int processSize[], int blockSize[]){
    int allocation[processes];
    for (int i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }

    int j = 0;

    for (int i = 0; i < processes; i++)
    {
        int count = 0;

        while (count < blocks)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;

                blockSize[j] -= processSize[i];
                break;
            }

            j = (j + 1) % blocks;
            count += 1;
        } 
    }

    printResult(processes, blocks, processSize, allocation, blockSize);
}


void bestFit(int processes, int blocks, int processSize[], int blockSize[]){
    int allocation[processes];
    for (int i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }

// for each process find smallest sufficient block
    for (int i = 0; i < processes; i++)
    {
        int bestindex = -1;

        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestindex == -1)
                {
                    bestindex = j;
                }
                else if (blockSize[bestindex] > blockSize[j])
                {
                    bestindex = j;
                }                
            }
        }

        if (bestindex != -1)
        {
            allocation[i] = bestindex;

            blockSize[bestindex] -= processSize[i];
        }
        
        
    }

    printResult(processes, blocks, processSize, allocation, blockSize);
}


void worstFit(int processes, int blocks, int processSize[], int blockSize[]){
    int allocation[processes];
    for (int i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }

// for each process find largest sufficient block
    for (int i = 0; i < processes; i++)
    {
        int worstindex = -1;

        for (int j = 0; j < blocks; j++)
        {   
            if (blockSize[j] >= processSize[i])
            {
                if (worstindex == -1)
                {
                    worstindex = j;
                }
                else if (blockSize[worstindex] < blockSize[j])
                {
                    worstindex = j;
                }                
            }
        }

        if (worstindex != -1)
        {
            allocation[i] = worstindex;

            blockSize[worstindex] -= processSize[i];
        }
        
        
    }

    printResult(processes, blocks, processSize, allocation, blockSize);
}

int main(){

    int processes = 4;
    int blocks = 5;
    int processSize[] = {212, 417, 112, 426};
    int blockSize[] = {100, 500, 200, 300, 600};
     int blockSize1[blocks];
    for (int i = 0; i < blocks; i++)
    {
       blockSize1[i] = blockSize[i];
    }
     int blockSize2[blocks];
    for (int i = 0; i < blocks; i++)
    {
       blockSize2[i] = blockSize[i];
    }
     int blockSize3[blocks];
    for (int i = 0; i < blocks; i++)
    {
       blockSize3[i] = blockSize[i];
    }

    printf("------First Fit------\n");
    firstFit(processes, blocks, processSize, blockSize);
    printf("---------------------\n");

    printf("------Next fit--------\n");
    nextFit(processes, blocks, processSize, blockSize1);
        printf("---------------------\n");

    printf("------Best fit--------\n");
    bestFit(processes, blocks, processSize, blockSize2);
        printf("---------------------\n");

    printf("------Worst fit--------\n");
    worstFit(processes, blocks, processSize, blockSize3);
        printf("---------------------\n");


    return 0;
}
