mod_a: BEGIN
y: extern
mod_b: extern
public val
public l1

section .data
val: const 5

section .text
    input y
    load val
    add y
    store y
    jmpp mod_b
l1: stop
    .end
