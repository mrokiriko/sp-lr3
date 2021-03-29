FROM ubuntu
RUN apt-get update && apt-get upgrade -y
RUN apt install  build-essential -y
RUN apt install nasm -y
RUN apt-get install gcc-multilib -y
COPY combining.asm .
COPY arr_with_asm.c .
CMD nasm -felf combining.asm && gcc -m32 arr_with_asm.c combining.o -o arr2 && ./arr2
