```minLisp
ML		    :=	arrays program      []                         
arrays		:=	arrays array        []
            |   ε                   [x]
array		:=	( array id num )    []
program		:=	program function    [x]
		    |	function            [x]                   
function	:=	( define id param_list expr ) [x] // should be good
param_list	:=	( )                 [x]
			|	( id_list )         [x]
id_list		:=	id_list id          [x] _int
		    |	id	                [x] _int
expr		:=	num                 [x] 
            |	id                  [x]
            |	id [ expr ]         [] // todo
            |	true                [x] // potentially to be given more thought
            |	false               [x] // potentially to be given more thought
            |	( if expr expr expr )   [x]
            |	( while expr expr ) []
            |	( id actual_list )  [x] // should be good
            |	( write expr )      [x]
            |	( writeln expr )    [x]
            |	( read )            [-] // probablygood
            |	( let ( assign_list ) expr ) [x]
            |	( set id expr )     [x] // check
            |	( set id [ expr ] expr ) []
            |	( + expr expr )     [x]
            |	( - expr expr)      [x]
            |	( * expr expr )     [x]
            |	( / expr expr)      [x]
            |	( < expr expr )     |	( > expr expr )  [x]
            |	( <= expr expr)     |	( >= expr expr)  [x]
            |	( = expr expr )     [x]
            |	( <> expr expr)     [x]
            |	( - expr )          [x]
            |	( and  expr expr)  	|	( &  expr expr)  []
            |	( or  expr expr )	|	( |  expr expr ) []
            |	( not expr ) 		|	( ! expr )       []
            |   ( seq expr_list )       [x] // just returning symbol of last expr
actual_list	:=	actual_list expr        [x] // generating parameter registers
		    |	ε                       [x] // nothing
assign_list	:=	assign_list ( id expr ) [x] // moving expr into stack spaces
		    |	( id expr )             [x] // moving expr into stack spaces
expr_list   :=  expr_list expr          [x] // nothing
		    |	expr                    [x] // nothing
```