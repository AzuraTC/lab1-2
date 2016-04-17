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
    if ((currentPage==0) || (length==0) || (totalPages==0))
    {
        cout <<"Error! Incorrect values!"<<endl;
        cout <<"0"<<endl;
    }
    else
    {
        if ((currentPage==1) || (length==1) || (totalPages==1))
        {
            cout <<currentPage<<endl;
        }
        else
        {
            list_pages();
            create_lister();
        }
    }
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
            cout<<"Incorrect input! Length lister should be decimal! Please, repeat correct input!"<<endl;
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
    if (currentPage>totalPages)
    {
        cout<<"Incorrect values! Current page should be smaller then total pages."<<endl;
        create_lister();
    }
    if (length>totalPages)
    {
        cout<<"Incorrect values! Length should be smaller then total pages."<<endl;
        create_lister();
    }

}

void lister::list_pages()  //������� ��� ��������� �����, ��������� ����� ����������� �����
{
    listPages.clear();  //������� ������ ��������� �������
    listPages.push_back(currentPage); //��������� ������� ��������
    int a=0;
    int c=0;
    int b=0;
    if (currentPage==totalPages) a =1;  //������� - ��������� ��������
    else {
        if (currentPage==1)  a =2;  //������� - ������ ��������
        else {
            if((totalPages-currentPage)<=(length/2)) a =3; //������� �������� ����� � �����
            else {
                if((currentPage-1)<=(length/2)) a =4;//������� �������� ����� � ������
                else {
                    if (length % 2 == 0)  a =5;  //������ ����� ��������� �������
                }
            }
        }
    }

    switch (a)
    {
    case (1):
        for(int i=0; i<length-1; i++)
        {
            listPages.push_front(currentPage-i-1);
        }
        break;
    case (2):
        for(int i=0; i<length-1; i++)
        {
            listPages.push_back(currentPage+i+1);
        }
        break;
    case (3):
        c=1;
        for (int i=currentPage; i<totalPages-1;i++)
        {
            listPages.push_front(currentPage-c);
            listPages.push_back(currentPage+c);
            c++;
        }
        b=length-(c-1)*2+1;

        for (int i=0; i<b; i++)
        {
            listPages.push_front(currentPage-c-i);
        }
        break;
    case (4):
        c=1;
        for (int i=currentPage-1; i>1;i--)
        {
            listPages.push_front(currentPage-c);
            listPages.push_back(currentPage+c);
            c++;
        }
        b=length-(c-1)*2+1;
        for (int i=0; i<b; i++)
        {
            listPages.push_back(currentPage+c+i);
        }
        break;
    case (5):
        for (int i=0; i<((length/2)-1);i++)
        {
            listPages.push_front(currentPage-i-1);
            listPages.push_back(currentPage+i+1);
        }
        listPages.push_back(currentPage+(length/2)+1);
        break;
    default:
        //�������� ����� ��������� �������

        for (int i=0; i<round(length/2);i++)
        {
            listPages.push_front(currentPage-i-1);
            listPages.push_back(currentPage+i+1);
        }
        break;
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

