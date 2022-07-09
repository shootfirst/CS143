#include <assert.h>
#include <stdio.h>
#include "emit.h"
#include "cool-tree.h"
#include "symtab.h"
#include <vector>
#include <unordered_map>

enum Basicness     {Basic, NotBasic};
#define TRUE 1
#define FALSE 0

class CgenClassTable;
typedef CgenClassTable *CgenClassTableP;

class CgenNode;
typedef CgenNode *CgenNodeP;

enum class BASE_LOC_TYPE {
   SELF_,
   FP_
};

struct Loc {
   BASE_LOC_TYPE base_loc;
   int offset;
};

// after the semantic analysis, we can simply use stack to implement scope without worry
template<typename K, typename V>
class SymbolTbl {
private:
   std::vector<std::unordered_map<K, V>> sym_tab;

public:
   void addKV(const K& k, const V& v) {
      assert(!sym_tab.empty());
      assert(sym_tab.back().find(k) == sym_tab.back().end());
      sym_tab.back()[k] = v;
   };

   V lookUp(const K& k) {
      for (auto it = sym_tab.rbegin(); it != sym_tab.rend(); ++it) {
         if (it->find(k) != it->end()) {
            return (*it)[k];
         }
      }
      std::cerr << "Can not find the symbol! " << k << std::endl;
      exit(1);
   };

   void enterScope() {
      sym_tab.push_back({});
   };

   void exitScope() {
      assert(!sym_tab.empty());
      sym_tab.pop_back();
   };
};



class CgenClassTable : public SymbolTable<Symbol,CgenNode> {
private:
   List<CgenNode> *nds;
   ostream& str;
   int stringclasstag;
   int intclasstag;
   int boolclasstag;
   
// my add
   CgenNodeP cur_class;

   std::unordered_map<Symbol, std::pair<int, int>> subclass_idrange;
   std::vector<Symbol> tag_to_class;
   std::unordered_map<Symbol, int> class_depth;

   SymbolTbl<Symbol, Loc> sym_tbl;

   std::unordered_map<Symbol, std::unordered_map<Symbol, int>> attr_off;
   std::unordered_map<Symbol, std::unordered_map<Symbol, int>> method_off;

   int labbelid {0};

   int loc_var_off {-3};
   
// The following methods emit code for
// constants and global declarations.

   void code_global_data();
   void code_global_text();
   void code_bools(int);
   void code_select_gc();
   void code_constants();

// my add
   void set_class_tag_internal(CgenNodeP cur, int cur_dep);
   void set_tag();
   void generate_class_nameTab();
   void generate_classObj_tab();
   void generate_one_dispatch_table(CgenNodeP cur_class, std::ostream& str);
   void generate_dispatch_tables();
   std::vector<std::pair<Symbol, Symbol>> collect_all_attr(CgenNodeP cur);
   void generate_prototype_obj();
   void class_init();
   void class_method();
   
   
   
   
   SymbolTbl<Symbol, Loc> getSymbolTbl() { return sym_tbl; };
   
// The following creates an inheritance graph from
// a list of classes.  The graph is implemented as
// a tree of `CgenNode', and class names are placed
// in the base class symbol table.

   void install_basic_classes();
   void install_class(CgenNodeP nd);
   void install_classes(Classes cs);
   void build_inheritance_tree();
   void set_relations(CgenNodeP nd);
public:
   CgenClassTable(Classes, ostream& str);
   void code();
   CgenNodeP root();

   // my add
   void addSym(Symbol class_name, BASE_LOC_TYPE _type, int offset) { sym_tbl.addKV(class_name, {_type, offset}); };
   void enterScope() { sym_tbl.enterScope(); };
   void exitScope() { sym_tbl.exitScope(); };
   Loc lookUpSym(Symbol attr_name) { return sym_tbl.lookUp(attr_name); };
   int get_last_labelid() { return labbelid ++; };
   int push_new_var() { return loc_var_off--; };
   void pop_new_var(int num) { loc_var_off += num; };
   int get_method_off(Symbol class_name, Symbol method_name);
   void setCurClass(CgenNodeP _cur_class) { cur_class = _cur_class; };
   CgenNodeP getCurClass() { return cur_class; };

   std::pair<int, int> get_subclass_idrang(Symbol class_name) {
      assert(subclass_idrange.find(class_name) != subclass_idrange.end());
      return subclass_idrange[class_name];
   }
   
   int get_depth(Symbol class_name) {
      assert(class_depth.find(class_name) != class_depth.end());
      return class_depth[class_name];
   }


};

   








class CgenNode : public class__class {
private: 
   CgenNodeP parentnd;                        // Parent of class
   List<CgenNode> *children;                  // Children of class
   Basicness basic_status;                    // `Basic' if class is basic
                                              // `NotBasic' otherwise

public:
   CgenNode(Class_ c,
            Basicness bstatus,
            CgenClassTableP class_table);

   void add_child(CgenNodeP child);
   List<CgenNode> *get_children() { return children; }
   void set_parentnd(CgenNodeP p);
   CgenNodeP get_parentnd() { return parentnd; }
   int basic() { return (basic_status == Basic); }
   
};

class BoolConst 
{
 private: 
  int val;
 public:
  BoolConst(int);
  void code_def(ostream&, int boolclasstag);
  void code_ref(ostream&) const;
};

