/*
Nama        : Falah Rizqi Abudllah Fairuz
NPM         : 140810180069
Deskripsi   : exercise-04 multilist
Kelas       : A
*/

#include<iostream>
#include<conio.h>
using namespace std;

struct Index
{
    char index;
    Index* next;
    Contact* nextContact;
};

struct Contact
{
    char name[20];
    char phone[12];
    Contact* next;
};

typedef Index* pInd;
typedef Contact* pCon;

typedef pInd listInd;

void createlistIndex(listInd& first)
{
    first = NULL;
}

void createIndex(pInd& baru)
{
    baru = new Index;
    cout << "Index : "; cin >> baru->index;
    baru->next = NULL;
}

void createContact(pCon& baru)
{
    baru = new Contact;
    cout << "Contact" << endl;
    cout << "Name : "; cin.ignore(); cin.getline(baru->name, 20);
    cout << "Phone : "; cin.getline(baru->phone, 12);
    baru->next = NULL;
}

void insertIndex(listInd& first, pInd baru)
{
    pInd last;
    if (first == NULL)
    {
        first = baru;
    }

    else
    {
        last = first;
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = baru;
    }
}

void search(listInd first, char key, int& found, pInd& cari)
{
    found = 0;
    cari = first;
    while(found == 0 && cari != NULL)
    {
        if (cari->index == key)
        {
            found = 1;
        }

        else
        {
            cari = cari->next;
        }
    }
}

void insertContact(listInd& first, char key, pCon baru)
{
    pInd index;
    pCon last;
    int found;
    
    search(first, key, found, index);

    if (found)
    {
        cout << "Index found" << endl;
        if (index->nextContact == NULL)
        {
            index->nextContact = baru;
        }
        else
        {
            last = index->nextContact;
            while(last->next != NULL)
            {
                last = last->next;
            }
            last->next = baru;
        }
    }
    else
    {
        cout << "Not found" << endl;
    }
    
}

void deletecontact(listInd& first, pCon update)
{
    // pInd index;
    // pCon last, preclast;
    // int found;

    // search(first,key,found,index);
    // if (found)
    // {
    //     if (index->nextContact == NULL)
    //     {
    //         hapus = NULL;
    //         cout << "Empty list" << endl;
    //     }

    //     else if (index->nextContact->next == NULL)
    //     {
    //         hapus = index->nextContact;
    //         index->nextContact = NULL;
    //     }
        
    //     else
    //     {
    //         last = index->nextContact;
    //         preclast = NULL;
    //         while(last->next != NULL)
    //         {
    //             preclast = last;
    //             last = last->next;
    //         }
    //         hapus = last;
    //         preclast->next = NULL;
    //     }
        
        
    // }
    char nama[20];
    cout << "Nama yang akan dihapus : "; cin.ignore; cin.getline(nama, 20);

    pInd index;
    index = first;
    while((index->index != nama[0]) && (index != NULL))
    {
        index = index->next;
    }
    if(index == NULL)
    {
        cout << "No match" << endl;
    }
    else
    {
        pCon contact;
        update = index->nextContact;
        while((update != NULL) && (update->name != nama))
        {
            contact = update;
            update = update->next;
        }
        contact->next = update->next;
        update->next = NULL;
        
    }
}

void updatecontact(listInd& first, pCon update)
{
    char nama[20];
    cout << "Nama yang akan dihapus : "; cin.ignore; cin.getline(nama, 20);

    pInd index;
    index = first;
    while((index->index != nama[0]) && (index != NULL))
    {
        index = index->next;
    }
    if(index == NULL)
    {
        cout << "No match" << endl;
    }
    else
    {
        update = index->nextContact;
        while((update != NULL) && (update->name != nama))
        {
            update = update->next;
        }
        if (update == NULL)
        {
            cout << "No match" << endl;
        }
        else
        {
            cout << "Insert new name : "; cin.ignore(); cin.getline(update->name, 20);
            cout << "Insert new phone : "; cin.getline(update->phone, 20);
        }
    }
}

void traverse(listInd& first)
{
    pInd index;
    pCon contact;

    index = first;
    while(index != NULL)
    {
        contact = index->nextContact;
        while(contact->next != NULL)
        {
            cout << contact->name << " " << contact->phone << endl;
            contact = contact->next;
        }
        index = index->next;
        
    }
    
}

main()
{
    pInd p;
    pCon q;
    listInd l;
    int menu;
    char k;
    createlistIndex(l);
    
    do
    {
        cout << "1. Insert index" << endl;
        cout << "2. Insert contact" << endl;
        cout << "3. Delete contact" << endl;
        cout << "4. Update contact" << endl;
        cout << "5. Print list" << endl;
        cout << "6. Exit" << endl;
        cout << "Pilihan : "; cin >> menu;

        switch (menu)
        {
            case 1:
                createIndex(p);
                insertIndex(l,p);
                break;

            case 2 :
                createContact(q);
                insertContact(l,k,q);
                break;

            case 3 :
                deletecontact(l,q);
                break;

            case 4 :
                updatecontact(l,q);
                break;

            case 5 :
                traverse(l);
                break;

            default:
                cout << "Exit" << endl;
                break;
        }
    } while (menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5);
}