# BUỔI THỰC HÀNH 3 - PARSER

## About Parser

Là một Syntax Analysizer, kiểm tra cấu trúc ngữ pháp của một chương trình. Input là array of code từ scanner gửi vào

### Structures

Về cơ bản KPL là một ngôn ngữ **LL(1) Grammar**
Xây dựng một parser topdown recursive

- Xem trước nội dung một token ở `Token lookAhead`

```c
Token *currentToken;   // Token vừa đọc
Token *lookAhead;      // Token xem trước

void scan(void) {
    Token* tmp = currentToken;
    currentToken = lookAhead;
    lookAhead = getValidToken();
    free(tmp);
}
```

- `eat()` - Duyệt ký hiệu Terminal

```c
void eat(TokenType tokenType) {
    if (lookAhead->tokenType == tokenType) {
        printToken(lookAhead);
        scan();
    }
    else missingToken(
            tokenType,
            lookAhead->lineNo,
            lookAhead->colNo
        );
}
```

- Duyệt ký hiệu Nonterminal

```c
void compileProgram(void) {
    assert("Parsing a Program ....");
    eat(KW_PROGRAM);
    eat(TK_IDENT);
    eat(SB_SEMICOLON);

    compileBlock();
    eat(SB_PERIOD);
    assert("Program parsed!");
}
```

### Functions

- Kích hoạt Parser

```c
int compile(char *fileName);
```

- Print message to the console

```c
void assert(char *msg) {
  printf("%s\n", msg);
}
```

- Print lỗi thiếu token với loại `tokenType` cụ thể

```c
void missingToken(TokenType tokenType, int lineNo, int colNo);
```

## Bài tập

### Bài 1

Dịch chương trình với

- Khai báo hằng
- Khai báo kiểu
- Khai báo biến
- **Thân hàm rỗng**

### Bài 2

Dịch chương trình với

- Khai báo hằng
- Khai báo kiểu
- Khai báo biến
- **Các lệnh**

### Bài 3

Dịch chương trình với đầy đủ sơ đồ cú pháp

## Chạy chương trình

Install make hay Cmake, thêm PATH vào enviroment variables

Chuyển directory vào folder `Bai3`
Chạy Make để compile project kèm libraries
Chọn file test đi kèm với parser

Với MacOS/Linux

```bash
cd incompleted
make
./parser ../test/<file_name>
```

Với Windows

```bash
cd incompleted
mingw32-make
./parser.exe ../test/<file_name>
```

Đối chiếu kết quả với `result.txt`
