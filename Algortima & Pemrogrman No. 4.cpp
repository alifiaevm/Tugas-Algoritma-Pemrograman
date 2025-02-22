#include <iostream>
using namespace std;

struct Node {
    int data;     
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        cout << "Data " << data << " ditambahkan ke stack.\n";
    }

    
    int pop() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak dapat pop.\n";
            return -1;
        }
        Node* temp = top;
        int poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack kosong.\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack kosong.\n";
            return;
        }
        Node* temp = top;
        cout << "Isi stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    int pilihan, data;

    do {
        cout << "\nMenu Stack:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Cek apakah stack kosong\n";
        cout << "5. Tampilkan stack\n";
        cout << "6. Keluar\n";
        cout << "Pilih pilihan (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data yang ingin ditambahkan ke stack: ";
                cin >> data;
                stack.push(data);
                break;

            case 2:
                data = stack.pop();
                if (data != -1) {
                    cout << "Data yang di-pop: " << data << endl;
                }
                break;

            case 3:
                data = stack.peek();
                if (data != -1) {
                    cout << "Data di puncak stack: " << data << endl;
                }
                break;

            case 4:
                if (stack.isEmpty()) {
                    cout << "Stack kosong.\n";
                } else {
                    cout << "Stack tidak kosong.\n";
                }
                break;

            case 5:
                stack.display();
                break;

            case 6:
                cout << "Terima kasih! Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                break;
        }

    } while (pilihan != 6);

    return 0;
}
