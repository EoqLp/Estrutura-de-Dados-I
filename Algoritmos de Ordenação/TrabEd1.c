/* 1º Trabalho de ED1 - UFRRJ
Comparação entre algoritmos de ordenação
Alunos: Felipe Rangel da Silva (201678013-2)
Lucas Morais Pereira da Silva (201678028-0)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int n, int *v){
	int fim, i;
	int temp, troca;
	for (fim=n-1; fim>0; fim--){
		troca = 0;
		for (i=0; i<fim; i++)
			if (v[i]>v[i+1]){
					temp = v[i]; /* troca */
					v[i] = v[i+1];
					v[i+1] = temp;
					troca = 1;
				}
		if (troca == 0) 
			return;			
	}
}

void selectSort(int n, int *v){
	int fim, i, maior;
	int aux;
	for (fim = n-1; fim>0; fim--)
	{
		maior=0;
		for(i=1;i<=fim;i++)
			if(v[i]>v[maior])
				maior=i;
		aux=v[fim];
		v[fim]=v[maior];
		v[maior]=aux;
	}
}

void quickSort(int *v, int inicio, int fim){
    int i, j, x, y;
     
    i = inicio;
    j = fim;
    x = v[(inicio + fim) / 2];
     
    while(i <= j) {
        while(v[i] < x && i < fim) {
            i++;
        }
        while(v[j] > x && j > inicio) {
            j--;
        }
        if(i <= j) {
            y = v[i];
            v[i] = v[j];
            v[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > inicio) {
        quickSort(v, inicio, j);
    }
    if(i < fim) {
        quickSort(v, i, fim);
    }
}

void insertSort(int n, int v[]){
   int i, key, j;
   for (i = 1; i < n; i++){
       key = v[i];
       j = i-1;
 		while (j >= 0 && v[j] > key){
           v[j+1] = v[j];
           j = j-1;
       }
       v[j+1] = key;
   }
}

int comparador(const void *valor1,const void *valor2){
	const int *numero1, *numero2;
	numero1=*(int *)valor1; 
	numero2=*(int *)valor2;
	if(numero1>numero2)
		return 1;
	else if (numero1<numero2)
		return -1;
	else
		return 0;
}

void mergeSort(int *v, int inicio, int fim){
   int i,j,k,metadeTamanho,*vetorTemp;
   if (inicio == fim ) return;
   
   // ordenacao recursiva das duas metades
   metadeTamanho = ( inicio+fim )/2;
   mergeSort( v, inicio, metadeTamanho);
   mergeSort( v, metadeTamanho+1,fim );

   // intercalacao no vetor temporario t
   i = inicio;
   j = metadeTamanho+1;
   k = 0;
   vetorTemp = (int *) malloc(sizeof(int) * (fim-inicio+1));
   
   while( i < metadeTamanho+1 || j  < fim+1 )
   { 
      if ( i == metadeTamanho+1 )
      { // i passou do final da primeira metade, pegar v[j]
         vetorTemp[k] = v[j];
         j++;
         k++;
      } 
      else
      {
         if (j==fim+1) 
         { 
            // j passou do final da segunda metade, pegar v[i]
            vetorTemp[k] = v[i];
            i++;
            k++;
         } 
         else 
         {
            if (v[i] < v[j]) 
            { 
               vetorTemp[k] = v[i];
               i++;
               k++;
            } 
            else
            { 
              vetorTemp[k] = v[j];
              j++;
              k++;
            }
         }
      }
      
   }
   // copia vetor intercalado para o vetor original
   for( i = inicio; i <= fim; i++ )
   {
      v[i] = vetorTemp[i-inicio];
   }
   free(vetorTemp);
}

int main(){
	int i, n;
	clock_t inicio, fim;
	double gasto;
	
	printf("Entre com o tamanho do vetor: ");

	scanf("%d", &n);

	printf("\n");
	
	int *v=(int*)malloc(sizeof(int)*n);
	int ordenado;
	
	printf("Ordenação: \n1- Vetor ordenado crescente\n2- Vetor aleatório\n3- Vetor ordenado decrescente\nEscolhido: ");
	scanf("%d", &ordenado);
	if(ordenado == 1){ //Gera vetor de inteiros ordenado de forma crescente de 0 até N-1.
		for(i=0; i<n; i++){
			v[i] = i;
		}
	}else if(ordenado == 2){ //Gera vetor de inteiros aleatório
		for(i=0; i<n; i++){
			v[i] = rand() % 100;
		}
	}else if(ordenado == 3){ //Gera vetor de inteiros ordenado de forma descescente de N até 1
		for(i=0; i<n; i++){
			v[i] = n-i;
		}
	}




	printf("\nAlgoritmo \n1- Bubble Sort\n2- Select Sort\n3- Quick Sort\n4- qsort\n5- Insert Sort\n6- Merge Sort\nEscolhido: ");
	
	int escolhe;
	
	scanf("%d", &escolhe);

	/*printf("\t\t\t VETOR DESORDENADO\n\n");
	for(i=0; i<n; i++){
		if(i<n-1)
			printf("%d - ", v[i]);
		else
			printf("%d\n", v[i]);
	}*/

	
	if(escolhe==1){
		inicio = clock();
		bubbleSort(n, v);
		fim = clock();
	}else if(escolhe==2){
		inicio = clock();
		selectSort(n, v);
		fim = clock();
	}else if(escolhe==3){
		inicio = clock();
		quickSort(v, 0, n);
		fim = clock();
	}else if(escolhe==4){
		inicio = clock();
		qsort(v, n, sizeof(int), comparador);
		fim = clock();
	}else if(escolhe==5){
		inicio = clock();
		insertSort(n, v);
		fim = clock();
	}else{
		inicio = clock();
		mergeSort(v, 0, n);
		fim = clock();
	}
	gasto = ((double)fim - inicio) / CLOCKS_PER_SEC;

	/*printf("\t\t\t VETOR ORDENADO\n\n");
	for(i=0; i<n; i++){
		if(i<n-1)
			printf("%d - ", v[i]);
		else
			printf("%d\n", v[i]);
	}*/

	printf("Tempo em segundos para entrada n=%d: %f", n, gasto);
	free(v);
	return 0;
}