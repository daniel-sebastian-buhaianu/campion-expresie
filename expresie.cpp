#include <fstream>
#define VALOARE_MAXIMA_N 1000
using namespace std;
int main()
{
	int N,
	    v[VALOARE_MAXIMA_N],
	    i,
	    celMaiMareProdus = 0,
	    alDoileaCelMaiMareProdus = 0,
	    pozitiePrimulTermenCelMaiMareProdus = 0,
	    pozitiePrimulTermenAlDoileaCelMaiMareProdus = 0;
	ifstream citeste("expresie.in");
	citeste >> N;
	citeste >> v[0];
	for (i = 1; i < N; i++)
	{
		citeste >> v[i];
		int produs = v[i]*v[i-1];
		if (produs > celMaiMareProdus)
		{
			alDoileaCelMaiMareProdus = celMaiMareProdus;
			pozitiePrimulTermenAlDoileaCelMaiMareProdus
				= pozitiePrimulTermenCelMaiMareProdus;
			celMaiMareProdus = produs;
			pozitiePrimulTermenCelMaiMareProdus = i-1;
		}
		else if (produs > alDoileaCelMaiMareProdus)
		{
			alDoileaCelMaiMareProdus = produs;
			pozitiePrimulTermenAlDoileaCelMaiMareProdus = i-1;
		}
	}
	citeste.close();
	int suma = 0;
	for (i = 0; i < N; i++)
	{
		if (i == pozitiePrimulTermenCelMaiMareProdus
		    || i == pozitiePrimulTermenAlDoileaCelMaiMareProdus)
		{
			if (i+1 == pozitiePrimulTermenCelMaiMareProdus
			    || i+1 == pozitiePrimulTermenAlDoileaCelMaiMareProdus)
			{
				suma += v[i]*v[i+1]*v[i+2];
				i += 2;
			}
			else
			{
				suma += v[i]*v[i+1];
				i++;
			}
		}
		else
		{
			suma += v[i];
		}
	}
	ofstream scrie("expresie.out");
	scrie << suma;
	scrie.close();
	return 0;
}
