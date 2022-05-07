(define add (x y)
    ( seq 
        (let (
            (a (/ (- (+ 22 20) ( * 5 (- y))) y)) # 52 / 2 = 26
            (b (- a (+ x y)))
        )
            (write b)
        )
        (write (/ (- (+ 22 20) ( * 5 (- y))) y)) # 52 / 2 = 26
        (write (- x y))
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