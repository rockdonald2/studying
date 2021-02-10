#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,tomb[50],maximum,k,q;
    ifstream f;
    f.open("../egyeb/beolvasas.txt");
    ofstream g;
    g.open("../egyeb/kiir.txt");
    f>>n;

    for(int i=1;i<=n;i++)
    {
        f>>tomb[i];
    }

    maximum=tomb[1];
    for(int i=2;i<=n;i++)
    {
        if(maximum<tomb[i])
        {
            maximum=tomb[i];
        }
    }

    k=maximum;
    int *segedtomb = new int[k + 1];

    for(int i=1;i<=k;i++)
    {
        segedtomb[i]=0;
    }
    for(int j=1;j<=n;j++)
    {
        segedtomb[tomb[j]]++;
    }

    q=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=segedtomb[i];j++)
        {
            q++;
            tomb[q]=i;
        }
    }

    for(int i=1;i<=n;i++)
    {
        g<<tomb[i]<<endl;
    }

    return 0;
}

