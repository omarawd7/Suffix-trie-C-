#include<iostream>
#define MAX_CHAR 256
using namespace std;

class Node {
public:
    int data;
    Node* next;


    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {

public:
Node* head;
    LinkedList() { head = NULL; }

    void insertNode(int data)
{
    Node* n = new Node(data);
    if (head == NULL) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = n;
}

};



/////////////////the linked list /////////////////////////

class SuffixTrieNode
{
private:
      LinkedList ind ;
    SuffixTrieNode *child[MAX_CHAR];
public:
    SuffixTrieNode()
    {
        for (int i = 0; i < MAX_CHAR; i++)
          child[i] = NULL;
    }
    void Insert(string str, int i)
{
    ind.insertNode(i);

    if (str.length() > 0)
    {
        char cIndex = str.at(0);
        if (child[cIndex] == NULL)
            child[cIndex] = new SuffixTrieNode();
    child[cIndex]->Insert(str.substr(1), i+1);
    }
}


    LinkedList* search1(string s)
{
    if (s.length() == 0)
        return &ind;

    if (child[s.at(0)] != NULL)
        return (child[s.at(0)])->search1(s.substr(1));

    else return NULL;
}
friend class  SuffixTrie;
};


class SuffixTrie
{
private:
    SuffixTrieNode root;
public:

    SuffixTrie(string txt)
    {

        for (int i = 0; i < txt.length(); i++)
            root.Insert(txt.substr(i), i);
    }


   void Search(string p)
{

    LinkedList * result=root.search1(p);

    if (result == NULL)
        cout << " not exist" << endl;
    else
    {
        Node * res= result->head;
        int Len = p.length();
            while(res !=NULL) {
			cout << p<<" found at position " <<  res->data -Len << endl;
			res = res->next;

		}
    }
}
};



int main()
{
    string txt = "bananabanaba$";
    SuffixTrie S(txt);

    S.Search("ana");

    return 0;
}
