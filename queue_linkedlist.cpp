#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void anggota()
{
    cout << " Program dibuat oleh :\n";
    cout << " 1. Muhammad zulfikar   (2310631170141)\n";
    cout << " 2. Rolis liu (2310631170117)\n";
    cout << " 3. Syafiq afiful azmi   (2310631170153)\n";
}

struct Node
{
    char data;
    Node *next;
};

struct LinkedListQueue
{
    Node *front;
    Node *rear;
};

bool isEmpty(const LinkedListQueue &q)
{
    return q.front == nullptr;
}

void enqueue(LinkedListQueue &q, char item)
{
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;

    if (isEmpty(q))
    {
        q.front = newNode;
        q.rear = newNode;
    }
    else
    {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

char dequeue(LinkedListQueue &q)
{
    if (isEmpty(q))
    {
        cout << "Queue sudah kosong.\n";
        return '\0';
    }

    char value = q.front->data;
    Node *temp = q.front;
    q.front = q.front->next;
    delete temp;
    return value;
}

bool isPalindrome(string word)
{
    LinkedListQueue q;
    q.front = nullptr;
    q.rear = nullptr;
    int len = word.length();

    for (int i = 0; i < len; i++)
    {
        enqueue(q, word[i]);
    }

    for (int i = 0; i < len / 2; i++)
    {
        char frontChar = dequeue(q);
        char rearChar = word[len - i - 1];

        if (frontChar != rearChar)
            return false;
    }
    return true;
}
int main()
{
    char pil;
    bool exitProgram = false;
    while (!exitProgram)
    {
        int jChar;
        cout << " \t\tProgram Menentukan\n";
        cout << " Palindrome atau Bukan Palindrome Menggunakan Linked List\n";
        cout << " -------------------------------------------------------------\n";
        cout << " Pilihan menu:\n";
        cout << " 1. Cek Palindrome\n";
        cout << " 2. Keluar\n";
        cout << " Pilihan : ";
        cin >> pil;

        system("cls");

        switch (pil)
        {
        case '1':
        {
            cout << " Masukkan jumlah huruf yang ingin di cek : ";
            cin >> jChar;
            string word;
            cout << " Masukkan huruf satu per satu\n";
            for (int i = 0; i < jChar; ++i)
            {
                char ch;
                cout << " Masukkan huruf ke-" << i + 1 << " : ";
                cin >> ch;
                word += ch;
            }
            cout << " Kata yang dibentuk : " << word << "\n";
            if (isPalindrome(word))
            {
                cout << " " << word << " adalah palindrome\n";
            }
            else
            {
                cout << " " << word << " bukan palindrome\n";
            }
            cout << " Tekan apa saja untuk kembali ke menu !";
            _getch();
            system("cls");
            break;
        }
        case '2':
            cout << "Terima kasih telah menggunakan program ini. Sampai jumpa lagi!\n";
            anggota();
            exitProgram = true;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih 1 atau 2.\n";
            break;
        }
    }
    return 0;
}