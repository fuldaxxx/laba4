#include <iostream>
#include <ctime>
#include <locale>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    int m, n;
    cout << "Введите колличество строк: ";
    cin >> m;
    cout << "Введите количество столбцов: ";
    cin >> n;

    map <int, int> mp;

    float** arr = new float* [m];
    for (int i(0); i < m; i++) 
        arr[i] = new float[n];



    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 3;
        }
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
    
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
           
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < n; l++) {
                    if (arr[i][j] == arr[k][l]) {
                        count += 1;
                        
                    }
                }
            }
            mp.insert(make_pair(arr[i][j], count));
            count = 0;
        }
    }

    map <int, int> ::iterator it = mp.begin();
    
    int maxIndex = 0;
    int max = 0;
    int maxN = 0;
    for (int i = 0; it != mp.end(); it++, i++) {  
        if (it->second > max) {
            max = it->second;
            maxN = it->first;
        }
        int index = 0;
        if (it->second == max) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (it->first == arr[i][j]) {
                        index = i + j;
                    }
                }
            }
            if (index > maxIndex) {
                maxIndex = index;
            }
        }
       
        index = 0;
        cout << i << ") Элемент " << it->first << ", количество " << it->second << "  " << endl;
    }

    cout << "Максимальный элемент: "<< maxN << " значение: " << max << "  " << maxIndex;

    

    for (int i(0); i < m; i++) 
        delete arr[i];
    delete arr; 

    return 0;
}