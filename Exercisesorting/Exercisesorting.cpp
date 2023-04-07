//1.Algoritma dibutuhkan untuk menyelesaikan suatu masalah karena algoritma dapat mempermudah dalam memecahkan suatu masalah dengan bertahap dengan menguraikan masalah menjadi tugas yang lebih kecil
//2.Dua struktur data yaitu static (contoh : array) serta dinamic (linked list)
//3.faktor yang mempengaruhi efeseiensi waktu : Speed of the machine,compiler,operating system,programing language,inpput data
//4.Algoritma quick sort : karena lebih mudah dalam mengurutkan data dengan cara data diubah dalam dua  bagian sehingga mudah dalam menyelsaikannya
//5.Algoritma quadratic : Bubble sort,Selection sort,Insertion sort. Algoritma Loglinear : Merge sort, Quick sort

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& fahri, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> left_fahri(n1);
    vector<int> right_fahri(n2);

    for (int i = 0; i < n1; i++)
        left_fahri[i] = fahri[left + i];
    for (int j = 0; j < n2; j++)
        right_fahri[j] = fahri[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (left_fahri[i] <= right_fahri[j]) {
            fahri[k] = left_fahri[i];
            i++;
        }
        else {
            fahri[k] = right_fahri[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        fahri[k] = left_fahri[i];
        i++;
        k++;
    }

    while (j < n2) {
        fahri[k] = right_fahri[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& fahri, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(fahri, left, mid);
        merge_sort(fahri, mid + 1, right);

        merge(fahri, left, mid, right);
    }
}

void print_vector(vector<int>& fahri)
{
    for (int i = 0; i < fahri.size(); i++)
        cout << fahri[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> fahri = { 1, 5, 8, 11, 14, 17, 21, 24, 28, 31, 34, 37, 40, 43, 46, 50, 53, 57, 60, 63, 67, 70, 74, 77, 81, 84, 87, 90, 93, 97, 100, 103, 107, 110, 114, 117, 120, 123, 126, 129, 132, 136, 139, 142, 146, 149, 153, 156, 160, 163, 167, 171, 174, 178, 182, 186, 189, 193, 197, 201, 205, 209, 213, 217, 221, 225, 229, 233, 237, 241, 245, 249, 253, 257, 261, 265, 269, 273, 277, 281, 285, 289, 293, 297, 301, 306, 310, 314, 318, 322, 326, 330, 335, 339, 343, 347, 351, 356, 360, 364, 369, 373, 377, 382, 386, 390, 395, 399, 404, 408, 412, 417, 421, 426, 430, 435, 439, 444, 448, 453, 457, 462 };
    int n = fahri.size();

    cout << "Array sebelum diurutkan: ";
    print_vector(fahri);

    merge_sort(fahri, 0, n - 1);

    cout << "Array setelah diurutkan: ";
    print_vector(fahri);

    return 0;
}