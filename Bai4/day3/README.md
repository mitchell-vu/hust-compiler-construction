# BUỔI THỰC HÀNH 4 - SEMANTICS ANALYSIS Day 3

## Chạy chương trình

Install make hay Cmake, thêm PATH vào enviroment variables

Chuyển directory vào folder `Bai4/day3/incompleted`

```bash
cd Bai4/day3/incompleted
```

Chạy Make để compile project kèm libraries
Chọn file test đi kèm với parser

Với MacOS/Linux

```bash
make
```

Với Windows

```bash
mingw32-make
```

Chạy chương trình kplc

Với MacOS/Linux

```bash
./kplc ../tests/<example_name>.kpl
```

Với Windows

```bash
./kplc.exe ../tests/<example_name>.kpl
```

Đối chiếu kết quả với `result.txt`

## File `semantics.c`

- Kiểm tra tính hợp lệ của tên const, var, type.
  Tên hợp lệ khi khai báo object đó **không bị lặp lại** trong cùng một scope
- Kiểm tra tham chiếu tới các object

Di chuyển hàm `lookupObject()` từ `parser.c`

```c
Object* lookupObject(char *name) {
  // Giống hệt parser.c day1
}
```

### Validate tên của object khi declare

Trước khi tạo Object thì đều phải `checkFreshIdent()`

```c
void checkFreshIdent(char *name);
Object* checkDeclaredIdent(char *name);
```

### Kiểm tra tham chiếu tới các object

Check đã khai báo chưa

```txt
Const MYAGE: 12
      HISAGE: MYAGE

Var N: Integer;
Begin
  For N:= 1 To 9 Do ...
End.
```

Migrate ở `parser.c` day 2:
Phần xem reference IDENT đã được khai báo chưa
Những hàm dưới đơn giản là `lookupObject()` rồi báo lỗi nếu có

```c
Object* checkDeclaredConstant(char *name);
Object* checkDeclaredType(char *name);
Object* checkDeclaredVariable(char *name);
Object* checkDeclaredFunction(char *name);
Object* checkDeclaredProcedure(char *name);

// Check vế trái của assign statement
Object* checkDeclaredLValueIdent(char *name);
```

```c
Object* checkDeclaredLValueIdent(char* name) {
  Object *obj = lookupObject(name);
  // ...

  switch (obj->kind) {
    case OBJ_VARIABLE:
    case OBJ_PARAMETER:
      break;
    case OBJ_FUNCTION:
      if (obj != symtab->currentScope->owner)
        error(ERR_INVALID_IDENT, currentToken->lineNo, currentToken->colNo);
      break;
    default:
      error(ERR_INVALID_IDENT, currentToken->lineNo, currentToken->colNo);
  }

  return obj;
}
```