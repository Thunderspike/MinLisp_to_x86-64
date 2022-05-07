(def add (x, y)
    ( seq
        ( + x y )
    )
)
(def main() 
    ( let (
            (a (write 5))
            (b 2)
        )
        (write add(a, b))
    )
)