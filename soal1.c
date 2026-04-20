/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 – Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Muhammad Aqeel Ghani (13224071)
 *   Nama File           : soal1.c
 *   Deskripsi           : Memulihakan elemen array yang hilang lalu cari jumlah subarray maksimum
 * 
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 
 int MAX_SUM(int *Arr, int N){ // Fungsi mencari max sum
    int sum=0, negativeAll=1;
    for (int i=0; i<N; i++){
        if (Arr[i]>0){
            sum += Arr[i];
            negativeAll = 0;
        }
    }

    if (negativeAll){
        for (int i=0; i<N; i++){
            if (sum==0) sum = Arr[i];
            else if (sum<Arr[i] && Arr[i]!=0) sum = Arr[i];
        }
    }

    return sum;
 }

 void Recovered(int *Arr, int N){ //Fungsi merecovered Array
    for (int i = 0; i<N; i++){
        int kiri=-1, kanan=-1;
        if (Arr[i] == -1){
            for(int j = i-1; j>=0; j--){
                if (Arr[j]!=-1){
                    kiri = Arr[j];
                    break;
                }
            }
            for (int j = i+1; j<N; j++){
                if (Arr[j]!=-1){
                    kanan = Arr[j];
                    break;
                }
            }
            if (kiri!=-1 && kanan!=-1) Arr[i] = floor((kiri+kanan)/2.0);
            else if (kiri!=-1) Arr[i] = kiri;
            else if (kanan!=-1) Arr[i] = kanan;
            else Arr[i] = 0;
        }
    }
 }

 int main() {
    int N, maxSum;

    scanf("%d", &N);

    int *Arr = (int*)malloc(sizeof(int)*N);

    for(int i = 0; i<N; i++) scanf(" %d", &Arr[i]);

    Recovered(Arr, N);

    maxSum = MAX_SUM(Arr, N);

    printf("\nRECOVERED");
    
    for(int i = 0; i<N; i++) printf(" %d", Arr[i]);

    printf("\nMAX_SUM %d\n", maxSum);

    free(Arr);
    Arr = NULL;
    return 0;
 }

//  Referensi
// https://www.geeksforgeeks.org/c/dynamic-array-in-c/
 