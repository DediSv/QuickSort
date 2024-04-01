#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector <int> CreateArray(){ //Creating a random massive
    srand (static_cast <unsigned int>(time(0))); //Seed
    vector <int> array(rand() % 13 + 1);
    for (int i = 0; i < array.size(); i++)
        array[i] = rand() % 100;
    return array;
}

void Vypis(vector <int> array){
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}

/*void QuickSort(vector <int> &array, int a, int n){ //a - begin, n - num of elements
    ///Partition the array(<p p >p)///
    if (a < n) { //Jeli array má vic než 1 element
        int left = a; //pointer on the start
        int right = n; // on the end
        int pivotIndex = rand() % (n - a + 1) + a; //vyber pivota
        int pivot = array[pivotIndex]; //remember the meaning of pivot
        swap(array[pivotIndex], array[right]); //swap pivot and the end
        for (int i = left; i < n; i++) {
            if (array[i] < pivot) {
                swap(array[i], array[a]);
                a++;
            }
        }
        swap(array[right], array[a]); //putting the pivot on his place
        QuickSort(array, left, a - 1);
        QuickSort(array, a + 1, right);
    }
}*/

void QuickSort(vector<int> &array, int a, int n){
    int p, i, j; //pivot, pointer leftSide, pointer rightSide
    if (a < n){
        p = array[a]; //pivot je hodnota zacatku pole
        i = a; //leftSide poiner is on the first index
        j = n; //rightSide pointer is on the last index
        while (i < j) {
            while (array[i] < p)
                i++;
            while (array[j] > p)
                j--;
            swap(array[i], array[j]);
        }
        QuickSort(array, a, i - 1);
        QuickSort(array, i + 1, n);
    }
}


int main() {
    vector <int> input = CreateArray();//Just gen the massive
    cout << "Random generated massive: " << endl;
    Vypis(input);
    ///Quick sort///
    cout << "Quck sorted massive: " << endl;
    QuickSort(input,0,input.size() - 1);
    Vypis(input);
    return 0;
}