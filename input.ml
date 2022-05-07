
(define fact (x) 
  (let ((n 0)(sum x))
    (while (< n x )
       (seq (set n (+ n 1))
            (set sum (+ sum n))  
       )
    )
  )

)

(define main()
   (write (fact 10))
)


