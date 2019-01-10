//! @file dido.h
//! @author caohw
//! @brief efficent dido(dual in dual out) by ring link

#ifndef __dido_H__
#define __dido_H__

#include <cassert>

//  
//    _back --> _back->last --> .... _front
//       ^                             |
//       |                             v
//       ............<---_front->last---
//

#define DIDO_ASSERT(x) //assert(x)

template<class T> 
class dido 
{
public:
  dido() : _front(new link), _back(_front), _cap(0) {assert(_back); _back->last = _front; _front->next = _back;}
  ~dido() {for (auto i = _back->last; i != _back;) {assert(i->last->next == i); const auto n = i->last; delete i; i = n; _cap--;} assert(_cap ==0); delete _front;}
  
  void clear() {_back = _front;}
  bool empty() const {return _back == _front;}
  unsigned capacity() const {return _cap;}
  T& front()       {assert(!empty()); DIDO_ASSERT(_front->next->last == _front); return _front->next->val;}
  T& back()        {assert(!empty()); DIDO_ASSERT(_back ->last->next == _back ); return _back->val;}
  void pop_front() {assert(!empty()); DIDO_ASSERT(_front->next->last == _front); _front = _front->next;}
  void pop_back () {assert(!empty()); DIDO_ASSERT(_back ->last->next == _back ); _back  = _back ->last;}
  void push_front(const T& t) {DIDO_ASSERT(_front); _front->val = t; if (_front->last == _back ) {_front->last = _back->next = new link(_front, _back); assert(_front->last); assert(_front->last->next == _front); assert(_back->next->last == _back); _cap++;} _front = _front->last;}
  void push_back (const T& t) {DIDO_ASSERT(_back );                  if (_back ->next == _front) {_back->next = _front->last = new link(_front, _back); assert(_back ->next); assert(_front->last->next == _front); assert(_back->next->last == _back); _cap++;} _back  = _back ->next; _back->val = t;}

private:
  class link 
  {
  public:
    link(link* n =0, link* l =0) : val(), next(n), last(l) {} 
    T     val;
    link* next;
    link* last;
  };
  link*    _front;
  link*    _back;
  unsigned _cap;
};


#endif
