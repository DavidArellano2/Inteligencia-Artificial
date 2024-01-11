//LOPEZ ARELLANO RICARDO DAVID 
//ALGORITMO DE KRUSKAL

#include <stdio.h>
#include <algorithm>
#include <cstring>
#define MAX 100  //VERTICES MAXIMOS

int padre[ MAX ]; //Este arreglo contiene el padre del ultimo nodo

//Método de inicialización
void hacer_raiz( int n ){
    for( int i = 1 ; i <= n ; ++i ) padre[ i ] = i;
}

//Método para encontrar la raiz del vértice actual
int buscar_raiz( int x ){
    return ( x == padre[ x ] ) ? x : padre[ x ] = buscar_raiz( padre[ x ] );
}

//Método para unir 2 vertices
void Union( int x , int y ){
    padre[ buscar_raiz( x ) ] = buscar_raiz( y );
}

//Método que me determina si 2 vértices estan o no en la misma componente conexa
bool vertices_conexos( int x , int y ){
    if( buscar_raiz( x ) == buscar_raiz( y ) ) return true;
    return false;
}

int V , A;//numero de vertices y aristas

struct Estructura_Arista{
    int origen;     //Vértice origen
    int destino;    //Vértice destino
    int peso;       //Peso entre el vértice origen y destino
    Estructura_Arista(){}
    bool operator<( const Estructura_Arista &e ) const {
        return peso < e.peso;
    }
}arista[ MAX ];//Arreglo de aristas 
Estructura_Arista MST[ MAX ];     //Arreglo de aristas del MST encontrado

void Kruskal(){
    int origen , destino , peso;
    int total = 0;          //Peso total
    int numAristas = 0;     //Numero de Aristas

    hacer_raiz( V );           //Inicializamos cada componente
    std::sort( arista , arista + A );    //Ordenamos las aristas por su comparador

    for( int i = 0 ; i < A ; ++i ){     //Recorremos las aristas ya ordenadas por peso
        origen = arista[ i ].origen;    //Vértice origen de la arista actual
        destino = arista[ i ].destino;  //Vértice destino de la arista actual
        peso = arista[ i ].peso;        //Peso de la arista actual

        //Verificamos si estan o no en la misma componente conexa
        if( !vertices_conexos( origen , destino ) ){  //Evitar ciclos
            total += peso;              //Incrementa el peso total del MST
            MST[ numAristas++ ] = arista[ i ];  //Agregar al MST la arista actual
            Union( origen , destino );  //Union de ambas componentes en una sola
        }
    }

    if( V - 1 != numAristas ){     //Si el MST encontrado no posee todos los vértices mostramos mensaje de error
        puts("No existe MST (ARBOL DE EXPANSION MINIMO) valido para el grafo ingresado,\nEl grafo debe ser conexo...");
        return;
    }
    puts( "\n\t< El MST (ARBOL DE EXPANSION MINIMO) \n\tencontrado contiene las siguientes aristas >");
    printf("\nVertice origen|Vertice destino|Peso arista: \n");
    for( int i = 0 ; i < numAristas ; ++i )
        printf("( \t%d \t-->\t%d )   =\t %d\n" , MST[ i ].origen , MST[ i ].destino , MST[ i ].peso ); //( vertice u , vertice v ) : peso
    printf( "\nEl costo minimo de todas las aristas del MST es : %d\n" , total );
}

int main(){
    int mst;
    printf("\n\t\t < ALGORITMO DE KRUSKAL >\n\n");
	printf("Ingresa el numero de vertices: ");
    scanf("%d", &V);
	printf("Ingresa el numero de aristas: ");
    scanf("%d",&A );
    printf("\nIngresa el vertice origen, despues el vertice destino y\nal final el peso de la arista: \n");
	for( int i = 0 ; i < A ; ++i )
        scanf("%d %d %d" , &arista[ i ].origen , &arista[ i ].destino , &arista[ i ].peso );

    Kruskal();
    return 0;
}
