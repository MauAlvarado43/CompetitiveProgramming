
#include "stdafx.h"
class Solution
{
public:
	int mySqrt(int x)
	{
		// Para cuidar de 0, establezca el margen izquierdo en 0
		int low = 0;
		 // Para cuidar de 1, establezca el límite derecho ax / 2 + 1
		int high = x / 2 + 1;
		while (low < high)
		{
			 // Nota: Aquí se debe tomar la mediana de la derecha. Si se toma la mediana de la izquierda, el código puede entrar en un bucle sin fin
			 // largo largo medio = bajo + (alto-bajo + 1) / 2; cambiar a la derecha en 1 para realizar la división por 2, operación de bits, rápido
			 // long long mid, si se establece en int, los casos de prueba para enteros grandes no pasarán
			long long mid = (low + (high - low + 1))>>1;
			if (x == mid*mid)
			{
				return mid;
			}
			else if (x >= mid*mid)
			{
				low = mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		return low;
	}
};
 
int main()
{
	Solution s;
	auto result = s.mySqrt(1);
	return 0;
}