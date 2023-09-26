#include <stdio.h>
#define size 100
#define np 4
int main()
{
    int n;
    printf("Enter the size of reference string: ");
    scanf("%d", &n);
    int s[100];
    printf("Enter the reference string: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    printf("\nPage \t Frame 1 \t Frame 2 \t Frame 3");
    int p[np];
    int hist[np];
    for(int i = 0; i < np; i++)
    {
        p[i] = -1;
        hist[i] = 0-i; // for making initial priority in filling the pages
    }
    int pagefaults = 0;
    int pagehits = 0;

    for(int i = 0; i < n; i++)
    {
        int currpage = s[i];
        int fl = 0;
        for(int j = 0; j < np; j++)
        {
            if(p[j] == currpage) // page hit
            {
                pagehits++;
                //reduce everyone's count except for p[i];
                for(int k = 0; k < np; k++)
                {
                    if(k == j) continue;
                    hist[k]--;
                }
                fl = 1;
                break;
            }
        }
        if(fl == 0)//page fault
        {
            pagefaults++;
            //find the one that was least recently used;
            int mn = 0;
            for(int j = 0; j < np; j++)
            {
                if(hist[j] < hist[mn]) mn = j;
            }

            p[mn] = currpage;
            hist[mn] = 0;
            for(int k = 0; k < np; k++)
            {
                if(k == mn)continue;
                hist[k]--;
            }
        }
    }

    printf("\nTotal Page faults : %d", pagefaults);
    printf("\nTotal Page hits : %d", pagehits);

    return 0;
}