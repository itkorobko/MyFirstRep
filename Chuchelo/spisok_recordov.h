#ifndef SPISOK_RECORDOV_H
#define SPISOK_RECORDOV_H
#include<QString>
class spisok_recordov
{
private:
    struct Node
    {
        QString name;
        int index;
        int seconds;
        int minutes;
    Node* next;
    }*head;

public:
    spisok_recordov();
    void push(QString, int,int);
    void read_from_file();
    void write_in_file();
    int isRecord();

};

#endif // SPISOK_RECORDOV_H
