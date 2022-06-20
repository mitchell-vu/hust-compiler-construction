# BUỔI THỰC HÀNH 4 - SEMANTICS ANALYSIS Day 1

## Chạy chương trình

Install make hay Cmake, thêm PATH vào enviroment variables

Chuyển directory vào folder `Bai4/day1/incompleted`

```bash
cd Bai4/day1/incompleted
```

Chạy Make để compile project kèm libraries
Chọn file test đi kèm với parser

Với MacOS/Linux

```bash
make
./symtab
```

Với Windows

```bash
mingw32-make
./symtab.exe
```

Chương trình sẽ in ra một symbol table có cấu trúc như ở [outcome](#outcome---day-1)

## About Semantics Analysis

Phân tích cú pháp chỉ kiểm tra cấu trúc ngữ pháp hợp lệ của chương trình
Trả lời cho các câu hỏi:
> `x` là tên variable hay function?

> `x` đã được declared hay defined chưa?

> `x` được declared ở đâu?

> Biểu thức `a + b` có nhất quán về type không?

### Nhiệm vụ của Semantics Analyzer

- **Quản lý** thông tin về identifier
  - Hằng
  - Biến
  - Custom type của người dùng
  - Procedure/Function

- Kiểm tra Semantic rules
  - **Scope** của identifier
  - Nhất quán về type

## Outcome - Day 1

Hoàn thành những function được đánh dấu `TODO` trong `symtab.c`

### Symbol Table

Với một chương trình KPL như dưới

```txt
PROGRAM test;

CONST c = 100;
TYPE t = Integer;
VAR v : t;

FUNCTION f(x : t) : t;
VAR y : t;
BEGIN
    y := x + 1;
    f := y;

END;

BEGIN
    v := 1;
    WriteLn (f(v));
END.
```

Sẽ cho ra được một bảng ký hiệu `symtab`

```txt
test : PRG
|
|-- c : CST = 100
|-- t : TY = INT
|-- v : VAR : INT
|-- f : FN: INT -> INT
    |
    |-- x :  PAR : INT
    |-- y :  VAR : INT
```

#### Structure

```c
struct SymTab_ {
    // Chương trình chính
    Object* program;

    // Phạm vi hiện tại
    Scope* currentScope;

    // Các đối tượng toàn cục như
    // hàm WRITEI, WRITEC, WRITELN, READI, READC
    ObjectNode *globalObjectList;
};
```

Vậy Scope contain những gì?

```c
struct Scope_ {
    // Danh sách objects trong block
    ObjectNode *objList;

    // Func/Prod/Program tương ứng block
    Object *owner;

    // Phạm vi bao ngoài
    // để có thể comeback khi thoát block
    struct Scope_ *outer;
};
```

#### Làm việc với Scope

Mỗi khi ra vào một function/procedure
Thì phải thoát/nhập Block để update biến `currentScope`

```c
void enterBlock(Scope* scope);
void exitBlock(void);
```

Đăng ký một đối tượng vào block hiện tại

```c
void declareObject(Object* obj);
```

### Object

Attribute sẽ được gọi khi tạo object ở `obj->typeAttrs`

```c
struct ConstantAttributes_ {
    ConstantValue* value;
};

struct VariableAttributes_ {
    Type *type;
    // Phạm vi của biến (sử dụng cho phase sinh mã)
    struct Scope_ *scope;
};

struct TypeAttributes_ {
    Type *actualType;
};

struct ParameterAttributes_ {
    // Tham biến hoặc tham trị
    enum ParamKind kind;
    Type* type;
    struct Object_ *function;
};

struct ProcedureAttributes_ {
    struct ObjectNode_ *paramList;
    struct Scope_* scope;
};

struct FunctionAttributes_ {
    struct ObjectNode_ *paramList;
    Type* returnType;
    struct Scope_ *scope;
};

struct ProgramAttributes_ {
    struct Scope_ *scope;
};
```

### Tạo object

Khi tạo object thì sẽ gắn một object:

- Kind: `OBJ_CONSTANT`/`OBJ_TYPE`/`OBJ_VARIABLE`/...
- Attribute: `constAttrs`/`typeAttrs`/`varAttrs`/...
- Scope: Đối với Variable, Func/Proc
- Param List: Cho Func/Proc (Param cũng là một object)
-> Param cần gắn thêm `owner`

```c
Object* createConstantObject(char *name);
Object* createTypeObject(char *name);
Object* createVariableObject(char *name);
Object* createParameterObject(
    char *name,
    enum ParamKind kind,
    Object* owner
);
```

```c
Object* createFunctionObject(char *name);
Object* createProcedureObject(char *name);
Object* createProgramObject(char *name);
```

### Free memory

Các functions free dùng để giải phóng các loại dữ liệu symtab
Được tổng hợp lại ở function `cleanSymTab`

```c
void cleanSymTab(void) {
  freeObject(symtab->program);
  freeObjectList(symtab->globalObjectList);
  free(symtab);
  freeType(intType);
  freeType(charType);
}
```

Các function được sử dụng trong `freeObject()`

```c
// Giải phóng danh sách đối tượng reference
void freeReferenceList(ObjectNode* objList)
// Giải phóng block
void freeScope(Scope* scope)
```
