#!/usr/bin/python

a = 'scope: global'
def A():
   a = 'scope: A'
   print locals()
   print globals()
   def B():
      a = 'scope: B'
      print locals()
      print globals()
   print locals()
   print globals()
   
A()      
