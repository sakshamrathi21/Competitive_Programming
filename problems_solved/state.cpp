

 States: Partial, Full, Empty
 Object following states: Stack


 Stack {
	State *s;


	// redirect all calls to state
 }

 State {  

 }

 Partial is State
 Full is State
 Empty is State


 
 Stack *s;
   s->... // sequence of calls, redirected to state
