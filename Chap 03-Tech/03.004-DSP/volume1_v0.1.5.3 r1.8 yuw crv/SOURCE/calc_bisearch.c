/***************************************************************************/
/*                                                                         */
/*     alg_bisearch.c                                                     */
/*                                                                         */
/*     Audio gain processing in a main loop                                */
/*                                                                         */
/***************************************************************************/

/*------------ include files -----------------------------------------------*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "calc_bisearch.h" 

/*------------ MACRO define -----------------------------------------------*/
/*------------ value define -----------------------------------------------*/
/*------------ Functions define -------------------------------------------*/
void Alg_Bisearch(void); 

void quicksort(int[], int, int); 
int  bisearch(int[], int); 

/*
 * ============================================================================
 *
 * FUNCTION: quicksort.
 *
 * PARAMETERS: xxx.
 *
 * RETURN VALUE: xxx.
 * ============================================================================
 */
void Alg_Bisearch(void) 
{ 
    int number[MAX] = {0}; 
    int i = 0;
    int find = 60;						/***/

    static unsigned int testcnt = 0;
    unsigned int delay = 0;
     
    srand(time(NULL)); 

    for(i = 0; i < MAX; i++) 
    { 
        number[i] = rand() % 100; 
    } 

	if (testcnt < 100)
	{
		testcnt ++;
	}
	else
	{
		testcnt = 0;
	}
    
    if (testcnt%2 == 1)
	{
	    number[0] = find;					/***/
	}

    printf("\n============ start ============");
    printf("\n����_raw��");
    for(i = 0; i < MAX; i++)
    {
        printf("%d ", number[i]); 
    } 

    quicksort(number, 0, MAX-1); 

    printf("\n����sort��");
    for(i = 0; i < MAX; i++)
    {
        printf("%d ", number[i]); 
    } 

    printf("\n����Ѱ�Ҷ���"); 
    scanf("%d", &find); 

    if((i = bisearch(number, find)) >= 0)
    {
        printf("�ҵ����������� %d ", i); 
    } 
    else 
    {
        printf("\n�Ҳ���ָ����"); 
    } 
    
    printf("\n============  end ============");
    printf("\n"); 

    while (delay < 10000)
    {
	    delay ++;

    } /*while*/
} 

/*
 * ============================================================================
 *
 * FUNCTION: quicksort.
 *
 * PARAMETERS: xxx.
 *
 * RETURN VALUE: xxx.
 * ============================================================================
 */
int bisearch(int number[], int find) 
{ 
    int low, mid, upper; 

    low = 0; 
    upper = MAX - 1; 

    while(low <= upper) 
    { 
        mid = (low+upper) / 2; 
        if(number[mid] < find) 
        {    low = mid+1; 			}
        else if(number[mid] > find) 
        {    upper = mid - 1; 		}
        else 
        {    return mid; 			}
    } 

    return -1; 
} 

/*
 * ============================================================================
 *
 * FUNCTION: quicksort.
 *
 * PARAMETERS: xxx.
 *
 * RETURN VALUE: xxx.
 * ============================================================================
 */
void quicksort(int number[], int left, int right) 
{ 
    int i, j, k, s; 

	k = (left+right)/2;

    if(left < right) 
    { 
        s = number[(left+right)/2]; 
        i = left - 1; 
        j = right + 1; 

        while(1) 
        { 
            while(number[++i] < s) ;  // ������ 
            while(number[--j] > s) ;  // ������ 
            if(i >= j) 
                break; 
            SWAP(number[i], number[j]); 
        } 

        quicksort(number, left, i-1);   // ����߽��еݻ� 
        quicksort(number, j+1, right);  // ���ұ߽��еݻ� 
    } 
} 

 /* ===========================================================================
 		file end
 ============================================================================*/

