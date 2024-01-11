//RICARDO DAVID LOPEZ ARELLANO

#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int c = 0,cost = 999;
int graph[4][4] = { {0, 10, 17, 15},
                    {20, 0, 19, 18},
                    {50, 44, 0, 25},
                    {45, 40, 20, 0}
                  };
void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void copy_array(int *a, int n)
{
    int i, sum = 0;
    for(i = 0; i <= n; i++)
    {
        sum += graph[a[i % 4]][a[(i + 1) % 4]];
    }
    if (cost > sum)
    {
        cost = sum;
    }
}  
void permute(int *a, int i, int n) 
{
   int j, k; 
   if (i == n)
   {
        copy_array(a, n);
   }
   else
   {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j));
        }
    }
} 
int main()
{
   int i, j;
   int a[] = {0, 1, 2, 3};  
   permute(a, 0, 3);
   cout<<"\n\t < ALGORITMO DE SALESMAN >"<<endl<<endl;
   cout<<"La matriz a resolver es la siguiente: \n";
   cout<<"  PINTURAS:  B|  A|  N|  R|\n";
   cout<<"    BLANCO:  0| 10| 17| 15|\n";
   cout<<"  AMARILLO: 20|  0| 19| 18|\n";
   cout<<"     NEGRO: 50| 44|  0| 25|\n";
   cout<<"      ROJO: 45| 40| 20|  0|\n"<<endl;
   cout<<"La ruta mas corta es: "<<cost<<endl;
   system("pause");
}
