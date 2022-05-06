```minLisp
ML		    :=	arrays program      []                         
arrays		:=	arrays array        []
            |   ε                   []
array		:=	( array id num )    []
program		:=	program function    []
		    |	function            []                   
function	:=	( define id param_list expr ) [x] // should be good
param_list	:=	( )                 [x]
			|	( id_list )         [x]
id_list		:=	id_list id          [x] _int
		    |	id	                [x] _int
expr		:=	num                 [x] 
            |	id                  [x]
            |	id [ expr ]         [-] // todo
            |	true                [-] // potentially to be given more thought
            |	false               [-] // potentially to be given more thought
            |	( if expr expr expr )   []
            |	( while expr expr ) []
            |	( id actual_list )  [x] // should be good
            |	( write expr )      [x]
            |	( writeln expr )    [x]
            |	( read )            []
            |	( let ( assign_list ) expr ) [x]
            |	( set id expr )     [x] // check
            |	( set id [ expr ] expr ) []
            |	( + expr expr )     [x]
            |	( - expr expr)      [x]
            |	( * expr expr )     [x]
            |	( / expr expr)      []
            |	( < expr expr )     |	( > expr expr )  []
            |	( <= expr expr)     |	( >= expr expr)  []
            |	( = expr expr )     []
            |	( <> expr expr)     []
            |	( - expr )          []
            |	( and  expr expr)  	|	( &  expr expr)  []
            |	( or  expr expr )	|	( |  expr expr ) []
            |	( not expr ) 		|	( ! expr )       []
            |   ( seq expr_list )       []
actual_list	:=	actual_list expr        [x]
		    |	ε                       [x]
assign_list	:=	assign_list ( id expr ) [x]
		    |	( id expr )             [x]
expr_list   :=  expr_list expr          []
		    |	expr                    []
```