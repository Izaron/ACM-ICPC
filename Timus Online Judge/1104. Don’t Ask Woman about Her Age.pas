// The solution of the problem was written by Izaron
// Date: 15:45:03   1 May 2015
// Execution time: 0.062

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

var
    a,min,k:shortint;
    t,i,tot:longint;
    x:char;
  begin
    min:=0; tot:=0;
    repeat
      read(x);
      if x in ['0'..'9']
        then a:=ord(x)-48
        else if x in ['A'..'Z']
               then a:=ord(x)-55;
      tot:=tot+a;
      if a>min then min:=a;
    until eoln;
    if min=0 then begin writeln(2); exit end;
    for k:=min+1 to 36 do
       if tot mod (k-1)=0 then begin writeln(k); exit end;
    writeln('No solution.');
  end.
