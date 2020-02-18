#pragma once
template<typename T>
class Stack
{
	int Top;
	int Capacity;
	T *ptr;
	bool isFixed;
	//Grow the Stack by double Capacity and copy 
	void GrowStack()
	{
		T *temp = new T[Capacity * 2];
		for (int i = 0; i < Capacity; i++)
		{
			temp[i] = ptr[i];
		}
		delete []ptr;
		Capacity *= 2;
		ptr = temp;
		temp = nullptr;
	}
public:
	Stack()
	{
		isFixed = false;
		Capacity = 1;
		ptr = new T[Capacity];
		Top = -1;
		
	}
	Stack(int Size)
	{
		isFixed = true;
		Capacity = Size;
		ptr = new T[Capacity];
		Top = -1;
	}
	//Tell if the Stack is full or not
	bool isFull()
	{
		return Top == (Capacity-1);
	}
	//Tell if the Stack is empty or not
	bool isEmpty()
	{
		return Top == -1;
	}
	/*Place an item on to the stack. If there is no place for new item then check whether Stack is fixed or not,
	If Stack is fixed it "Stack overflow" exception else increase capacity and place that item.*/
	void Push(T Value)
	{
		if (isFixed == true)
		{
			try
			{
				if (isFull())
				{
					throw(ptr);
				}
				else
				{
					ptr[++Top] = Value;
				}
			}
			catch (int *ptr)
			{
				cout << "Stack overflow" << endl;
			}
			
		}
		else
		{
			if (isFull())
			{
				GrowStack();
				ptr[++Top] = Value;
			}
			else
			{
				ptr[++Top] = Value;
			}
		}
	}
	/*Return the item at the top of the stack and then remove it. 
	if Pop is called when stack is empty it will throw "Stack underflow" exception*/
	T Pop()
	{
		try
		{
			if (isEmpty())
				throw (ptr);
			else
			{
				return ptr[Top--];
			}
		}
		catch (T *ptr)
		{
			cout << "Stack underflow" << endl;
		}
	}
	//Access the item at given position
	T peek(int Position)
	{
		try
		{
			if (isEmpty())
				throw (ptr);
			else
			if (Position - 1 > Top || Position - 1 < 0)
				throw (Position);
			else
			{
				return ptr[Position-1];
			}
		}
		catch (T *ptr)
		{
			cout << "Stack underflow" << endl;
		}
		catch (int Position)
		{
			cout << "Invalid position" << endl;
		}
	}
	//Get the number of items in the stack
	int Count()
	{
		return Top + 1;
	}
	//Change the item at the given position
	void Change(int Position,int Value)
	{
		try
		{
			if (isEmpty())
				throw (ptr);
			else
			if (Position - 1 > Top || Position - 1 < 0)
				throw (Position);
			else
			{
				return ptr[Position - 1] = Value;
			}
		}
		catch (T *ptr)
		{
			cout << "Stack underflow" << endl;
		}
		catch (int Position)
		{
			cout << "Invalid position" << endl;
		}
	}
	//Display all items in the stack
	void Display()
	{
		for (int i = Top; i >= 0; i--)
		{
			cout << ptr[i] << endl;
		}
	}
	//Convert flexible/growable stack to fixed stack
	void Fixed()
	{
		if (isFixed == false)
			isFixed = true;
	}
	//Covert fixed stack to growable stack
	void NotFixed()
	{
		if (isFixed == true)
			isFixed = false;
	}
	~Stack()
	{

	}
};

