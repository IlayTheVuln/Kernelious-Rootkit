EXTERN DbgPrint :PROC

_DATA SEGMENT
aMsrsStatusStar db 'syscall number is: %d',0Ah,0
_DATA ENDS

_TEXT SEGMENT


public datap
datap proc
push rbp
mov rbp, rsp

lea rcx, aMsrsStatusStar
call DbgPrint

pop rbp
ret
datap endp

_TEXT ENDS

END

