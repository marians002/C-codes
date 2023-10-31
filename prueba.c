#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    typedef struct proc_info {
    int pid;
    int executed_time;
    int on_io;
    } proc_info_t;

    proc_info_t p0 = {0, 0, 0};
    proc_info_t p1 = {1, 0, 0};
    proc_info_t p2 = {2, 0, 0};
    proc_info_t p3 = {3, 0, 0};
    proc_info_t p4 = {4, 0, 0};
    proc_info_t p5 = {5, 0, 0};
    proc_info_t p6 = {6, 0, 0};

    
    proc_info_t arrayP[] = {p0, p1, p2, p3, p4, p5, p6};    //proc_info
    proc_info_t arrayA[6];  //Cola A
    proc_info_t arrayB[6];  //Cola B


    pid = 5;

    proc_info_t get_current_process(proc_info_t *procs_info, int procs_count, int c_pid)
    {
        for (int i = 0; i<procs_count; i++)
        {
        if (procs_info[i].pid == c_pid)
            return procs_info[i];
        }
        proc_info_t error = {-1, -1, -1};
        return error;
    }

    int arraySize = 2;
    
    //declare 2D array and initialize it with array1 and array2
    proc_info_t *array[2] = {arrayA, arrayB};

    printf("%d", array[0][2].pid);
    
    // for (int i = 0; i<arraySize; i++)
    // {
    //     for (int j = 0; j<2; j++)
    //     {
    //         if  (array[i][j] == 7)
    //             printf("i: %d, j: %d \n", i, j);
    //     }
    // }
    
    printf("Fin\n");
    return 0;
}