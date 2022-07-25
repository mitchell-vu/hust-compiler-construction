# THI CUỐI KỲ 2022

## Chạy chương trình sinh mã

Install make hay Cmake, thêm PATH vào enviroment variables

Chuyển directory vào folder `final-2022`

```bash
cd final-2022
```

Chạy Make để compile project kèm libraries
Chọn file test đi kèm với parser

- Với MacOS/Linux

```bash
cd completed && make && cd ..
```

- Với Windows

```bash
cd completed && mingw32-make && cd ..
```

Chạy chương trình sinh mã

- Với MacOS/Linux

```bash
./completed/kplc ./test/final_1.kpl ./test/final_1 -dump
./completed/kplc ./test/final_2.kpl ./test/final_2 -dump
```

- Với Windows

```bash
./completed/kplc.exe ./test/final_1.kpl ./test/final_1 -dump
./completed/kplc.exe ./test/final_2.kpl ./test/final_2 -dump
```

## Chạy chương trình thông dịch kplrun

- Với MacOS/Linux

```bash
./interpreter/kplrun ./test/final_1
./interpreter/kplrun ./test/final_2
```

- Với Windows

```bash
./interpreter/kplrun.exe ./test/final_1
./interpreter/kplrun.exe ./test/final_2
```
