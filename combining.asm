; nasm -felf combining.asm
; gcc -m32 arr_with_asm.cpp combining.o -o arr2 -lstdc++
; подключение библиотеки stdc

section .text                            ; секция кода
global MatrixFill                               ; стандартная точка входа для gcc

MatrixFill:                                     ; точка входа программы
   push    ebp                           ; подготовка стека с помощью регистра BP
   mov     ebp, esp

   ; первые 4 байта - дамп стека

   mov ebx, [ebp + 8]                    ; счетчик для цикла .loop (Команды управления циклом используют регистр ECX в качестве счётчика цикла)
   mov esi, 0                            ; счетчик для перебора чисел массива

   mov eax, [ebp + 12]                   ; сохраняем нулевой элемент
   sub ebx, 1                            ; уменьшаем счетчик до n - 1

   loop:
      mov edi, [ebp + 12 + esi + 4]         ; перемещение элемента i + 1
      mov dword [ebp + 12], edi             ; на место элемента i
      add esi, 4                            ; увеличиваем счетчик (отступ) на 4 байта

      sub ebx, 1                            ; уменьшаем счетчик на единицу
      cmp ebx, 00                           ; условие для цикла
      jne  loop

      mov dword [ebp + 12], eax             ; присваиваем нулевой элемент последней ячейке массива


   pop ebp ; эпилог
;   mov     esp, ebp                      ; убрать стек
;   pop     ebp         
;   mov     eax,0                         ; выход без ошибок
   ret                 
