#include<iostream>
using namespace std;

template <typename T> class Array{
private:
	int size;
	T* arr;

public:
// array contructor
	Array(int size){
		(*this).size= size;
		arr = new  T[size];
	}
	
  // array function
	void getArray(){
		for(int index=0; index<size; index++){
			cout << arr[index] << " ";
		}
		cout << endl;
	}

	void insertElement(int index, T value){
		if(index >= size || index < 0){
			cout << "index out of bound" << endl;
			return;
		}
		arr[index] = value;
	}
	
	void deleteElement(int index){

	}
	
	bool search(T value){
		for(int index=0; index<size; index++){
			if(arr[index] == value)
				return true;
		}
		return false;
	}

};

int main(){
	Array<float> List(2);
	List.insertElement(0, 1.23);
	List.insertElement(1, 3.54);
	List.insertElement(2, 4.5);
	
	if(List.search(3))
		cout << "Present in an array" << endl;
	else
		cout << "Not Present in an array" << endl;

	List.getArray();
}