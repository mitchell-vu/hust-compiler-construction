# Môn Thực hành Chương trình dịch - K64

Mã môn: IT3282

Link Notion: [notion.so/compiler-construction](https://www.notion.so/Compiler-Construction-42a9142946bd4ae9a2f3cf6261a11de3)

## Cấu trúc Comipiler

| File name | Usage |
| --- | --- |
| Makefile | Project cmake file |
| scanner.c <br/> scanner.h | Đọc từng token |
| reader.h <br/> reader.c | Đọc mã nguồn |
| charcode.h <br/> charcode.c | Phân loại ký tự |
| token.h <br/> token.c | Phân loại và nhận dạng token, từ khóa |
| error.h <br/> error.c | Thông báo lỗi |
| parser.c <br/> parser.h | Duyệt các cấu trúc chương trình |
| main.c | Chương trình chính |

## KPL Grammars

_(Kid Programming Language)_
Là ngôn ngữ được tạo ra để sử dụng trong môn học này
