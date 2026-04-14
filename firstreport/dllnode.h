#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
#include <string>
using namespace std;

typedef struct student
{
    int num;
    string name;
} student;
typedef struct dllnode
{
    student stu;
    struct dllnode *prev;
    struct dllnode *next;

} dllnode;
typedef struct dllist
{
    dllnode *head;
    dllnode *tail;
    int size;
} dllist;

#endif // DLLIST_H