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
