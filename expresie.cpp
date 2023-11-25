#include <fstream>
using namespace std;
int main()
{
	ifstream citeste("expresie.in");
	int N; citeste >> N;
	long long v[N], suma = 0;
	for (int i = 0; i < N; i++)
	{
		citeste >> v[i];
		suma += v[i];
	}
	citeste.close();
	long long sumaMaxima = suma;
	for (int i = 2; i < N; i++)
	{
		long long
			sumaTriplet = v[i-2]
					+ v[i-1]
					+ v[i],
			produsTriplet = v[i-2]
					* v[i-1]
					* v[i],
			sumaPartiala = suma
					- sumaTriplet
					+ produsTriplet;
		if (sumaPartiala > sumaMaxima)
		{
			sumaMaxima = sumaPartiala;
		}
	}
	for (int i = 1; i < N-2; i++)
	{
		long long
			sumaPereche1 = v[i] + v[i-1],
			produsPereche1 = v[i] * v[i-1];
		for (int j = i+2; j < N; j++)
		{
			long long
				sumaPereche2 = v[j] + v[j-1],
				produsPereche2 = v[j] * v[j-1],
				sumaPartiala = suma
						- sumaPereche1
						- sumaPereche2
						+ produsPereche1
						+ produsPereche2;
			if (sumaPartiala > sumaMaxima)
			{
				sumaMaxima = sumaPartiala;
			}
		}
	}
	ofstream scrie("expresie.out");
	scrie << sumaMaxima;
	scrie.close();
	return 0;
}

