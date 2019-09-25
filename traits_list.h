#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
        int Size = 0;

        bool find(T data, Node<T> **pointer) {
            for (int i = 0; i < this->size(); i++) {
                if ((*pointer)->data == data){
                    return true;
                } else {
                    (pointer) = &((*pointer)->next);
                }
            }
            return false;
        }
              
    public:
        TraitsList() : head(nullptr) {};

        bool insert(T data) {
            Node<T> *nuevo = new Node<T>(data);
            if (Size == 0){
                head = nuevo;
                Size++;
                return true;
            }else{
                // Estás repitiendo mucho código
                Node<T>** temp = &head;
                if(!find(data,temp)){
                    temp = &head;
                    for (int i = 0; i < this->size(); i++) {
                        if (cmp(((*temp)->data),nuevo->data)){
                            temp = &((*temp)->next);
                        } else{
                            (*temp)->next = nuevo;
                            nuevo->next = (*temp)->next->next;
                            Size++;
                            return true;
                        }
                    }
                    (*temp) = nuevo;
                    nuevo->next = (*temp)->next;
                    Size++;
                    return true;
                }else{
                    return false;
                }
            }
        }
             
        bool remove(T data) {
            // El insert debería ser similar, este remove está muy parecido al de Said
            Node<T>** temp = &head;
            if (find(data,temp)){
                auto toDelete = *temp;
                (*temp) = (*temp)->next;
                delete toDelete;
                Size--;
                return true;
            }else return false;
        }  

        bool find(T data) {
            // Deberías usar el find de arriba
            Node<T> *iterador = head;
            for (int i = 0; i <this->size() ; i++) {
                if (iterador->data == data){
                    return true;
                } else{
                    iterador = iterador->next;
                }
            }
            return false;
        }

        T operator [] (int index) {
            Node<T>* iterador = head;
            for (int i = 0; i < index ; i++) {
                iterador = iterador->next;
            }
            return iterador->data;
        }
             
        int size() {
            return Size;
        }

        void print() {
            Node<T>* iterador = head;
            for (int i = 0; i <this->size() ; i++) {
                cout<<iterador->data<<" ";
                iterador = iterador->next;
            }cout<<endl;
        }

        ~TraitsList() {
            head->killSelf();
        }
};

#endif