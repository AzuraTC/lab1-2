#include <conio.h>
#include <iostream>
#include <math.h>
#include <list>

using namespace std;

class lister
{
    int length;  //����� ����������� ����� ��������
    int currentPage; //������� ��������
    int totalPages; //����� ���������� �������
    list<int> listPages; //���� ��� �������� ���� ����������� ����� ��������
    protected:
        void list_pages();  //������� ��� ��������� �����, ��������� ����� ����������� �����
        void print_lister(); //������� ������������ ��������
    public:
        lister();  //����������� �� ���������
        lister(int length); //����������� � �������� ������
        ~lister() {}; //����������
        void start(); //������� ������� ������������ ��������
        void create_lister(); //������� ����� �������� ������ ��������

};

lister::lister() //����������� �� ���������
{
    currentPage =0;
    totalPages =0;
    length =1;
    listPages.push_back (0);
    cout<<"Object created!"<<endl;
}

lister::lister(int length1)  //����������� � �������� ������
{
    currentPage =0;
    totalPages =0;
    length = length1;
    listPages.push_back (0);
    cout<<"Object created!"<<endl;
}


void lister::start() //������� ������� ������������ ��������
{
    create_lister();
    list_pages();
    print_lister();
}

void lister::create_lister() //������� ����� �������� ������ ��������
{
    cout<<"Enter values:"<<endl;
    cout<<"Length lister - ";
    cin>>length;
    cout<<"Total pages - ";
    cin>>totalPages;
    cout<<"Current page - ";
    cin>>currentPage;

}

void lister::list_pages()  //������� ��� ��������� �����, ��������� ����� ����������� �����
{
    listPages.clear();
    listPages.push_back(currentPage);
    if(length % 2 == 0)
    {
        for (int i=0; i<((length/2)-1);i++)
         {
             listPages.push_front(currentPage-i-1);
             listPages.push_back(currentPage+i+1);
        }
        listPages.push_back(currentPage+(length/2)+1);
    }
    else
    {
        for (int i=0; i<round(length/2);i++)
         {
             listPages.push_front(currentPage-i-1);
             listPages.push_back(currentPage+i+1);
         }
    }
}


void lister::print_lister() //������� ������������ ��������
{
    cout<<"Length: "<<this->length<<endl;
    cout<<"Total pages: "<<this->totalPages<<endl;
    cout<<"Current page: "<<this->currentPage<<endl;


    cout << "1" << " << ";
    for ( list<int>::iterator it = listPages.begin(); it != listPages.end(); ++it  )
    {
        if(*it==currentPage)
        {
            cout<<"["<< *it << "]"<<' ';
        }
        else
        {
            cout << *it << ' ';
        }
    }
    cout<< ">> " << totalPages;
}


int main()
{
    lister Lister1;
    Lister1.start();
    return 0;
}

