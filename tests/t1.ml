(define add (x y)
    ( seq
        ( + x y )
    )
)
(define main() 
    ( let (
            (a (write 5))
            (b 2)
        )
        (write (add a b))
    )
)