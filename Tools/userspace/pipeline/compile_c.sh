cd /tmp/gld_c; rm -f *.o *.err
for f in part_*.c; do b=${f%.c}; gcc -arch ppc -w -c $f -o $b.o 2> $b.err || echo FAIL $b; done
cat *.err | grep "error:" | sed 's/^[^:]*:[0-9]*: //' | sed "s/'[^']*'/X/g" | sort | uniq -c | sort -rn | head -25
ls *.o | wc -l
