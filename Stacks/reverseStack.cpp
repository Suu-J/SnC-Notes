#include<bits/stdc++.h>
using namespace std;


//to be able to reverse a stack, we must know how to insert at Bottom
void insertAtBottom(stack<int> &st, int &val){
	if(st.empty()){
		st.push(val);
		return;
	}
	//one case
	int temp = st.top(); st.pop();

	//recursive call
	insertAtBottom(st,val);

	//backtrack
	st.push(temp);
}

void reverse(stack<int> &st){
	if(st.empty()){
		return;
	}
	int val = st.top(); st.pop();
	reverse(st);
	insertAtBottom(st,val);
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
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);

	print(st);
	reverse(st);
	print(st);


}