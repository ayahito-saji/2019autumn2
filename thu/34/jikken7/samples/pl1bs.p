program test;
var n;
procedure addone(n);
begin
  n := n + 1;
end;
begin
  n := 2;
  addone(n);
  write(n)
end.
