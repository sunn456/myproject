#include <iostream> 
using namespace std; 
int fun_min(int[], int ); 
int fun_sum(int[], int ); 
int main() { 
 int arr[] = {-3,-6,43,-7,641,92, 0,2,-12,0,5}; 
 cout<< fun_min(arr, sizeof(arr)/sizeof(arr[0])); 
 cout  <<'\n' << fun_sum(arr, sizeof(arr) / sizeof(arr[0])); 
 
 return 0; 
} 
int fun_min(int arr_int[], int n) 
{ 
 int min = arr_int[0]; 
 for (size_t i = 1; i < n; i++) 
 { 
   
  if (abs(arr_int[i]) < min) 
  // поточний масив < за поточне мін
   min = abs(arr_int[i]); 
 } 
 return min; 
} 
int fun_sum(int arr_int[], int n) 
{ 
 int sum = 0; 
 bool not_null = false;
 // Вона буде використовуватися для визначення, чи був знайдений елемент масиву, який дорівнює нулю. 
 for (size_t i = 1; i < n; i++) 
 { 
  if (!arr_int[i])  
   not_null = true; 
  if (not_null) 
   sum = sum+ abs(arr_int[i]); 
 } 
 return sum; 
}