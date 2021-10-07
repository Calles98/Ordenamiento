#include <iostream>
#include <cstdlib>
//#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std; 

void insertionSort(int arr[], int tam);
void selectionSort(int arr[], int tam); 
void merge(int a[], int l, int m, int r) ;
void mergeSort(int a[], int l, int r) ;
void intercambio(int *a, int *b);
void imprimirArreglo(int arr[], int tam);
void mejorCasoInsertion(int n); 
void peorCasoInsertion(int n); 
void casoPromedioInsertion(int n); 
void mejorCasoSelection(int n); 
void peorCasoSelection(int n); 
void casoPromedioSelection(int n); 
void mejorCasoMerge(int n); 
void peorCasoMerge(int n);
void casoPromedioMerge(int n); 


// función de intercambio 
void intercambio(int *a, int *b){
    int n = *a; 
    *a = *b; 
    *b = n; 
}

void imprimirArreglo(int arr[], int tam){
    for (int i = 0; i < tam; ++i){
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

// ************************************************* ALGORITMOS DE ORDENAMIENTO *************************************************

void insertionSort(int arr[], int tam){
    int ind; 
    for (int i = 1; i < tam; ++i){
        ind = arr[i];
        int j = i - 1;

        while (ind < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j = j - 1;
        }  
        arr[j+1] = ind; 
    }
} 

void selectionSort(int arr[], int tam){
    
    for (int i = 0; i < tam-1; ++i){
        int j_min = i;
        for (int j = i+1; j < tam; ++j){
            if (arr[j] < arr[j_min]){
                j_min = j;  
                
            }  
        }
        intercambio(&arr[j_min], &arr[i]); 
    } 
}

void merge(int a[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  

    int L[n1], R[n2]; 
  

    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
  
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
   
    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
 
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int a[], int l, int r) 
{ 
    if (l < r) 
    { 


        int m = l+(r-l)/2; 
  

        mergeSort(a, l, m); 
        mergeSort(a, m+1, r); 
  
        merge(a, l, m, r); 
    } 
}

// ************************************************* CASOS INSERTION SORT *************************************************


void mejorCasoInsertion(int n){
    int arr[n]; 
    
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);


   ios_base::sync_with_stdio(false);

    for (int i = 0; i < n; i++){
        arr[i] = i; 
    } 

    insertionSort(arr, n);

    gettimeofday(&fin, NULL);

    double tiempo;

    tiempo = (fin.tv_sec - inicio.tv_sec) * 1e6;
    tiempo = (tiempo + (fin.tv_usec -
                              inicio.tv_usec)) * 1e-6;


    cout << "Mejor caso de Insertion Sort con " << n << " elementos duró: " << tiempo << " segundos" << endl;   
}

void peorCasoInsertion(int n){
    int arr[n]; 
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);


   ios_base::sync_with_stdio(false);


    for (int i = 0; i < n; ++i){
        arr[i] = n-i; 
    }

    insertionSort(arr, n); 

    gettimeofday(&fin, NULL);


    double tiempo;

    tiempo = (fin.tv_sec - inicio.tv_sec) * 1e6;
    tiempo = (tiempo + (fin.tv_usec -
                              inicio.tv_usec)) * 1e-6;


    cout << "peor caso de Insertion Sort con " << n << " elementos duró: " << tiempo << " segundos" << endl;  
    
}

void casoPromedioInsertion(int n){
    int arr[n]; 
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);


   ios_base::sync_with_stdio(false);

    for (int i = 0; i < n; i++){
        arr[i] = rand()%n; 
         
    }

    insertionSort(arr, n); 

    gettimeofday(&fin, NULL);


    double tiempo;

    tiempo = (fin.tv_sec - inicio.tv_sec) * 1e6;
    tiempo = (tiempo + (fin.tv_usec -
                              inicio.tv_usec)) * 1e-6;


    cout << "Caso promedio de Insertion Sort con " << n << " elementos duró: " << tiempo << " segundos" << endl;  

}
// ************************************************* CASOS SELECTION SORT *************************************************

void mejorCasoSelection(int n){
   int arr[n]; 
    
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);


   ios_base::sync_with_stdio(false);

    for (int i = 0; i < n; i++){
        arr[i] = i; 
    } 

    selectionSort(arr, n);

    gettimeofday(&fin, NULL);

   double tiempo;

    tiempo = (fin.tv_sec - inicio.tv_sec) * 1e6;
    tiempo = (tiempo + (fin.tv_usec -
                              inicio.tv_usec)) * 1e-6;

    cout << "Mejor caso de Selection Sort con " << n << " elementos duró: " << tiempo << " segundos" << endl;   
}


