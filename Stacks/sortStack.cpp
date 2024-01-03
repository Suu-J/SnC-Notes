#include<bits/stdc++.h>
using namespace std;


//to be able to sort a stack we must know how to insert element in a sorted stack
void insertSorted(stack<int> &st, int &val){
	if(st.empty()||val>= st.top()){
		st.push(val);
		return;
	}

	int temp = st.top(); st.pop();
	insertSorted(st,val);

	st.push(temp);
}

void sortStack(stack<int> &st){
	if(st.empty()){
		return;
	}
	int temp = st.top(); st.pop();
	sortStack(st);

	insertSorted(st,temp);

}


void print(stack<int> st){
	while (!st.empty()) {
        cout << st.top() <<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
	stack<int> st;
	st.push(40);
	st.push(30);
	st.push(50);
	st.push(20);
	st.push(60);
	st.push(10);

	print(st);
	sortStack(st);
	print(st);


}