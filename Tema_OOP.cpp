#include<iostream>
#include<bits/stdc++.h>
#include <cstddef>
using namespace std;

class nod
{
public:
    int key;
    int data;
    nod* next;
nod()
    {
        key=0;
        data=0;
        next=NULL;
    }
    nod(int k,int d)
    {
        key=k;
        data=d;
        next=NULL;
    }
    ~nod();
friend class circular_list;
};

class circular_list
{
private:
    nod* head;
public:

    circular_list()
    {
        head=NULL;
    }
    // 1 verificam daca nodul exista folosind o cheie
    nod* verify_nod(int k)
    {
        nod* temporr = NULL;
        nod* ptr = head;

        if(ptr==NULL)
        {
            return temporr;
        }
        else
        {
            do
            {
                if(ptr->key==k)
                {
                    temporr=ptr;
                }
                ptr=ptr->next;
            }while(ptr!=head);
            return temporr;
        }



    }
    // 2 Adaugam un nod la lista
    void append_nod(nod* new_nod)
    {
        if(verify_nod(new_nod->key)!=NULL)
        {
            cout<<"Nodul deja exista si are cheia: "
            <<new_nod->key
            <<". Adaugati un nod cu o cheie diferita de cea tocmai aleasa"
            <<endl;
        }
        else
        {
            if(head==NULL)
            {
                head = new_nod;
                new_nod->next=head;
                cout<<"Nod adaugat la prima pozitie"<<endl;
            }
            else
            {
                nod* ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
            ptr->next = new_nod;
            new_nod->next = head;
            cout << "Nod adaugat cu succes" << endl;
            }
        }

    }
  // 3. Adaugam un not la inceputul listei
  void first_nod(nod * new_nod)
  {
        if (verify_nod(new_nod->key)!= NULL)
            {
                cout << "Nodul deja exista si are cheia:  " <<
                new_nod->key <<
                ". Adaugati un nod cu o cheie diferita de cea tocmai aleasa" <<
                endl;
            } else
                {
                    if (head == NULL)
                    {
                        head = new_nod;
                        new_nod->next = head;
                        cout << "Nod adaugat la prima pozitie " << endl;
      } else
      {
            nod * ptr = head;
            while (ptr->next != head) {
            ptr = ptr->next;
        }

        ptr->next = new_nod;
        new_nod->next = head;
        head = new_nod;
        cout << "Nod adaugat cu succes" << endl;
      }

    }
  }

  // 4. Adaugati un nod pe o anumita pozitie
  void insert_nod(int k, nod * new_nod)
  {
        nod* ptr = verify_nod(k);
        if (ptr==NULL)
            {
                cout << "Nu exista nod care sa aiba cheia : " << k << endl;
    } else
    {
            if (verify_nod(new_nod->key)!= NULL)
                {
                    cout << "Nodul deja exista si are cheia: " <<
                    new_nod-> key <<
                    ". Adaugati un nod cu o cheie diferita de cea tocmai aleasa" <<
                    endl;
      } else
      {
            if (ptr->next == head)
                {
                    new_nod->next = head;
                    ptr->next = new_nod;
                    cout<< "Nod adaugat la final" << endl;
        } else
        {
          new_nod->next = ptr->next;
          ptr->next = new_nod;
          cout << "Nod adaugat intre ele" << endl;
        }

      }
    }
  }

  // 5. Stergerea unui nod
  void delete_nod(int k)
  {
    nod * ptr = verify_nod(k);
    if (ptr == NULL)
        {
            cout << "Nu exista nod care sa aiba cheia : " << k <<
            endl;
    } else
    {
            if (ptr == head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    cout << "Nodul prim nu are legatura... Lista goala";
        } else
        {
          nod * ptr1 = head;
          while (ptr1->next!= head)
          {
            ptr1 = ptr1->next;
          }
          ptr1->next = head->next;
          head = head->next;
          cout << "Nodul nu are legatura si are cheia : " << k << endl;
        }
      } else
      {
        nod * temporr = NULL;
        nod * pre_ptr = head;
        nod * current_ptr = head->next;
        while (current_ptr != NULL)
        {
          if (current_ptr->key == k)
          {
            temporr = current_ptr;
            current_ptr = NULL;
          } else
          {
            pre_ptr = pre_ptr->next;
            current_ptr = current_ptr->next;
          }
        }

        pre_ptr->next = temporr-> next;
        cout << "Nodul nu are legatura si are cheia : " << k << endl;

      }

    }

  }
  // 6th update nod
  void update_nod(int k, int new_data)
  {

    nod * ptr = verify_nod(k);
    if (ptr != NULL) {
      ptr->data = new_data;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }

  }

  // 7 Afisarea listei
  void print_list()
    {
        if(head == NULL)
            {
                cout << "Nu exista noduri in lista circulara";
            } else
            {
                cout << endl << "Adresa nodulul cap este : " << head << endl;
                cout << "Nodurile din lista circulara sunt urmatoarele: " << endl;

      nod* temporr = head;

      do {
            cout << "(" << temporr->key<<","<<temporr->data<<","<<temporr->next<<") --> ";
            temporr = temporr->next;
      } while (temporr != head);
    }

  }
  friend istream& operator>>(istream& scrie, circular_list&);

};

/*istream & operator>>(istream& adauga, circular_list& clist)
{
     nod temporr;
     int val;

     while (val != 0)
     {
     adauga >> val;

     if (val ==0) // 
     
            return adauga;

        temporr.nod(temporr,val);
        clist.append_nod(temporr);
     }

    return scrie;
}*/
// lista l1= listal2=b l1.next=l2.primul return l1;
int main()
{ circular_list l1;
  int option;
  int key1, k1, data1;
  do
    {
        cout << "\n Ce operatie vrei sa rulezi? Selecteaza un numar. Apasa 0 pentru a iesi" << endl;
        cout << "1. Adauga nod()" << endl;
        cout << "2. Adauga la inceput()" << endl;
        cout << "3. Insereaza un nod()" << endl;
        cout << "4. Sterge un nod()" << endl;
        cout << "5. Afiseaza lista()" << endl;
        cout << "6. Curata ecranul" << endl << endl;

    cin >> option;
    nod * n1 = new nod();
    //Node n1;

    switch (option)
    {
        case 0:
        break;
        case 1:
            cout << "Adauga un nod \nScrie cheia si valoarea lui" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            l1.append_nod(n1);
            //cout<<n1.key<<" = "<<n1.data<<endl;
            break;

    case 2:
      cout << "Adauga un nod la inceput \nScrie cheia si valoarea lui" << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;
      l1.first_nod(n1);
      break;

    case 3:
      cout << "Adauga un nod pe o pozitie oarecare \nScrire cheia nodului dupa care vrei sa adaugi noul nod " << endl;
      cin >> k1;
      cout << "Scrie cheia si valoarea noului nod: " << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;

      l1.insert_nod(k1, n1);
      break;

    case 4:

      cout << "Stergerea unui nod- \nScrie cheia nodului care vrei sa fie sters:" << endl;
      cin >> k1;
      l1.delete_nod(k1);

      break;

    case 5:
      l1.print_list();

      break;
    case 6:
      system("cls");
      break;
        default:
        cout << "Selecteaza un numar " << endl;
    }

  } while (option != 0);

  return 0;


}
