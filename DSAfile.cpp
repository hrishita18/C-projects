#include <fstream>
#include <iostream>
#define MAX 100
using namespace std;
string file1 = "Stack.txt";
string file2 = "Queue.txt";
string file3 = "Array.txt";
int n;
template <class T> class Stack {
  int top;

public:
  Stack() { top = -1; }
  T arr[MAX];
  void push(T ele) {
    if (top >= (MAX - 1))
      cout << "Stack Overflow." << endl;
    else {
      top++;
      arr[top] = ele;
    }
    saveToFile();
  }
  void pop() {
    if (top == -1)
      cout << "Stack Underflow" << endl;
    else {
      cout << "The popped element is " << arr[top] << endl;
      --top;
    }
  }
  inline void display() {
    cout << "Stack elements are: " << endl;
    for (int i = top; i >= 0; i--)
      cout << arr[i] << endl;
  }
  void input() {
    T ele;
    cout << "Enter the size of the stack: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << "Enter stack element: ";
      cin >> ele;
      push(ele);
    }
  }
  void saveToFile() {
    ofstream outFile(file1);
    if (!outFile) {
      cerr << "Error opening file: " << file1 << endl;
      exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; ++i) {
      outFile << arr[i] << endl;
    }
    outFile.close();
  }
};
template <class T> class Queue {
  int front, rear;
  T arr[MAX];

public:
  Queue() {
    front = -1;
    rear = -1;
  }
  void input() {
    T ele;
    cout << endl << "Enter the size of the queue: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << "Enter element to be inserted in the queue: ";
      cin >> ele;
      enqueue(ele);
    }
  }
  void enqueue(T ele) {
    if (rear == (MAX - 1))
      cout << "Queue overflow.";
    else if (front == -1 && rear == -1) {
      front = 0;
      rear = 0;
    } else
      rear = rear + 1;
    arr[rear] = ele;
    saveToFile();
  }
  void dequeue() {
    T val;
    if (front == -1 || front > rear)
      cout << "Queue is empty.";
    else {
      val = arr[front];
      front = front + 1;
      cout << endl << "Deleted element from the queue: " << val << endl;
    }
  }
  inline void display() {
    cout << "Elements in the queue: " << endl;
    for (int i = front; i <= rear; i++)
      cout << arr[i] << "\t";
  }
  void saveToFile() {
    ofstream outFile(file2);
    if (!outFile) {
      cerr << "Error opening file: " << file2 << endl;
      exit(EXIT_FAILURE);
    }
    for (int i = front; i <= rear; ++i) {
      outFile << arr[i] << "\t";
    }
    outFile.close();
  }
};
template <class T> class Array {
  T arr[MAX];

public:
  void input() 
  {
    cout << "Enter size of array: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << "Enter element: ";
      cin >> arr[i];
    }
    saveToFile();
  }
  void saveToFile() {
    ofstream outFile(file3);
    if (!outFile) {
      cerr << "Error opening file: " << file3 << endl;
      exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
      outFile << arr[i] << "\t";
    }
    outFile.close();
  }
  void DeleteElement() {
    int pos;
    cout << "Enter the position of the element to be deleted: ";
    cin >> pos;
    cout << "Deleted element: " << arr[pos - 1] << endl;
    for (int i = pos - 1; i < n; i++)
      arr[i] = arr[i + 1];
    n--;
  }
  void display() {
    cout << "Elements in the array: " << endl;
    for (int i = 0; i < n; i++)
      cout << arr[i] << "\t";
  }
  void sort() {
    int i, j, temp;
    for (i = 1; i < n; i++) {
      temp = arr[i];
      j = i - 1;
      while (arr[j] > temp && j >= 0) {
        arr[j + 1] = arr[j];
        --j;
      }
      arr[j + 1] = temp;
    }
  }
};
int main() {
  Stack<int> s1;
  Stack<char> s2;
  Queue<int> q1;
  Queue<char> q2;
  Array<int> a1;
  Array<char> a2;
  int ch1, ch2, ans = 1, ans1 = 1;
  while(ans = 1){
  cout << endl
       << "1.Stack for integers\n2.Queue for integers\n3.Stack for "
          "characters\n4.Queue for characters\n5.Array for integers\n6.Array "
          "for characters\n7.Exit\nEnter your choice: ";
  cin >> ch1;
  ans1=1;
  switch (ch1) {
  case 1:
    while (ans1 == 1) {
      cout << "\n\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ";
      cin >> ch2;
      switch (ch2) {
      case 1:
        s1.input();
        break;
      case 2:
        s1.pop();
        break;
      case 3:
        s1.display();
        break;
      case 4:
        ans1 = 0;
        break;
      default:
        cout << "Invalid choice entered.";
      }
    }
    break;
  case 2:
    while (ans1 == 1) {
      cout
          << "\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ";
      cin >> ch2;
      switch (ch2) {
      case 1:
        q1.input();
        break;
      case 2:
        q1.dequeue();
        break;
      case 3:
        q1.display();
        break;
      case 4:
        ans1 = 0;
        break;
      default:
        cout << "Invalid choice entered.";
      }
    }
    break;
  case 3:
    while (ans1 == 1) {
      cout << "\n\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ";
      cin >> ch2;
      switch (ch2) {
      case 1:
        s2.input();
        break;
      case 2:
        s2.pop();
        break;
      case 3:
        s2.display();
        break;
      case 4:
        ans1 = 0;
        break;
      default:
        cout << "Invalid choice entered.";
      }
    }
    break;
  case 4:
    while (ans1 == 1) {
      cout
          << "\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ";
      cin >> ch2;
      switch (ch2) {
      case 1:
        q2.input();
        break;
      case 2:
        q2.dequeue();
        break;
      case 3:
        q2.display();
        break;
      case 4:
        ans1 = 0;
        break;
      default:
        cout << "Invalid choice entered.";
      }
    }
    break;
  case 5:
    while (ans1 == 1) {
      cout << "\n\n1.Insert in array\n2.Delete element\n3.Display\n4.Sort the "
              "array\n5.Exit\nEnter "
              "your choice: ";
      cin >> ch2;
      switch (ch2) {
      case 1:
        a1.input();
        break;
      case 2:
        a1.DeleteElement();
        break;
      case 3:
        a1.display();
        break;
      case 4:
        a1.sort();
        break;
      case 5:
        ans1 = 0;
        break;
      default:
        cout << "Invalid choice entered.";
      }
    }
    break;
  case 6:
    while (ans1 == 1) {
      cout << "\n\n1.Insert in array\n2.Delete element\n3.Display\n4.Sort the "
              "array\n5.Exit\nEnter "
              "your choice: ";
      cin >> ch2;
      switch (ch2) {
      case 1:
        a2.input();
        break;
      case 2:
        a2.DeleteElement();
        break;
      case 3:
        a2.display();
        break;
      case 4:
        a2.sort();
        break;
      case 5:
        ans1 = 0;
        break;
      default:
        cout << "Invalid choice entered.";
      }
    }
    break;
    case 7: ans=0;
            exit(1);
            break;
    default: cout << "Invalid choice entered.";
    }
  }
  return 0;
}