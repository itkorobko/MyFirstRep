#include "spisok_recordov.h"
#include<QFile>
#include <QTextStream>
spisok_recordov::spisok_recordov()
{
    head=nullptr;
}
void spisok_recordov::push(QString s, int m, int sec)
{
    // QFile sp(":/txtfiles/Records.txt");
    // sp.open(QIODevice::WriteOnly|QIODevice::Truncate);
    //  QTextStream potok(&sp);

    // int arr[10];
    // int i1=0;
    // QString tmp;
    // while(!potok.atEnd())
    // {
    //     potok>>tmp>>arr[i1];
    //     i1++;
    // }
    if(head==nullptr)
    {
        head=new Node;
        head->name=s;
        head->minutes=m;
        head->seconds=sec;
        head->next=nullptr;
        head->index=1;

    }
    else if(head->minutes*60+head->seconds>=m*60+sec)
    {
        Node* nh=new Node;
        nh->name=s;
        nh->minutes=m;
        nh->seconds=sec;
        nh->next=head;
        head=nh;
    }
    else
    {
        Node* temp=head;
        int i=1;
        if(temp->next!=nullptr)
        {
            while(temp->next->minutes*60+temp->next->seconds<m*60+sec)
            {

                 temp=temp->next;
                 i++;
                 if(i==6)
                     return;
                 if(temp->next==nullptr)
                     break;

            }
            if(temp->next==nullptr)
            {
                temp->next=new Node;
                temp->next->name=s;
                temp->next->minutes=m;
                temp->next->seconds=sec;
                temp->next->next=nullptr;
                i++;
                temp->next->index=i;

            }



        Node* el=new Node;
            el->next=temp->next;
        el->name=s;
        el->minutes=m;
        el->seconds=sec;

        temp->next=el;
        i++;
        el->index=i;

        }
        else
        {
            temp->next=new Node;
            temp->next->name=s;
            temp->next->minutes=m;
            temp->next->seconds=sec;
            temp->next->next=nullptr;
            i++;
            temp->next->index=i;

        }
    }
}
void spisok_recordov::read_from_file()
{
    QFile MyFile("D:/к лабам/Chuchelo/Records.txt");
    MyFile.open(QIODevice::ReadOnly);
    QTextStream potok(&MyFile);
    head=new Node;
    Node* temp=head;
    QString tmp;
    int i1=1;
    while(!potok.atEnd())
    {
        tmp=potok.readLine(0);
        bool fl=false;
        QString tmp1;
        tmp+=" ";

        for(int i=0;i<tmp.size();i++)
        {


            if(tmp[i]!=' ')
                tmp1+=tmp[i];
            else
            {
                bool fl1=false;

                for(int j=0;j<tmp1.size();j++)
                {
                    if(!tmp1[j].isDigit())
                    {
                        fl1=true;
                        break;
                    }
                }
                if(fl1)
                {
                    temp->name=tmp1;
                    tmp1="";
                }

                else
                {
                    bool ok;
                    if(fl==true)
                    {
                        temp->seconds=tmp1.toInt(&ok,10);
                        tmp1="";
                    }

                    else
                    {

                        temp->minutes=tmp1.toInt(&ok,10);
                        tmp1="";
                        fl=true;
                    }
                }

            }
        }
        temp->index=i1;
        i1++;
        if(!potok.atEnd())
        {
            temp->next=new Node;
            temp=temp->next;
        }
    }
    temp->next=nullptr;
    MyFile.close();
}
void spisok_recordov::write_in_file()
{
    QFile sp("D:/к лабам/Chuchelo/Records.txt");
    sp.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream potok(&sp);
    Node* temp=head;
    int i=1;
    while(temp!=nullptr && i<=5)
    {
        i++;
        potok<<temp->name<<"  "<<temp->minutes<<" "<<temp->seconds<<"\n";
        temp=temp->next;
    }
    sp.close();

}
int spisok_recordov::isRecord()
{
    return 0;
}
