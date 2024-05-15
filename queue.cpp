#include <iostream>
#include <string>
#define maks 50
using namespace std;

//deklarasi struct queue
struct Queue
{
    int front, rear;
    char data[maks];
} Q;

//inisiasi queue awal
void initQueue()
{
    Q.front = 0;
    Q.rear = 0;
}

//validasi apakah queue penuh
bool isFull()
{
    return Q.rear == maks;
}

//validasi apakah queue kosong
bool isEmpty()
{
    return Q.rear == Q.front;
}

//function enqueue menambah karakter ke dalam queue
void enqueue(char data)
{
    if (!isFull())
    {
        Q.data[Q.rear++] = data;
    }
}

//function untuk compare karakter 
bool isPalindrome()
{
    int length = Q.rear;
    for (int i = 0; i < length / 2; i++)
    {
        if (Q.data[i] != Q.data[length - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int jumlah;
    char ch, pil;

    do {
        initQueue();
        cout << "Masukkan jumlah karakter: ";
        cin >> jumlah;
        for (int i = 1; i <= jumlah; i++)
        {
            cout << "Masukkan karakter ke-" << i << ": ";
            cin >> ch;
            enqueue(ch);
        }

        if (isPalindrome())
        {
            cout << "Kata tersebut adalah palindrome" << endl;
        }
        else
        {
            cout << "Kata tersebut bukan palindrome" << endl;
        }

        cout << "Apakah Anda ingin memeriksa kata lain? (y/n): ";
        cin >> pil;

    } while (pil == 'y' || pil == 'Y'); //looping untuk validasi menjalankan program ulang

    cout << "Program selesai." << endl;
    cout << "Nama Kelompok" << endl;
    cout << "Nama" << "\t\t\t\t" << "NPM" << endl;
    cout << "Rolis Liu" << "\t\t\t" << "2310631170117" << endl;
    cout << "Syafiq Affiful Azmi" << "\t\t" << "2310631170153" << endl;
    cout << "Muhammad Zulfikar A.R." << "\t\t" << "2310631170141" << endl;

    return 0;
}
