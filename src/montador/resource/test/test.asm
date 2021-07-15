mod: BEGIN
;bar: extern
public foo
public fim

section .data
foo: space
labl_2: const 5

section .text
    add labl_2
fim:
    .end
