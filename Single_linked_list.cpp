#include<iostream>
using namespace std;
template <typename T> class node{
private:
	T value;
	node<T>* Next;
public:
	node(){
		this->Next = NULL;
	}
	node(T value){
		this->value = value;
		this->Next = NULL;
	}
	node<T>* getNext(){
		return this->Next;		
	}
	void setNext(node<T>* node){
		this->Next = node;
	}
	T getData(){
		return this->value;
	}
};
template <typename T> class LinkedList{
private:
	node<T> *head;
public:
	LinkedList(){
		this->head = NULL;
	}

  void insertFront(T value){
    node<T> * temp = new node<T>(value);
    temp->setNext(head);
    head = temp;
  }
	void insertNode(T value){
		node<T> *current = head;
		node<T> *temp = new node<T>(value);
		if(head == NULL){
			head = temp;
			return;	
		}
		while(current->getNext() != NULL){
			current = current->getNext();
		}
		current->setNext(temp);
	}	
	void deleteNode(T value){
		node<T> *current = head;
		node<T> *previous = NULL;

		while(current != NULL){
			if(current->getData() == value){
				if(previous == NULL){
					head = current->getNext();
				}
				else{
					previous->setNext(current->getNext());
				}
				if(current->getNext())
					current->setNext(NULL);	
			}
			previous = current;
			current = current->getNext();
		}
	}
	bool search(T value){
		node<T> *current = head;
		while(current != NULL){
			if(current->getData() == value)
				return true;
			current = current->getNext();
		}
		return false;
	}
    void print(){
		node<T> *current = head;
		while(current != NULL){
			cout<<current->getData()<<" ";
			current = (current->getNext());
		}
		cout<<endl;
	}
};
int main(){	
	LinkedList<int> list;
	
	list.insertNode(7);
	list.insertNode(2);
  list.insertFront(3);
	list.insertNode(9);
	list.insertNode(1);
	list.insertNode(21);
	
	if(list.search(6))
		cout<<"Present in list"<<endl;
	else
		cout<<"Not present in list"<<endl;	
	list.print();
	
	if(list.search(9))
		cout<<"Present in list"<<endl;
	else
		cout<<"Not present in list"<<endl;

	list.deleteNode(8);	
	list.print();
}