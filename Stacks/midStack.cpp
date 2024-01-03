#include<bits/stdc++.h>
using namespace std;


//helper function for deletemiddle
void deleteMid(stack<int> &st, int &pos){
	if(pos==1){
		st.pop();
		return;
	}

	//solving 1 case
	pos--;
	int temp = st.top(); st.pop();
	deleteMid(st,pos);

	//backtrack and insert other elements
	st.push(temp);
}

void deleteMiddle(stack<int> &st){
	int size = st.size();
	if(size == 0){
		cout<<"Stack is empty"<<endl;
		return;
	}
	//odd case
	int pos = 0;
	if(size & 1){
		pos = size/2 + 1;
	}else{ //even case
		pos = size/2;
	}
	deleteMid(st,pos);
	
}

//helper function for find middle
int solve ( stack<int> &st, int &pos){

	if(pos==1){
		return st.top();
	}

	//solving 1 case
	pos--;
	int temp = st.top(); st.pop();
	int res = solve(st,pos);

	//backtrack to insert element back
	st.push(temp);

	return res;
}


int findMiddle(stack<int> &st){
	int size = st.size();
	if(size == 0) return -1;

	//odd case
	int pos = 0;
	if(size & 1){
		pos = size/2 + 1;
	}else{ //even case
		pos = size/2;
	}
	int ans = solve(st,pos);
	return ans;
}


int main(){
	stack<int>st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);

	int mid = findMiddle(st);
	cout<<"Middle element is=> "<<mid<<endl;

	deleteMiddle(st);
	cout<<"After removing middle element\n";
	while (!st.empty()) {
        cout << st.top() <<" ";
        st.pop();
    }

}