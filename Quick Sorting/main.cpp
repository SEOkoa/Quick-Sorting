#include <iostream>
#include <unistd.h>
using namespace std;

int input[1000] = {0};

int i, j = 0; // i = 숫자의 총 갯수 // j= 출력할 숫자의 위치
int cnt = 0; // while문 안에서 해당 배열에 저장된 값 만큼 그래프 문자를 출력하고 초기화 하는걸 담당함.

int start, pivot = 0;
int k, l = 0;
int tmp = 0;  // 정렬 과정에서 임시값 저장


void notice() {
    cout << "input numbers you want to sort (1 ~ 10, 10 numbers)\n" ;
    cout << "And if you want to finish input, input 0 last. \n";
    cout << "ex) 11 22 33 0 \n";
    cout << "input : ";

}

void Clear() {
    for (int i = 0; i < 1000; i++) {
        cout << endl;
    }
    }

void Display() {
    
 
    
    
   for (j = 0; j < i; j++ ) {
        
       cout << input[j];
       
       if ( input[j] < 10)
           cout << " ";
       
        while (1) {
            cout << "◼︎" ;
            cnt++;
    
            if ( cnt == input[j] ) {
                cout << endl;
                cnt = 0;
                
                break;
                
            }}}
    
   // usleep(200*200);

}

void Quicksort (int *input, int start, int end) {
    
    if (start >= end) {
        return;
    }
    
    pivot = start;
    k = pivot + 1;  // 오른쪽으로 가면서 피벗보다 큰 값을 찾음
    l = end;        // 왼쪽으로 가면서 피벗보다 작은 값을 찾음
    
    while(k <= l) {
                
        while ( k <= end && input[k] <= input[pivot] ) {
            k++;
        }
        
        while ( l > start && input[l] >= input[pivot]) {
            l--;
        }
        
        if ( k > l) {
            tmp = input[l];
            input[l] = input[pivot];
            input[pivot] = tmp;
            
            Clear();
            Display();

        }
        
        else {
            tmp = input[k];
            input[k] = input[l];
            input[l] = tmp;
            
            Clear();
            Display();

        }
        
                
        Quicksort(input, start , l - 1);
        Quicksort(input, l + 1, end);
        
                
    }
}

 void Is_correct() {
     
    for (int f = 0; f < 1000; f++) {
        
        if ( input[f] > input[f + 1] )
            Quicksort(input, 0, i - 1 );
        
    }
}


int main(int argc, const char * argv[]) {
 
    notice();
    
    for (i = 0; i < 1000; i++) {
        scanf (" %d", &input[i]);
        
        if (input[i] == 0) {
            break;
        }
    }
    
    Display();
    
    Clear();
    
    Is_correct();
    
    return 0;
}
