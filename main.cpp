#include <iostream>
#include <time.h>

using namespace std;

void bubbleSort(int array[], int size) {  //BUBBLE SORT
    for (int step = 0; step < (size-1); ++step) {
        int swapped = 0;
        for (int i = 0; i < (size-step-1); ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                swapped = 1;
            }
        }
        if (swapped == 0)
        break;
    }
}

int binarySearch(int array[], int x, int low, int high) { //BINARY SEARCH
  if (high >= low) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);  //REKURSIF

    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

bool check(int x){
    if(x != 0 && x != 1 && x != 2 &&
       x != 3 && x != 4 && x != 5 &&
       x != 6 && x != 7 && x != 8 &&
       x != 9)
        return false;
    else{
        return true;
    }
}

int main()
{
    srand(time(NULL));

    char yn = 'y';

    while(yn == 'y'){

        int guess;       // inisiallisasi awal
        int arrSize = 5;
        int arr[arrSize];
        int maxNum = 10;

        bool used[maxNum] = {};

        for(int i=0; i<arrSize;){  //membuat random array
            int r = rand() % 10;
            if (!used[r-1]){
                arr[i++] = r;
                used[r-1] = true;
            }
        }

        bubbleSort(arr, arrSize); //sorting random array dengan bubblesort

        cout << "---------------------------" << endl;
        cout << "== Guessing  Number Game ==" << endl;
        cout << "==  There are 5 numbers  ==" << endl;
        cout << "==   guess 1 of them!    ==" << endl;
        cout << "==    they are 0 to 9    ==" << endl;
        cout << "---------------------------" << endl;
        cout << "== [ x | x | x | x | x ] ==" << endl;
        cout << "---------------------------" << endl;

        do{
            cout << "Your guess : ";
            cin  >> guess;
        }while(check(guess) == false);   //make sure user inputting number from 0 to 9

        cout << "---------------------------" << endl;

        int result = binarySearch(arr, guess, 0, arrSize - 1);  //searching if guess is the right answer
        if (result == -1){
            cout << "==     Wrong Answer!     ==" << endl;
        }else{
            printf("==   Found at index %d    ==\n", result);
            cout << "==    Great! You WIN!    ==" << endl;
        }

        cout << "== [";  //print the array
        for(int n=0;n<arrSize;n++){
            cout<<" ";
            cout << arr[n] << " ";   //print angka if its the right guess

            if(n < arrSize-1){
                cout << "|";
            }
        }

        cout << "] ==" <<endl;
        cout << "---------------------------" << endl;

        do{
            cout << "Do you wanna try again? (y/n) \n: "; //repeat
            cin >> yn;
        }while(yn != 'y' && yn != 'n');

        system("cls");

    }

    return 0;
}
