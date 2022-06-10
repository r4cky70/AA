import os
import sys

argv = sys.argv

if(len(argv) < 3):
  os.system("g++ {}.cpp -std=c++17 -Wall -Wextra -Wfatal-errors \
  -Wno-sign-compare -o sla && ./sla".format(argv[1]))
elif(len(argv) >= 3 and argv[2] == 'l') :
  os.system("g++ {}.cpp -std=c++17 -Wall -Wextra -Wfatal-errors \
  -Wno-sign-compare -DLOCAL -o sla && ./sla".format(argv[1]))
elif(len(argv) >= 3 and argv[2] == 'dl'):
  os.system("g++ {}.cpp -std=c++17 -Wall -Wextra -pedantic -O2 -Wshadow \
  -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 \
  -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG \
  -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address \
  -fsanitize=undefined -fno-sanitize-recover -fstack-protector \
  -o sla && ./sla".format(argv[1]))
else:
  print("Argumento invalido.\nUse\nargv[1]="" para execucao \
  simples\nargv[2]=l para execucao simples com define \
  local\nargv[2]=dl para execucao debug com define local")