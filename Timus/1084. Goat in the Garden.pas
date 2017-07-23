// The solution of the problem was written by Izaron
// Date: 14:26:15   29 Apr 2015
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

var a,r:integer;  az,s,stru,b:real;
function ArcCos ( X : Real ): Real;
var
tmpArcCos : Real;
begin
if X = 0.0 then
tmpArcCos := Pi / 2.0
else
tmpArcCos := ArcTan ( Sqrt ( 1 - X * X ) / X );
if X < 0.0 then
tmpArcCos := Pi - tmpArcCos;
ArcCos := 180*tmpArcCos/pi;
end;


begin
readln(a,r);
if a/2>=r then writeln(pi*r*r:1:3) else
if sqrt(2)/2*a<=r then writeln(a*a) else
 begin
 az:=2*arccos((a/2)/r);
   s:=pi*r*r*az/360;
   b:=2*sqrt((r-a/2)*(r+a/2));
   stru:=a/4*b;
   s:=s-stru;
   s:=pi*r*r-4*s;
   writeln(s:1:3);
 end;
readln;
end.