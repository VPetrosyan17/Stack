#include <iostream>

template <typename T>
//Stack implementation
class Stack{
	public:
	//constructor, destructor
	Stack() : m_top{-1}, arr{new T[MAX]} {}

	~Stack(){
		delete[] arr;
	}

	//check whether stack is empty
	bool isEmpty() const {
		return m_top == -1;
	}

	// return the last element of the stack
	T top(){
		if(isEmpty()){
			throw std::underflow_error("Stack is empty!");
		}
		return arr[m_top];
	}
	
	//adding elememt to the stack
	void push(const T& value){
		if(m_top + 1 < MAX){
			++m_top;
			arr[m_top] = value;
		}else{
			throw std::overflow_error("Stack overflow!");
		}
	}
		
	// removing element from the stack
	void pop(){
		if(!isEmpty()){
			--m_top;
		}
	}
	
	private:
	static const int MAX = 1000;
	T* arr;
	T m_top;
};

int main(){
	Stack<int> myStack;

	myStack.push(10);
	myStack.push(20);
	myStack.push(5);

	myStack.pop();

	std::cout << myStack.top();
}
