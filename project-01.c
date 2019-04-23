#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int N,Q, *T,*S,qi,*qa,i;
    int time=0;
    int temp;
    printf("enter you N number:");
    scanf("%d",&N);

    scanf("%d",&Q);
    printf("enter you time of N number:");

    qa=(int *)malloc(sizeof(int)*Q);

    T=(int *)malloc(sizeof(int)*N);
    S=(int *)malloc(sizeof(int)*N);
    for(i=0;i<N;i++)
    {

        scanf("%d",T+i);
    }
    for(i=0;i<N;i++)
    {
        scanf("%d",S+i);
    }
    for(qi=0;qi<Q;qi++)
    {
        scanf("%d",qa+qi);
    }
    mergeSort(T,0,N-1);
    mergeSort(S,0,N-1);

    for(qi=0;qi<Q;qi++)
    {
        temp=qa[qi];

        for(i=0;i<temp;i++)
        {
            time=time+T[N-i-1];

        }
        //printf("time requried");
        printf("%d\n",time );

        time=0;

    }
  return 0;
}
