section .text                            ; секция кода
global MatrixFill                        ; стандартная точка входа для gcc

MatrixFill:                              ; точка входа программы
   push    ebp                           ; подготовка стека с помощью регистра BP
   mov     ebp, esp

   mov ecx, [ebp + 8]                    ; счетчик для цикла next: (Команды управления циклом используют регистр ECX в качестве счётчика цикла)
   mov esi, 0                            ; счетчик для указания на элемент массива
   mov eax, [ebp + 24]                   ; сохраняем нулевой элемент
   sub ecx, 1                            ; уменьшаем счетчик до n - 1

   next:
      mov edi, [ebp + 24 + esi + 4]      ; перемещение элемента i + 1
      mov dword [ebp + 24 + esi], edi    ; на место элемента i

      add esi, 4                         ; увеличиваем счетчик (отступ) на 4 байта

      sub ecx, 1                         ; уменьшаем счетчик на единицу
      cmp ecx, 00                        ; условие для цикла
      jne next

   mov dword [ebp + 24 + esi], eax       ; присваиваем нулевой элемент последней ячейке массива

   pop ebp
   ret                 
