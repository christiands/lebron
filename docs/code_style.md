## Object Creation/Deletion
- Any stack allocated objects use the command verb "make" for construction
- Any heap allocated objects use the command verbs "create" and "delete" for construction/destruction
- Any object which requires a destructor should be implemented on the stack
- Heap constructors are placement, to differentiate allocation schemes