# BUỔI THỰC HÀNH 4 - SEMANTICS ANALYSIS Day 2

- Day 1 thì không dùng `parser` và thao tác symtab ở trong `main.c`
- Day 2 sẽ chuyển những phần khai báo object trong `main.c` của Day 1 vào `parser`

## Chạy chương trình

Install make hay Cmake, thêm PATH vào enviroment variables

Chuyển directory vào folder `Bai4/day2/incompleted`

```bash
cd Bai4/day2/incompleted
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

## Xây dựng Symbol Table

### Khai báo Object

```c
enum ObjectKind {
  OBJ_CONSTANT,
  OBJ_VARIABLE,
  OBJ_TYPE,
  OBJ_FUNCTION,
  OBJ_PROCEDURE,
  OBJ_PARAMETER,
  OBJ_PROGRAM
};
```

Sau khi tạo các loại Object trên thì sẽ phải `declareObject()`
(OBJ_PROGRAM gọi `declareObject()` ở Block 5)

`declareObject()` check xem object đấy có phải là param của func/prod không?
Sau đấy sẽ `addObject()`

```c
void declareObject(Object* obj)
void addObject(ObjectNode **objList, Object* obj) {
  // Tạo thêm một node ở cuối linked list
  // Nếu object là param thì sẽ add vào paramList của func/prod
  // Nếu không thì add vào currentScope
  // ...
}
```

Kết quả chỉ trả ra scope những biến khi declare chứ chưa thể hiện biến được dùng như thế nào, giá trị bao nhiêu

### Giá trị của hằng, biến

Mỗi function compile các hằng, biến trong parser thì return giá trị của hằng, biến đấy

```c
ConstantValue* compileConstant(void) {
  ConstantValue* constValue;
  // ...
  return 
}
```

### Tìm Object

Các const, biến mà declare lúc đầu luôn có mức ưu tiên cao nhất

```c
Object* lookupObject(char *name) {
  // Tìm trong currentScope
  // Dùng findObject nhận currentScope làm list
  // Nếu không có thì chuyển ra scope ngoài

  // Tìm biến trong global scope
  // (READC, READI, WRITEI, WRITEC, WRITELN)
  // ...
}
```

```c
Object* findObject(ObjectNode *objList, char *name)
```
