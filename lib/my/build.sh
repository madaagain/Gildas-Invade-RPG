#!
gcc *.c -c -I../../include/
ar rc libmy.a *.o
rm *.o