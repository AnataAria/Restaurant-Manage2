gcc -Wno-format -o test0 main.c -Wl,--export-all-symbols -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0`