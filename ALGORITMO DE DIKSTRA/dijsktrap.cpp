//LOPEZ ARELLANO RICARDO DAVID

#include <iostream>
#include <limits.h>
#define max 5

using namespace std;

int matrix[max][max] = {//lo mencionado son los vertices
    // 1, 2, 3, 4, 5
/*1*/{ 0, 100, 30, 0, 0},
/*2*/{ 0, 0, 20, 0, 0},
/*3*/{ 0, 0, 0, 10, 60},
/*4*/{ 0, 15, 0, 0, 50},
/*5*/{ 0, 0, 0, 0, 0}
};

int origen = 0;
int distancia[max];
bool array[max] = { false, false, false, false, false };

int minimaDistancia(){
    int min = INT_MAX;
    int minIndex;
    for(int i = 0; i < max; i++){
        if(array[i] == false && distancia[i] <= min){
            min = distancia[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int mostrar (){
	cout << "\n\t < ALGORITMO DE DIJKSTRA >"<<endl<<endl;
    cout << "Distancia: " << endl;

    for(int i = 0; i < max; i++){
        cout << "Nodo:" << i << " Distancia: " << distancia[i] << endl;
    }
}

void dijkstra(){
    for(int i = 0; i < max; i++){
        distancia[i] = INT_MAX;
        distancia[origen] = 0;
    }

    for(int i = 0; i < max-1; i++){
        int u = minimaDistancia();
        array[u] = true;

        for(int j = 0; j < max; j++){
            if(!array[j] && matrix[u][j] && distancia[u] != INT_MAX && distancia[u] + matrix[u][j] < distancia[j]){
                distancia[j] = distancia[u] + matrix[u][j];
            }
        }
    }

    mostrar();

}

int main(int argc, char const *argv[])
{
    dijkstra();

    return 0;
}
