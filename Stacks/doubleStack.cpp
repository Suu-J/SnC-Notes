#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
	int* arr;
	int top1;
	int top2;
	int size;

	Stack(int size){
		this->size = size;
		top1 = -1;
		top2 = size;
		arr = new int[size];
	}

	void push1(int data){
		//when they are adjacent basically
		if(top2 - top1 == 1){
			cout<<"stack 1 overflow"<<endl;
			return;
		}
		top1++;
		arr[top1] = data;

	}

	void push2(int data){
		//when they are adjacent basically
		if(top2 - top1 == 1){
			cout<<"stack 2 overflow"<<endl;
			return;
		}
		top2--;
		arr[top2] = data;
	}

	void pop1(){
		if(top1==-1){
			cout<<"stack1 is empty"<<endl;
			return;
		}
		top1--;
	}

	void pop2(){
		if(top2==size){
			cout<<"stack2 is empty"<<endl;
			return;
		}
		top2++;
	}

	void peek1(){
		if(top1==-1){
			cout<<"stack1 is empty"<<endl;
			return;
		}
		cout<<arr[top1]<<endl;
	}

	void peek2(){
		if(top2==size){
			cout<<"stack2 is empty"<<endl;
			return;
		}
		cout<<arr[top2]<<endl;
	}

	void printAll(){
		for(int i = 0; i<size; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	void printStack1(){
		for(int i = 0; i<=top1; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	void printStack2(){
		for(int i = size-1; i>=top2; i--){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	Stack st(6);
	st.push1(5);
	st.push1(4);
	st.push1(3);
	st.push1(1);
	st.push2(99);
	st.push2(9);
	// st.push2(100);
	st.printAll();
	st.printStack1();
	st.printStack2();

}