void peorCasoSelection(int n){
    int arr[n]; 
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);


   ios_base::sync_with_stdio(false);


    for (int i = 0; i < n; ++i){
        arr[i] = n-i; 
    }

    selectionSort(arr, n); 

    gettimeofday(&fin, NULL);

    double tiempo;

    tiempo = (fin.tv_sec - inicio.tv_sec) * 1e6;
    tiempo = (tiempo + (fin.tv_usec -
                              inicio.tv_usec)) * 1e-6;


    cout << "peor caso de Selection Sort con " << n << " elementos duró: " << tiempo << " segundos" << endl;  
}

void casoPromedioSelection(int n){
    int arr[n]; 
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);


   ios_base::sync_with_stdio(false);

    for (int i = 0; i < n; i++){
        arr[i] = rand()%n; 
         
    }

    insertionSort(arr, n); 

    gettimeofday(&fin, NULL);

    double tiempo;

    tiempo = (fin.tv_sec - inicio.tv_sec) * 1e6;
    tiempo = (tiempo + (fin.tv_usec -
                              inicio.tv_usec)) * 1e-6;

    cout << "Caso promedio de Insertion Sort con " << n << " elementos duró: " << tiempo << " segundos" << endl;  

}

// ************************************************* CASOS MERGE SORT *************************************************


void mejorCasoMerge(int n){
    int arr[n]; 
    
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);


   ios_base::sync_with_stdio(false);

    for (int i = 0; i < n; i++){
        arr[i] = i; 
    } 

    mergeSort(arr, 0, n-1);

    gettimeofday(&fin, NULL);

    double tiempo;

    tiempo = (fin.tv_sec - inicio.tv_sec) * 1e6;
    tiempo = (tiempo + (fin.tv_usec -
                              inicio.tv_usec)) * 1e-6;


    cout << "Mejor caso de Merge Sort con " << n << " elementos duró: " << tiempo << " segundos" << endl;   

}

void peorCasoMerge(int n){
    int arr[n]; 
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);


   ios_base::sync_with_stdio(false);


    for (int i = 0; i < n; ++i){
        arr[i] = n-i; 
    }

    mergeSort(arr,0,n-1); 

    gettimeofday(&fin, NULL);

    double tiempo;

    tiempo = (fin.tv_sec - inicio.tv_sec) * 1e6;
    tiempo = (tiempo + (fin.tv_usec -
                              inicio.tv_usec)) * 1e-6;


    cout << "peor caso de Merge Sort con " << n << " elementos duró: " << tiempo << " segundos" << endl;  
} 


void casoPromedioMerge(int n){
    int arr[n]; 
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);


   ios_base::sync_with_stdio(false);

    for (int i = 0; i < n; i++){
        arr[i] = rand()%n; 
         
    }

    mergeSort(arr, 0,n-1); 

    gettimeofday(&fin, NULL);

    double tiempo;

    tiempo = (fin.tv_sec - inicio.tv_sec) * 1e6;
    tiempo = (tiempo + (fin.tv_usec -
                              inicio.tv_usec)) * 1e-6;


    cout << "Caso promedio de Merge Sort con " << n << " elementos duró: " << tiempo << " segundos" << endl;  
}

// ************************************************* MAIN *************************************************


int main()
{
    int n[10] = { 10000,20000,30000,40000,50000,60000,70000,80000,90000,100000 };
    
    srand(time(NULL)); 

    cout << "Mejor caso Insertion Sort" << endl << endl; 

    for (int i = 0; i < 10; ++i){
        mejorCasoInsertion(n[i]); 
    }

    cout << "Caso promedio Insertion Sort" << endl << endl; 

    for (int i = 0; i < 10; ++i){
        casoPromedioInsertion(n[i]); 
    }

    cout << "Peor caso Insertion Sort" << endl << endl; 

    for (int i = 0; i < 10; ++i){
        peorCasoInsertion(n[i]); 
    }

    cout << "************************************************************************************" << endl << endl; 

    cout << "Mejor caso Selection Sort" << endl << endl; 

    for (int i = 0; i < 10; ++i){
        mejorCasoSelection(n[i]); 
    }

    cout << "Caso promedio Selection Sort" << endl << endl; 

    for (int i = 0; i < 10; ++i){
        casoPromedioSelection(n[i]); 
    }

    cout << "Peor caso Selection Sort" << endl << endl; 

    for (int i = 0; i < 10; ++i){
        peorCasoSelection(n[i]); 
    }

    cout << "***********************************************************************************" << endl << endl; 

    cout << "Mejor caso Merge Sort" << endl << endl; 

    for (int i = 0; i < 10; ++i){
        mejorCasoMerge(n[i]); 
    }

    cout << "Caso promedio Merge Sort" << endl << endl; 

    for (int i = 0; i < 10; ++i){
        casoPromedioMerge(n[i]); 
    }

    cout << "Peor caso Merge Sort" << endl << endl; 

    for (int i = 0; i < 10; ++i){
        peorCasoMerge(n[i]); 
    }
 
    return 0;
}