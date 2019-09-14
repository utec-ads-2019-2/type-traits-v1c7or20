#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

enum Method {
    Move, Count, Transpose
};

template <typename T>
class SelfList {
    protected:
        Node<T>* head;
        Node<T>* tail;
        Method method;
        int Size=0;

    public:
        SelfList(Method method) : head(nullptr), method(method) {};

        bool insert(T data) {
            Node<T> *nuevo = new Node<T>(data);
            if (Size == 0){
                head = nuevo;
                tail = head;
                Size++;
                return true;
            }else{
                Node<T> *iterador = head;
                for (int i = 0; i <this->size() ; i++) {
                    if(iterador->data == data){
                        return true;
                    }else{
                        iterador = iterador->next;
                    }
                }
                tail->next = nuevo;
                tail=nuevo;
                Size++;
                return false;
            }
        }
             
        bool remove(T data) {
            Node<T>** temp = &head;
            for (int i = 0; i <Size ; i++) {
                if((*temp)->data==data){
                    auto toDelete = (*temp);
                    (*temp) = (*temp)->next;
                    delete toDelete;
                    Size--;
                    return true;
                } else{
                    temp = &((*temp)->next);
                }
            }
            return false;
        }  

        bool find(T data) {
            Node<T> **iterador = &head;
            Node<T> **before = &head;
            for (int i = 0; i < Size; i++) {
                if ((*iterador)->data == data){
                    if((*iterador) != head){
                        Node<T> *moved = (*iterador);
                        Node<T> **other = &head;
                        switch (method){
                            case Move:
                                for (int j = 0; j <i-1 ; ++j) {
                                    before = &(*before)->next;
                                }
                                (*iterador) = (*iterador)->next;
                                moved->next = (*before);
                                (*before) = moved;
                                break;
                            case Count:
                                moved->Rp++;
                                while ((moved->Rp)<((*other)->Rp)){
                                    other = &((*other)->next);
                                }
                                moved->next = *other;

                                break;
                            case Transpose:
                                (*iterador) = (*iterador)->next;
                                moved->next = head;
                                head = moved;
                                break;
                        }
                        i = Size;
                    }else {
                        (head)->Rp++;
                        return true;
                    }

                } else{
                    iterador = &((*iterador)->next);
                }
            }
            return false;
        }

        T operator [] (int index) {
            Node<T> * iterador = head;
            for (int i = 0; i <index ; i++) {
                iterador = iterador->next;
            }
            return iterador->data;
        }
             
        int size() {
            return Size;
        }

        void print() {
            Node<T>* iterador = head;
            for (int i = 0; i < Size; i++) {
                cout<<iterador->data<<" ";
                iterador = iterador->next;
            }cout<<endl;
        }

        ~SelfList() {
            head->killSelf();
        }
};

#endif