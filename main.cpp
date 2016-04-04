#include <conio.h>
#include <iostream>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
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



bool IsValidInt(char* x){
    bool Checked = true;
    int i = 0;
    do
    {
        //valid digit?
        if (isdigit(x[i]))
        {
            //to the next character
            i++;
            Checked = true;
        }
        else
        {
            //to the next character
            i++;
            Checked = false;
            break;
        }
    } while (x[i] != '\0');

    return Checked;
}


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
    bool correctInput=0;
    while (correctInput==0) {
        char str[]="";
        cout<<"Length lister - ";
        cin>>str;
        if (IsValidInt(str)){
            length=atoi(str);
            correctInput=1;
        }
        else {
            cout<<"Incorrect input! Lenght lister should be decimal! Please, repeat correct input!"<<endl;
        }
    }
    correctInput=0;
    while (correctInput==0) {
        char str[]="";
        cout<<"Total pages - ";
        cin>>str;
        if (IsValidInt(str)){
            totalPages=atoi(str);
            correctInput=1;
        }
        else {
            cout<<"Incorrect input! Total pages should be decimal! Please, repeat correct input!"<<endl;
        }
    }
    correctInput=0;
    while (correctInput==0) {
        char str[]="";
        cout<<"Current page - ";
        cin>>str;
        if (IsValidInt(str)){
            currentPage=atoi(str);
            correctInput=1;
        }
        else {
            cout<<"Incorrect input! Current page should be decimal! Please, repeat correct input!"<<endl;
        }
    }

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

