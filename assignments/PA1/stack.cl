(*
 *  CS164 Fall 94
 *
 *  Programming Assignment 1
 *    Implementation of a simple stack machine.
 *
 *  Skeleton file
 *)

 
class Main inherits IO {

   store : Stack <- new Stack;
   is_loop : Bool <- true;

   execute(s : String) : Object {
      if s = "e" then
         store <- store.evaluate()
      else if s = "d" then
         store.display(store)
      else if s = "x" then
         is_loop <- false
      else
         store <- store.push(s)
      fi (*x*)
      fi (*d*)
      fi (*e*)
   };

   main() : Object {
      {
         let s : String in {
            while (is_loop) loop {
               out_string(">");
               s <- in_string();
               execute(s);
            }
            pool;
         };
      }
   };

};


class Stack inherits A2I {
   item : String;
   next : Stack;

   evaluate() : Stack {
      if item = "+" then
         let st0 : Stack <- next() in 
         let st1 : Stack <- st0.next() in 
         let i1 : Int <- a2i(st0.item()) in 
         let i2 : Int <- a2i(st1.item()) in 
         let st2 : Stack <- st1.next() in 
         st2.push(i2a(i1 + i2))
      else if item = "s" then
         let st0 : Stack <- next() in 
         let st1 : Stack <- st0.next() in 
         let s1 : String <- st0.item() in
         let s2 : String <- st1.item() in
         let st2 : Stack <- st1.next() in
         st2.push(s1).push(s2)
      else 
         self
      fi (*s*)
      fi (*+*)                  
   };

   display(st : Stack) : Object {
      if st.item() = "" then 
         1
      else {
         while (not isvoid st) loop {
            (new IO).out_string(st.item());
            (new IO).out_string("\n");
            st <- st.next();
         }
         pool;
      }
      fi
   };

   push(s : String) : Stack {
      if isvoid self then {
         item <- s;
         self;
      }    
      else
         let st : Stack <- new Stack in {
            
            st.set_item(s);
            st.set_next(self);
            st;
         }
      fi 
   };

   item() : String {
      item
   };

   next() : Stack {
      next
   };

   set_item(s : String) : Object {
      item <- s
   };

   set_next(st : Stack) : Object {
      next <- st
   };
};


