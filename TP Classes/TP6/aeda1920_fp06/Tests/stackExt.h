# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
    stack<T> st;
    stack<T> min;

public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};

// a alterar
template <class T> 
bool StackExt<T>::empty() const
{
	return st.empty();
}

//a alterar
template <class T> 
T& StackExt<T>::top()
{
    T *novo = new T();
    *novo = st.top();
    return *novo;
}

//a alterar
template <class T> 
void StackExt<T>::pop(){

    T x = st.top();
    st.pop();
    if(!min.empty() && min.top() == x) min.pop();
}

//a alterar
template <class T> 
void StackExt<T>::push(const T & val)
{
    if(st.empty()) min.push(val);
    st.push(val);
    if(val < min.top()){
        min.push(val);
    }
}

//a alterar
template <class T> 
T& StackExt<T>::findMin()
{
    return min.top();
}

