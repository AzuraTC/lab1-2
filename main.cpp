#include <conio.h>
#include <iostream>
#include <math.h>
#include <list>

using namespace std;

class lister
{
    int length;  //кол-во страниц между стрелками НАЗАД и ВПЕРЁД
    int currentPage; //текущая страница
    int totalPages; //общее число страниц
    list<int> listPages; //массив номеров страниц
    protected:
        void list_pages();  //возвращает массив страниц
        void print_lister(); //возвращает текст страницы
    public:
        lister();  //конструктор по умолчанию
        lister(int length); //конструктор с заданной длиной
        ~lister() {}; //деструктор
        void start();
        void create_lister(); //ввод исходных данных

};

lister::lister() //описание конструктора по умолчанию
{
    currentPage =0;
    totalPages =0;
    length =1;
    listPages.push_back (0);
    cout<<"Object created!"<<endl;
}

lister::lister(int length1)  //описание конструктора с заданной длиной
{
    currentPage =0;
    totalPages =0;
    length = length1;
    listPages.push_back (0);
    cout<<"Object created!"<<endl;
}


void lister::start()
{
    create_lister();
    list_pages();
    print_lister();
}

void lister::create_lister() //описание функции ввода данных
{
    cout<<"Enter values:"<<endl;
    cout<<"Length lister - ";
    cin>>length;
    cout<<"Total pages - ";
    cin>>totalPages;
    cout<<"Current page - ";
    cin>>currentPage;

}

void lister::list_pages()  //описание возвращает массив страниц
{
    listPages.clear();
    listPages.push_back(currentPage);
    if(length % 2 == 0)
    {
       //четное
        for (int i=0; i<((length/2)-1);i++)
         {
             listPages.push_front(currentPage-i-1);
             listPages.push_back(currentPage+i+1);
        }
        listPages.push_back(currentPage+(length/2)+1);
    }
    else
    {
       //не четное

        for (int i=0; i<round(length/2);i++)
         {
             listPages.push_front(currentPage-i-1);
             listPages.push_back(currentPage+i+1);
         }
    }
}


void lister::print_lister() //возвращает текст страницы
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
    lister Lister1; //создание объекта класса
    Lister1.start();
    return 0;
}

