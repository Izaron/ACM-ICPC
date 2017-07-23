// The solution of the problem was written by Izaron
// Date: 14:49:27   29 Apr 2015
// Execution time: 0.031

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

var
 mass,have:array[0..400] of string;
 mark:array[0..400] of integer;
 go,p,n,i,l,k,j:longint;
 g,ex:string;
 iska,find:boolean;
begin
 readln(n); iska:=false;
 for i:=1 to n do
  begin
   readln(g); mass[i]:=g+' ';
   if pos('Isenbaev ',mass[i])<>0 then iska:=true;
  end;
 i:=1; inc(l);have[l]:='Isenbaev ';mark[l]:=0;
 while i<=l do begin
  for j:=1 to n do
   begin
    if pos(have[i],mass[j])=0 then continue;
    while mass[j]<>'' do
     begin
      k:=pos(' ',mass[j]);
      ex:=copy(mass[j],1,k); find:=false;
      for p:=1 to l do
       if ex=have[p] then find:=true;
      if not find then
       begin
        inc(l); have[l]:=ex; mark[l]:=mark[i]+1;
       end;
      delete(mass[j],1,k);
     end; end;
    inc(i);
   end;
 for i:=1 to n do
  while mass[i]<>'' do
   begin
    k:=pos(' ',mass[i]);
    ex:=copy(mass[i],1,k); find:=false;
    for p:=1 to l do
     if ex=have[p] then find:=true;
    if not find then
     begin
      inc(l); have[l]:=ex; mark[l]:=-1;
     end;
    delete(mass[i],1,k);
   end;
 if not iska then
  begin
   have[1]:=have[l];
   mark[1]:=mark[l];
   dec(l);
  end;
 for i:=l downto 2 do
  for j:=1 to i-1 do
   if have[i]<have[j] then
    begin
     ex:=have[i];have[i]:=have[j];have[j]:=ex;
     p:=mark[i];mark[i]:=mark[j];mark[j]:=p;
    end;
 for i:=1 to l do
  if mark[i]>-1 then writeln(have[i],mark[i])
                else writeln(have[i],'undefined');
end.