#include <assert.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#include "emit.h"
#include "cool-tree.h"
#include "symtab.h"

enum Basicness     {Basic, NotBasic};
#define TRUE 1
#define FALSE 0

class CgenClassTable;
typedef CgenClassTable *CgenClassTableP;

class CgenNode;
typedef CgenNode *CgenNodeP;

template<typename K, typename V>
class SymbolTab {
private:
   std::vector<std::unordered_map<K, V>> data;

public:
   void enterScope() {
      data.push_back({});
   }

   void exitScope() {
      assert(!data.empty());
      data.pop_back();
   }

   V lookUp(const K& k) {
      for (auto it = data.rbegin(); it != data.rend(); ++it) {
         if (it->find(k) != it->end()) {
            return (*it)[k];
         }
      }
      std::cerr << "Can not find the symbol! " << k << std::endl;
      exit(1);
   }

   void addKV(const K& k, const V& v) {
      assert(data.back().find(k) == data.back().end());
      data.back()[k] = v;
   }
};



enum class BASE_LOC_TYPE {
   SELF_,
   FP_
};

struct Loc {
   BASE_LOC_TYPE base_loc;
   int offset;
};



class CgenClassTable : public SymbolTable<Symbol,CgenNode> {
private:
   List<CgenNode> *nds;
   ostream& str;
   int stringclasstag;
   int intclasstag;
   int boolclasstag;


   

   // offset for Self
   std::unordered_map<Symbol, std::unordered_map<Symbol, int>> attr2offset_map;
   
   // offset for dispatch tab
   std::unordered_map<Symbol, std::unordered_map<Symbol, int>> method2offset_map;

   // for jump instruction
   int label_id{0};

   // this used for generate case code
   std::unordered_map<Symbol, std::pair<int, int>> class_tag_range;

   // each class has one class tag
   std::vector<Symbol> tag_to_class;


   // The following methods emit code for
// constants and global declarations.

   void code_global_data();
   void code_global_text();
   void code_bools(int);
   void code_select_gc();
   void code_constants();
   void set_class_tag();
   void set_class_tag_internal(CgenNodeP cur, int cur_dep);




   // my add 
   void generate_name_tab();
   void generate_objTab();
   void generate_dispatchTab();
   void generate_dispatchTab_for_each_class(CgenNodeP cur, std::ostream& str);
   std::vector<std::pair<Symbol, Symbol>> collect_all_attr(CgenNodeP cur);
   void generate_protObj();


   void prepare_class_init();
   void generate_method_code();
   // my add end

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

   int get_method_offset(Symbol class_name, Symbol method_name);
   int get_next_labelid() {
      return label_id++;
   }
   std::pair<int, int> get_subclass_idrang(Symbol class_name) {
      assert(class_tag_range.find(class_name) != class_tag_range.end());
      return class_tag_range[class_name];
   }


private:
   int loc_var_offset = -3;

public:

   int push_variable() { return loc_var_offset--; }

   void pop_variable(int num) { loc_var_offset += num; }

   






private:
   SymbolTab<Symbol, Loc> symbol_to_loc;
public:
   Loc getSymbolLoc(Symbol name) {
      return symbol_to_loc.lookUp(name);
   }

   SymbolTab<Symbol, Loc>& getSymbolToLoc() {
      return symbol_to_loc;
   }

   void addSymbol(Symbol name, BASE_LOC_TYPE type_, int offset) {
      symbol_to_loc.addKV(name, {type_, offset});
   }

   void enterScope() {
      symbol_to_loc.enterScope();
   }

   void exitScope() { symbol_to_loc.exitScope(); }


private:
   std::unordered_map<Symbol, int> class_depth;

public:
   int get_depth(Symbol class_name) {
      assert(class_depth.find(class_name) != class_depth.end());
      return class_depth[class_name];
   }


private:
   CgenNodeP cur_class;

public:
   void setCurClass(CgenNodeP cur_class_) { cur_class = cur_class_; }

   CgenNodeP getCurClass() { return cur_class; }






};








// my add end


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

