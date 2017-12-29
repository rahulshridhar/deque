/*----------------------------------------------------------------
file: ddeque.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ddeque class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ddeque_H
#define ddeque_H

#include "../util/util.h"
#include "../darray/darray.h"

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
template <typename T>
class ddeque;

template <typename T>
class ddeque_iterator;

/*--------------------------------------------------------
typename ddeque iterator
----------------------------------------------------------*/
template <typename T>
class ddeque_iterator {
public:
    ddeque_iterator(T* front_queue = 0, int front = 0, T *rear_queue = 0, int rear = 0, T* current=0): _current(current), _fq(front_queue), _front(front), _rq(rear_queue), _rear(rear) {}
    ~ddeque_iterator() {}

    // *(itt)
    T& operator*() const {
        return *(_current);    
    }

    //++itt
    ddeque_iterator& operator++() {
        if (_front > 0)
        {
            --_current;
            _front--;
            return *this;
        }
        else if (_front == 0)
        {
            _current = _rq;
            _front--;
            return *this;
        }
        else 
        {
            ++_current;
            //_rear++;
            return *this;
        }
    }
    
    //--itt
    ddeque_iterator& operator--() {
        if (_rear > 0)
        {
            --_current;
            _rear--;
            return *this;
        }
        else if (_rear == 0) 
        {
            _current = _fq;
            _rear--;
            return *this;
        }
        else
        {
            ++_current;
            //_front++;
            return *this;
        }
    }

    //if (itt != x.end())
    bool operator!=(const ddeque_iterator& rhs){
        return (_current != rhs._current);
    }

private:
    T* _current;
    T* _fq;;
    int _front;
    T* _rq;
    int _rear;
};

/*--------------------------------------------------------
class ddeque
----------------------------------------------------------*/
template <typename T>
class ddeque {
public:
  /* WRITE ALL PUBLIC FUNCTION HERE */
  /* CANNOT HAVE ANY PUBLIC DATA HERE */
  typedef ddeque_iterator<T> iterator;
  explicit ddeque(int capacity = 50, bool d = false);
  ~ddeque();
  T& operator[](int i);

  iterator begin() { return iterator(&_ddeque_front[_front-1], _front-1, &_ddeque_rear[_rear_first], _rear_first, &_ddeque_front[_front-1]); }
  iterator end() { return iterator(&_ddeque_front[_front_last], _front_last, &_ddeque_rear[_rear], _rear, &_ddeque_rear[_rear]); }
  int size() const;
  bool empty() const;
  void push_front(const T& b);  //add element to the front
  void push_back(const T& b);   //add element to the back
  T& front();                   //Get front by alias
  T& back();                    //Get back by alias
  void pop_front();             //Remove element at the front of the queue
  void pop_back();              //Remove element at the end of the queue

  bool display() const { return _display; }
  void set_display(bool x) {
    darray<T>::set_display(x);
    _display = x;
  }

private:
  bool _display;
  darray<T> _ddeque_front;
  darray<T> _ddeque_rear;
  int _front;
  int _front_last;
  int _rear;
  int _rear_first;

  /* CAN HAVE ANY PRIVATE FUNCION */
  void _put(int pos, const T& a);
};

#include "ddeque.hpp"

#endif
//EOF

