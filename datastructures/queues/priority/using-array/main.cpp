#include <iostream>
#include <string>
#include "./operations.h"

#define MAX_SIZE 10

using namespace std;

int Q[MAX_SIZE], Pr[MAX_SIZE];
int rear = -1, front = -1;


int getFront() {
    return Q[front];
}


int getRear() {
    return Q[rear];
}

void print(string title){
    cout << title << ": " << endl<< "[" << endl;
    for (int i = front; i <= rear; i++){
        cout << "\t(Data => " << Q[i] << ", Priority => " << Pr[i] <<" )," << endl;
    }

    cout << "] "<< endl;
}



void enqueue(int data, int priority){
    int i ;
    if ((front == 0) && (rear == (MAX_SIZE - 1))){
         cout << "Overflow" << endl;
         return;
    }

    else{
        if (front == -1){
            front = rear = 0;
            Q[rear] = data;
            Pr[rear] = priority;
        }
        else{
            for (i= rear; i >= front; i--){
                if (priority > Pr[i]){
                    Q[i + 1] = Q[i];
                    Pr[i + 1] = Pr[i];
                }
                else break;
            }
            Q[i + 1] = data;
            Pr[i + 1] = priority;
            rear++;
        }
    }
    print("PriorityQueue after insertion");
}


void dequeue(){
    if (front == -1){
        cout << "Underflow";
        return;
    }
    else{
        if (front == rear) front = rear = -1;
        else front++;
    }

    print("PriorityQueue after deletion");
}



int main(){
	cout << endl;

	enqueue(1, 1);
	enqueue(2, 2);
	enqueue(3, 3);
	enqueue(0, 0);

	cout << "The FirstElement in PriorityQueue is: " << getFront() << endl;
	cout << "The LastElement in PriorityQueue is: " << getRear() << endl;

	dequeue();
	dequeue();

	cout << endl;
    
 return 0;
}
