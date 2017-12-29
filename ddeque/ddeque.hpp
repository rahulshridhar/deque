/*----------------------------------------------------------------
file: ddeque.hpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Constructor
-----------------------------------------------------------------*/
template <typename T>
ddeque<T>::ddeque(int c, bool d): _display(d), _ddeque_front(c, d), _ddeque_rear(c, d), _front(0), _rear(0), _front_last(0), _rear_first(0)
{
    if (display()) {
        cout<<"In ddeque constructor:"<<endl;
    }
}

/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
template <typename T>
ddeque<T>::~ddeque()
{
    if (display()) {
        cout<<"In ddeque destructor:"<<endl;
    }
    _front = 0;
    _rear = 0;
}

/*----------------------------------------------------------------
[] operator
-----------------------------------------------------------------*/
template <typename T>
T& ddeque<T>::operator[](int i)
{
    if (i < 0) {
        assert(0);
    }
    if (i < _front) return _ddeque_front[(_front-1)-i];
    else if (_front == 0) return _ddeque_rear[i];
    else if (i >= _front) return _ddeque_rear[i - _front];
}

/*----------------------------------------------------------------
Get size of the ddeque
-----------------------------------------------------------------*/
template <typename T>
int ddeque<T>::size() const
{
    return _front + _rear;
}

/*----------------------------------------------------------------
Check if the ddeque is empty
-----------------------------------------------------------------*/
template <typename T>
bool ddeque<T>::empty() const
{
    return (_front == 0 && _rear == 0);
}

/*----------------------------------------------------------------
Push to the front of the deque
-----------------------------------------------------------------*/
template <typename T>
void ddeque<T>::push_front(const T& b)
{
    _ddeque_front[_front++] = b; 
}


/*----------------------------------------------------------------
Push to the back of the deque
-----------------------------------------------------------------*/
template <typename T>
void ddeque<T>::push_back(const T& b)
{
    _ddeque_rear[_rear++] = b;
}

/*----------------------------------------------------------------
Get the front of the deque by alias
-----------------------------------------------------------------*/
template <typename T>
T& ddeque<T>::front()
{
    if (empty()) {
        assert(0);
    }
    if (_front) return (_ddeque_front[_front-1]);
    else return (_ddeque_rear[_rear_first]);
}

/*----------------------------------------------------------------
Get the back of the deque by alias
-----------------------------------------------------------------*/
template <typename T>
T& ddeque<T>::back()
{
    if (empty()) {
        assert(0);
    }
    if (_rear) return (_ddeque_rear[_rear-1]);
    else return (_ddeque_front[_front_last]);
}

/*----------------------------------------------------------------
Remove an element from the front of the deque
-----------------------------------------------------------------*/
template <typename T>
void ddeque<T>::pop_front()
{
    if (empty()) {
        assert(0);
    }
    if (_front) _front--;
    else _rear_first++; 
}

/*----------------------------------------------------------------
Remove an element from the back of the deque
-----------------------------------------------------------------*/
template <typename T>
void ddeque<T>::pop_back()
{
    if (empty()) {
        assert(0);
    }
    if (_rear) _rear--;
    else _front_last++;
}


//EOF


