echo "Welcome in nboisde shell script to check Repository Faster.\n"
echo "Starting Process"
sleep 1
find .
norminette -R CheckForbiddenSourceHeader ./ex*/*.c
sleep 2
echo "executing the comilation"
sleep 0.1
echo "."
sleep 0.5
gcc -Wall -Werror -Wextra -c ./ex*/*.c
find .*/*.o
sleep 1
cat ./ex*/*.c
find ./ex*/*.c > tmp.c
awk '{print "#include \""$0"\""}' tmp.c >> tmp.c
cat tmp.c | grep "^#" > main.c
echo "\nint main(void)\n{\n}" >> main.c
echo "main.c for tests -------------------\n"
cat main.c
rm tmp.c
rm ./*.o
ls -la
